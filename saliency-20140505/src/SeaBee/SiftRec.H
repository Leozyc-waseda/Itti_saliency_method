/*!@file SeaBee/SiftRec.H */


// //////////////////////////////////////////////////////////////////// //
// The iLab Neuromorphic Vision C++ Toolkit - Copyright (C) 2000-2005   //
// by the University of Southern California (USC) and the iLab at USC.  //
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
// Primary maintainer for this file: Lior Elazary
// $HeadURL: svn://isvn.usc.edu/software/invt/trunk/saliency/src/SeaBee/SiftRec.H $
// $Id: SiftRec.H 10794 2009-02-08 06:21:09Z itti $
//

#ifndef SEABEE_SIFTREC_H
#define SEABEE_SIFTREC_H

#include "Component/ModelManager.H"
#include "Component/ModelComponent.H"
#include "Component/ModelOptionDef.H"
#include "Image/Image.H"
#include "SIFT/ScaleSpace.H"
#include "SIFT/VisualObject.H"
#include "SIFT/Keypoint.H"
#include "SIFT/VisualObjectDB.H"

class SiftRec : public ModelComponent
{
public:
  SiftRec(OptionManager& mgr,
        const std::string& descrName = "SiftRec",
        const std::string& tagName = "SiftRec");

  ~SiftRec();

  void getObject(const Image<PixRGB<byte> > &img);

  //SIFT methods
  //Init the database
  bool initVDB();
  //Get the best label by doing some temporal integration.
  //TODO: Add the score to this matching, and determin the labels if the score is close
  std::string getBestLabel(const size_t mincount);

  //Find a match
  std::string matchObject(Image<PixRGB<byte> > &ima,
      float &score,
      Rectangle& rect);

  //Train an object
  void trainObject(const Image<PixRGB<byte> > &img, const std::string& objectName);




private:
  OModelParam<std::string> itsVDBFile; //the visual object database filename
  OModelParam<bool> itsUseColor; //use color in sift
  VisualObjectDB itsVDB; //the visual object database
  uint itsMaxLabelHistory; //the history of labels that we keep
  std::deque<std::string> itsRecentLabels; //the recent labels that we found so far
  bool itsTrainingMode; //are we in training mode


};

// ######################################################################
/* So things look consistent in everyone's emacs... */
/* Local Variables: */
/* mode: c++ */
/* indent-tabs-mode: nil */
/* End: */

#endif
