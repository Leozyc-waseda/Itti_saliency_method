/*!@file MBARI/BitObjectDrawModes.C definition of the different modes of
  drawing a BitObject into a frame */

// //////////////////////////////////////////////////////////////////// //
// The iLab Neuromorphic Vision C++ Toolkit - Copyright (C) 2000-2003   //
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
// Primary maintainer for this file: Dirk Walther <walther@caltech.edu>
// $HeadURL: svn://isvn.usc.edu/software/invt/trunk/saliency/src/MBARI/BitObjectDrawModes.C $
// $Id: BitObjectDrawModes.C 5755 2005-10-19 20:57:27Z rjpeters $
//

#include "MBARI/BitObjectDrawModes.H"

#include "Util/StringConversions.H"
#include "Util/log.H"

// ######################################################################
// converters for BitObjectDrawMode
// ######################################################################

std::string convertToString(const BitObjectDrawMode val)
{ return bitObjectDrawModeName(val); }

void convertFromString(const std::string& str, BitObjectDrawMode& val)
{
  // CAUTION: assumes types are numbered and ordered!
  for (int i = 0; i < NBBITOBJECTDRAWMODES; i ++)
    if (str.compare(bitObjectDrawModeName(BitObjectDrawMode(i))) == 0)
      { val = BitObjectDrawMode(i); return; }

  conversion_error::raise<BitObjectDrawMode>(str);
}

// ######################################################################
/* So things look consistent in everyone's emacs... */
/* Local Variables: */
/* indent-tabs-mode: nil */
/* End: */
