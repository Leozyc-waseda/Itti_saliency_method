/*!@file CINNIC/contourDefine.H CINNIC classes */

#define ImageSizeX 100 // <--- FIX HERE
#define ImageSizeY 100 // <--- FIX HERE

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
// Primary maintainer for this file: T. Nathan Mundhenk <mundhenk@usc.edu>
// $HeadURL: svn://isvn.usc.edu/software/invt/trunk/saliency/src/CINNIC/contourDefine.H $
// $Id: contourDefine.H 5329 2005-08-16 05:10:30Z mundhenk $
//

#define XSize       12  //this is the size of the neurons field + 1
                        //idealy this should
                        // be equal to y and
#define YSize       12  //an even number (n+1) so the math works cleanly
//#define AnglesUsed     12  // Number of angles used in this filter
//#define CINNIC_ANGLES  0,15,30,45,60,75,90,105,120,135,150,165
#define AnglesUsed    4
#define CINNIC_ANGLES 0,45,90,135

#define AngleCenter 90  // this is the center angle to be used in compuations
#define pi 3.14159

//this matrix is used to generate a random angle oriented image
#define dumbImageSize 100
#define CutOffLevel   .9
#define Scales        3
#define Iterations    3


// ######################################################################
/* So things look consistent in everyone's emacs... */
/* Local Variables: */
/* indent-tabs-mode: nil */
/* End: */
