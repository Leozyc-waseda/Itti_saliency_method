/*!@file Script/ModelScript.H */

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
// Primary maintainer for this file: Rob Peters <rjpeters at usc dot edu>
// $HeadURL: svn://isvn.usc.edu/software/invt/trunk/saliency/src/Script/ModelScript.H $
// $Id: ModelScript.H 11876 2009-10-22 15:53:06Z icore $
//

#ifndef SCRIPT_MODELSCRIPT_H_DEFINED
#define SCRIPT_MODELSCRIPT_H_DEFINED

#include "nub/objfactory.h"

struct Tcl_Interp;
class OptionManager;

extern "C" int Modelcomponent_Init(Tcl_Interp* interp);
extern "C" int Modelmanager_Init(Tcl_Interp* interp);
extern "C" int Simmodule_Init(Tcl_Interp* interp);
extern "C" int Simeventqueue_Init(Tcl_Interp* interp);

OptionManager& getManager();

template <class T>
struct ComponentCreator
{
  static nub::soft_ref<T> make()
  {
    return nub::soft_ref<T>(new T(getManager()));
  }
};

template <class T>
void registerComponentCreator()
{
  nub::obj_factory::instance().register_creator
    (&ComponentCreator<T>::make);
}

// ######################################################################
/* So things look consistent in everyone's emacs... */
/* Local Variables: */
/* indent-tabs-mode: nil */
/* End: */

#endif // SCRIPT_MODELSCRIPT_H_DEFINED
