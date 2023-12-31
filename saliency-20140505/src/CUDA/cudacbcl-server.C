/*!@file CUDA/cudacbcl-server.C Test TCP Label Server accepts patches and returns labels */

// //////////////////////////////////////////////////////////////////// //
// The iLab Neuromorphic Vision C++ Toolkit - Copyright (C) 2001 by the //
// University of Southern California (USC) and the iLab at USC.         //
// See http://iLab.usc.edu for information about this project.          //
// //////////////////////////////////////////////////////////////////// //
// Major portions of the iLab Neuromorphic Vision Toolkit are protected //
// under the U.S. patent ``Computation of Intrinsic Perceptual Saliency //
// in Visual Environments, and Applications'' by Christof Koch and      //
// Laurent Itti, California Institute of Technology, 2001 (patent       //
// pending; application number 09/912,225 filed July 23, 2001; see      //
// http://pair.uspto.gov/cgi-bin/final/home.pl for current status).     //
// //////////////////////////////////////////////////////////////////// //
// This file is part of the iLab Neuromorphic Vision C++ Toolkit.       //
//                                                                      //
// The iLab Neuromorphic Vision C++ Toolkit is free software; you can   //
// redistribute it and/or modify it under the terms of the GNU General  //
// Public License as published by the Free Software Foundation; either  //
// version 2 of the License, or (at your option) any later version.     //
//                                                                      //
// The iLab Neuromorphic Vision C++ Toolkit is distributed in the hope  //
// that it will be useful, but WITHOUT ANY WARRANTY; without even the   //
// implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR      //
// PURPOSE.  See the GNU General Public License for more details.       //
//                                                                      //
// You should have received a copy of the GNU General Public License    //
// along with the iLab Neuromorphic Vision C++ Toolkit; if not, write   //
// to the Free Software Foundation, Inc., 59 Temple Place, Suite 330,   //
// Boston, MA 02111-1307 USA.                                           //
// //////////////////////////////////////////////////////////////////// //
//
// Primary maintainer for this file: Dan Parks <danielfp@usc.edu>
// $HeadURL: svn://isvn.usc.edu/software/invt/trunk/saliency/src/CUDA/cudacbcl-server.C $
// $Id: cudacbcl-server.C 14154 2010-10-21 05:07:25Z dparks $
//

#include "Component/ModelManager.H"
#include "Learn/Bayes.H"
#include "GUI/DebugWin.H"
#include "NeovisionII/nv2_common.h"
#include "NeovisionII/nv2_label_server.h"

#include "GUI/XWindow.H"
#include "CUDA/CudaHmaxCBCL.H"
#include "Image/Image.H"
#include "Image/ImageSet.H"
#include "Image/ColorOps.H"
#include "Image/ShapeOps.H"
#include "Image/CutPaste.H"
#include "Image/FilterOps.H"
#include "Image/Rectangle.H"
#include "Image/MathOps.H"
#include "Image/DrawOps.H"
#include "Image/MatrixOps.H"
#include "Image/Transforms.H"
#include "Image/Convolutions.H"
#include "Learn/SVMClassifier.H"
#include "Media/FrameSeries.H"
#include "nub/ref.h"
#include "Raster/GenericFrame.H"
#include "Raster/Raster.H"
#include "Util/Types.H"
#include "Util/log.H"

#include <signal.h>

#include "rutz/fstring.h"
#include "rutz/time.h"
#include "rutz/timeformat.h"

#include <fstream>
#include <map>
#include <vector>
#include <utility>
#include <iostream>
#include <iomanip>
#include <string>
#include <unistd.h>
#include <cstdlib>


const bool USECOLOR = false;

bool terminate = false;

void terminateProc(int s)
{
  terminate = true;
}

std::string getBestLabel(const std::deque<std::string>& labels,
                         const size_t mincount)
{
  if (labels.size() == 0)
    return std::string();

  std::map<std::string, size_t> counts;

  size_t bestcount = 0;
  size_t bestpos = 0;

  for (size_t i = 0; i < labels.size(); ++i)
    {
      const size_t c = ++(counts[labels[i]]);

      if (c >= bestcount)
        {
          bestcount = c;
          bestpos = i;
        }
    }

  if (bestcount >= mincount)
    return labels[bestpos];

  return std::string();
}

namespace
{
  void fillRegion(Image<PixRGB<byte> >& img, PixRGB<byte> col,
                  const int x0, const int x1,
                  const int y0, const int y1)
  {
    for (int x = x0; x < x1; ++x)
      for (int y = y0; y < y1; ++y)
        img.setVal(x, y, col);
  }

  Image<PixRGB<byte> > makeColorbars(const int w, const int h)
  {
    Image<PixRGB<byte> > result = Image<PixRGB<byte> >(w, h, ZEROS);

    const PixRGB<byte> cols[] =
      {
        PixRGB<byte>(255, 255, 255), // white
        PixRGB<byte>(255, 255, 0),   // yellow
        PixRGB<byte>(0,   255, 255), // cyan
        PixRGB<byte>(0,   255, 0),   // green
        PixRGB<byte>(255, 0,   255), // magenta
        PixRGB<byte>(255, 0,   0),   // red
        PixRGB<byte>(0,   0,   255)  // blue
      };

    int x1 = 0;
    for (int i = 0; i < 7; ++i)
      {
        const int x0 = x1+1;
        x1 = int(double(w)*(i+1)/7.0 + 0.5);
        fillRegion(result, cols[i],
                   x0, x1,
                   0, int(h*2.0/3.0));
      }

    x1 = 0;
    for (int i = 0; i < 16; ++i)
      {
        const int x0 = x1;
        x1 = int(double(w)*(i+1)/16.0 + 0.5);
        const int gray = int(255.0*i/15.0 + 0.5);
        fillRegion(result, PixRGB<byte>(gray, gray, gray),
                   x0, x1,
                   int(h*2.0/3.0)+1, int(h*5.0/6.0));
      }

    fillRegion(result, PixRGB<byte>(255, 0, 0),
               0, w,
               int(h*5.0/6.0)+1, h);

    writeText(result, Point2D<int>(1, int(h*5.0/6.0)+2),
              "iLab Neuromorphic Vision",
              PixRGB<byte>(0, 0, 0), PixRGB<byte>(255, 0, 0),
              SimpleFont::FIXED(10));

    return result;
  }

  Image<PixRGB<byte> > addLabels(const Image<PixRGB<byte> >& templ,
                                 const int fnum)
  {
    Image<PixRGB<byte> > result = templ;

    std::string fnumstr = sformat("%06d", fnum);
    writeText(result, Point2D<int>(1, 1),
              fnumstr.c_str(),
              PixRGB<byte>(0, 0, 0), PixRGB<byte>(255, 255, 255),
              SimpleFont::FIXED(10));

    rutz::time t = rutz::time::wall_clock_now();

    writeText(result, Point2D<int>(1, result.getHeight() - 14),
              rutz::format_time(t).c_str(),
              PixRGB<byte>(32, 32, 32), PixRGB<byte>(255, 0, 0),
              SimpleFont::FIXED(6));

    return result;
  }

  int maxKey(std::map<int, std::string> m)
  {
    map<int, std::string>::iterator cur,end;
    cur = m.begin(); end = m.end();
    int mKey=-1;
    while(cur!=end)
      {
        if(cur->first > mKey)
          mKey = cur->first;
        cur++;
      }
    return mKey;
  }

  std::map<int, std::string> loadLabels(std::string labelFile)
  {
    std::map<int, std::string> labels;
    FILE *fp = fopen(labelFile.c_str(),"r");
    int ret;
    if(fp==NULL) return labels;
    while(1)
      {
        int id; char clabel[80];
        ret = fscanf(fp,"%d ",&id);
        if(ret != 1)
        {
          fprintf(stderr,"fscanf failed with %d\n",ret);
          break;
        }
        ret = fscanf(fp,"%80s",clabel);
        if(ret != 1)
          {
            fprintf(stderr,"fscanf failed with %d\n",ret);
            break;
          }
        printf("loaded label %d %s\n",id,clabel);
        std::string label = std::string(clabel);
        labels.insert(std::pair<int, std::string>(id,label));
      }
    fclose(fp);
    return labels;
  }

  void writeLabels(std::string labelFile, std::map<int, std::string> labels)
  {
    FILE *fp = fopen(labelFile.c_str(),"w");
    if(fp==NULL) return;
    map<int, std::string>::iterator cur,end;
    cur = labels.begin(); end = labels.end();
    while(cur!=end)
      {
        fprintf(fp,"%d %80s\n",cur->first, (cur->second).c_str());
        cur++;
      }
    fclose(fp);
  }

  int findLabel(std::string label, std::map<int, std::string> labels)
  {
    map<int, std::string>::iterator cur,end;
    cur = labels.begin(); end = labels.end();
    while(cur!=end)
      {
        if(cur->second.compare(label)==0)
          return cur->first;
        cur++;
      }
    return -1;
  }


  int addLabel(std::string label, std::map<int, std::string> &labels)
  {
    int id = maxKey(labels)+1;
    labels.insert(std::pair<int, std::string>(id,label));
    return id;
  }

  bool idExists(int id, std::map<int, std::string> &labels)
  {
    if(labels.find(id) == labels.end())
      return false;
    else
      return true;
  }

}


int main(const int argc, const char **argv)
{

  MYLOGVERB = LOG_INFO;

  ModelManager *mgr = new ModelManager("Cuda Hmax CBCL Model Server");


  mgr->exportOptions(MC_RECURSE);


  if (mgr->parseCommandLine(
                            (const int)argc, (const char**)argv, "<cudadev> <labelFile> <c0patches> <c1patches> <featuresFile> <localport> <server_ip> <serverport> <svmModelFile> <svmRangeFile> ", 8, 10) == false)
    return 1;

  std::string devArg, serverIP,serverPortStr,localPortStr;
  std::string c0Patches;
  std::string c1Patches;
  std::string svmModelFileName, svmRangeFileName;
  std::string c2FileName;
  std::string labelFileName, featuresFileName;
  std::string trainPosName; // Directory where positive images are

  // Load the SVM Classifier Model and Range in
  SVMClassifier svm;

  // Whether we are in training mode
  bool train = false;


  // Now we run
  mgr->start();

  // catch signals and redirect them to terminate for clean exit:
  signal(SIGHUP, terminateProc); signal(SIGINT, terminateProc);
  signal(SIGQUIT, terminateProc); signal(SIGTERM, terminateProc);
  signal(SIGALRM, terminateProc);


  devArg = mgr->getExtraArg(0);
  labelFileName = mgr->getExtraArg(1);
  c0Patches = mgr->getExtraArg(2);
  c1Patches = mgr->getExtraArg(3);
  featuresFileName = mgr->getExtraArg(4);
  localPortStr = mgr->getExtraArg(5);
  serverIP = mgr->getExtraArg(6);
  serverPortStr = mgr->getExtraArg(7);
  // If we are given the SVM info, load it in
  if(mgr->numExtraArgs() > 8)
  {
    if(mgr->numExtraArgs() == 9)
      {
        LFATAL("USAGE: prog <cudadev> <labelFile> <c0patches> <c1patches> <featuresFile> <localport> <server_ip> <serverport> <svmModelFile> <svmRangeFile>\n");
      }
    svmModelFileName = mgr->getExtraArg(8);
    svmRangeFileName = mgr->getExtraArg(9);
    svm.readModel(svmModelFileName);
    svm.readRange(svmRangeFileName);
  }
  else
  {
    // With no SVM data, we should be in training mode
    train = true;
  }
  std::map<int,std::string> labels = loadLabels(labelFileName);

  int dev = strtol(devArg.c_str(),NULL,0);
  CudaDevices::setCurrentDevice(dev);

  CudaHmaxCBCL hmax(c0Patches,c1Patches);

  XWinManaged xwin(Dims(256,256),
                   -1, -1, "ILab Robot Head Demo");

  int serverPort = strtol(serverPortStr.c_str(),NULL,0);
  int localPort = strtol(localPortStr.c_str(),NULL,0);
  struct nv2_label_server* labelServer =
    nv2_label_server_create(localPort,
                            serverIP.c_str(),
                            serverPort);

  nv2_label_server_set_verbosity(labelServer,1); //allow warnings


  const size_t max_label_history = 1;
  std::deque<std::string> recent_labels;

  Image<PixRGB<byte> > colorbars = makeColorbars(256, 256);
  bool clearFile=true;

  while(!terminate)
    {
      Point2D<int> clickLoc = xwin.getLastMouseClick();
      if (clickLoc.isValid())
        train = !train;

      struct nv2_image_patch p;
      const enum nv2_image_patch_result res =
        nv2_label_server_get_current_patch(labelServer, &p);

      std::string objName;
      if (res == NV2_IMAGE_PATCH_END)
        {
          LINFO("ok, quitting");
          break;
        }
      else if (res == NV2_IMAGE_PATCH_NONE)
        {
          usleep(10000);
          continue;
        }
      else if (res == NV2_IMAGE_PATCH_VALID)
        {
          if (p.type != NV2_PIXEL_TYPE_RGB24)
            {
              LINFO("got a non-rgb24 patch; ignoring %i", p.type);
              continue;
            }

          if (p.width * p.height == 1)
            {
              xwin.drawImage(addLabels(colorbars, p.id));
              continue;
            }

          Image<PixRGB<byte> > img(p.width, p.height, NO_INIT);
          // Get the test image from the socket
          memcpy(img.getArrayPtr(), p.data, p.width*p.height*3);

          Image<PixRGB<byte> > inputImg = rescale(img, 256, 256);

          xwin.drawImage(inputImg);

          Image<float> inputf = luminanceNTSC(inputImg);

          // Get the C2 Layer Response
          hmax.getC2(inputf.getArrayPtr(),inputf.getWidth(),inputf.getHeight());
          if(!train)
            {
              // Output the c2 responses into a libsvm
              double prob;
              float *feat = hmax.getC2Features();
              int numFeat = hmax.numC2Features();
              double pred = svm.predict(feat,numFeat,&prob);
              printf("Prediction is %f\n",pred);
              int predId = (int) pred;
              bool knowObject = idExists(predId,labels);
              if(knowObject)
              {
                printf("Known object %d, prob %f\n",predId,prob);
                objName = labels[predId];
              }
              else
              {
                printf("Unknown object %d, prob %f\n",predId,prob);
                char tmp[200];
                sprintf(tmp,"Unknown-%d",predId);
                objName = std::string(tmp);
              }
              recent_labels.push_back(objName);
              while (recent_labels.size() > max_label_history)
                recent_labels.pop_front();

              struct nv2_patch_label l;
              l.protocol_version = NV2_LABEL_PROTOCOL_VERSION;
              l.patch_id = p.id;
              l.confidence = (int)(prob*NV2_MAX_LABEL_CONFIDENCE);
              snprintf(l.source, sizeof(l.source), "%s",
                       "HmaxFL");
              snprintf(l.name, sizeof(l.name), "%s",
                       objName.c_str());
              snprintf(l.extra_info, sizeof(l.extra_info),
                       "%ux%u #%u",
                       (unsigned int) p.width,
                       (unsigned int) p.height,
                       (unsigned int) p.id);

              nv2_label_server_send_label(labelServer, &l);
              LINFO("sent label '%s (%s)'\n", l.name, l.extra_info);
            }
          // Determine what the object is
          else
            {
              printf("Enter a label for this object:\n");
              std::getline(std::cin, objName);
              printf("You typed '%s'\n", objName.c_str());

              if (objName == "exit")
                break;
              else if (objName != "")
                {
                  int newId = findLabel(objName,labels);
                  if(newId == -1)
                    {
                      newId = addLabel(objName,labels);
                      printf("No existing label found, adding [%s]\n",objName.c_str());
                    }
                  else
                    {
                      printf("Found existing label\n");
                    }
                  hmax.writeOutFeatures(featuresFileName,newId,clearFile);
                  clearFile=false;
                }
            }

          nv2_image_patch_destroy(&p);
        }
    }

  writeLabels(labelFileName,labels);

  if (terminate)
    LINFO("Ending application because a signal was caught");

  //nv2_label_server_destroy(labelServer);
  LINFO("Got Here");

  return 0;
}




// ######################################################################
/* So things look consistent in everyone's emacs... */
/* Local Variables: */
/* indent-tabs-mode: nil */
/* End: */
