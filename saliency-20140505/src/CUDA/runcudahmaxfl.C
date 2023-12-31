/*!@file HMAX/test-hmax5.C Test Hmax class and compare to original code */

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
// $HeadURL: svn://isvn.usc.edu/software/invt/trunk/saliency/src/CUDA/runcudahmaxfl.C $
// $Id: runcudahmaxfl.C 12962 2010-03-06 02:13:53Z irock $
//

#include "Component/ModelManager.H"
#include "GUI/XWindow.H"
#include "CUDA/CudaHmaxFL.H"
#include "CUDA/CudaHmax.H"
#include "Image/Image.H"
#include "Image/ColorOps.H"
#include "Image/CutPaste.H"
#include "Image/Rectangle.H"
#include "Image/MathOps.H"
#include "Image/MatrixOps.H"
#include "Image/Transforms.H"
#include "Image/Convolutions.H"
#include "Learn/svm.h"
#include "Media/FrameSeries.H"
#include "nub/ref.h"
#include "Raster/GenericFrame.H"
#include "Raster/Raster.H"
#include "Util/Types.H"
#include "Util/log.H"

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <unistd.h>
#include <cstdlib>


// number of orientations to use in HmaxFL
#define NORI 4
#define NUM_PATCHES_PER_SIZE 250

int main(const int argc, const char **argv)
{

  MYLOGVERB = LOG_INFO;

  ModelManager *mgr = new ModelManager("Test Hmax with Feature Learning");


  mgr->exportOptions(MC_RECURSE);

  // required arguments
  // <c1patchesDir> <dir|list> <id> <outputfile>
  //
  // <id> is the given id for the given set of images
  // --in only needs to happen if we are loading the patches

  if (mgr->parseCommandLine(
                            (const int)argc, (const char**)argv, "<cudadev> <c1patchesDir> <dir|list:images> <id> <outputfile>", 5, 5) == false)
    return 1;

  std::string loadImagesOption = mgr->getExtraArg(1);
  std::string c1PatchesBaseDir;
  std::string images,idArg,devArg;
  std::string c2FileName;

  std::string trainPosName; // Directory where positive images are

  int id;

  devArg = mgr->getExtraArg(0);
  c1PatchesBaseDir = mgr->getExtraArg(1);
  images = mgr->getExtraArg(2);
  idArg = mgr->getExtraArg(3);
  c2FileName = mgr->getExtraArg(4);

  MemoryPolicy mp = GLOBAL_DEVICE_MEMORY;
  int dev = strtol(devArg.c_str(),NULL,0);
  std::string::size_type dirArg=images.find("dir:",0);
  std::string::size_type listArg=images.find("list:",0);
  if((dirArg == std::string::npos &&
      listArg == std::string::npos) ||
     (dirArg != 0 && listArg != 0)){
    LFATAL("images argument is in one of the following formats -  dir:<DIRNAME>  or  list:<LISTOFIMAGEPATHSFILE>");
    return EXIT_FAILURE;
  }
  if(dirArg == 0)
    images = images.substr(4);
  else
    images = images.substr(5);

  id = strtol(idArg.c_str(),NULL,0);


  // get an HmaxFL object:
  std::vector<int> scss(9);
  scss[0] = 1; scss[1] = 3; scss[2] = 5; scss[3] = 7; scss[4] = 9;
  scss[5] = 11; scss[6] = 13; scss[7] = 15; scss[8] = 17;
  std::vector<int> spss(8);
  spss[0] = 8; spss[1] = 10; spss[2] = 12; spss[3] = 14;
  spss[4] = 16; spss[5] = 18; spss[6] = 20; spss[7] = 22;
  // std::vector<int> scss(4);
  // scss[0] = 3; scss[1] = 7; scss[2] = 11; scss[3] = 15;
  // std::vector<int> spss(4);
  // spss[0] = 10; spss[1] = 14; spss[2] = 18; spss[3] = 22;

  CudaHmaxFL hmax(mp,dev,NORI, spss, scss);




  //
  hmax.readInC1Patches(c1PatchesBaseDir);
  // Now we run if needed
  mgr->start();

  std::vector<std::string> imageNames;
  if(dirArg == 0)
    imageNames = hmax.readDir(images);
  else
    imageNames = hmax.readList(images);

  std::ofstream c2File;
  c2File.open(c2FileName.c_str(),std::ios::out);

  std::vector<int> patchSizes = hmax.getC1PatchSizes();
  float **c2Res = new float*[patchSizes.size()];
  for(unsigned int i=0;i<patchSizes.size();i++) {
    c2Res[i] = new float[NUM_PATCHES_PER_SIZE];
  }

  for(unsigned int imgInd=0;imgInd<imageNames.size();imgInd++){
    Image<float> inputf = Raster::ReadGrayNTSC(imageNames[imgInd]);

    // Output the c2 responses per patch into a libsvm
    // (or equivalently osusvm) style format

    //hmax.printCorners("inputf",inputf,1);
    hmax.getC2(CudaImage<float>(inputf,mp,dev),c2Res);
    std::cout <<"C2 Processing Complete: " << imgInd << std::endl;
    if (c2File.is_open()) {
      c2File << id << " ";
      for(unsigned int i=0;i<patchSizes.size();i++) {
        for(int j=0;j<NUM_PATCHES_PER_SIZE;j++) {
          c2File << std::setiosflags(std::ios::fixed) << std::setprecision(4) <<
            (i*NUM_PATCHES_PER_SIZE+j+1) << ":" << c2Res[i][j] << " ";
        }
      }
      c2File << std::endl;
    }
    std::cout <<"C2 Output Written: " << imgInd << std::endl;
  }

  for(unsigned int i=0;i<patchSizes.size();i++) {
    delete[] c2Res[i];
  }
  delete [] c2Res;

  c2File.close();
  return 0;
}


// ######################################################################
/* So things look consistent in everyone's emacs... */
/* Local Variables: */
/* indent-tabs-mode: nil */
/* End: */
