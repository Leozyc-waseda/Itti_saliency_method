/*!@file TestSuite/ObjDetBrain The brain struct */

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
// Primary maintainer for this file: Lior Elazary
// $HeadURL: svn://isvn.usc.edu/software/invt/trunk/saliency/src/TestSuite/ObjDetBrain.h $
// $Id: ObjDetBrain.h 12962 2010-03-06 02:13:53Z irock $
//

#ifndef OBJDETBRAIN_H
#define OBJDETBRAIN_H

struct ObjectData
{
  std::string name;
  float confidence;
};

struct DetLocation
{
  int i;
  int j;
  float val;

  int width;
  int height;

  DetLocation(int _i, int _j, float _val, int _w = -1, int _h = -1) :
    i(_i),
    j(_j),
    val(_val),
    width(_w),
    height(_h)
  {}

};


class ObjDetBrain
{
  public:
    virtual ~ObjDetBrain() {}

    virtual void preTraining() = 0;
    virtual void onTraining(Image<PixRGB<byte> > &img, ObjectData& objData) = 0;
    virtual void postTraining() = 0;

    virtual void preDetection() = 0;
    virtual std::vector<DetLocation> onDetection(Image<PixRGB<byte> > &img) = 0;
    virtual void postDetection() = 0;
};

typedef ObjDetBrain* CreateObjDetBrain(const int arc, const char** argv);
typedef void DestoryObjDetBrain(ObjDetBrain* brain);

#endif
