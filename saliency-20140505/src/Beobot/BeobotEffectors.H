/*!@file Beobot/BeobotEffectors.H controls the effectors of the Beobots (e.g., motors) */

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
// Primary maintainer for this file: Laurent Itti <itti@usc.edu>
// $HeadURL: svn://isvn.usc.edu/software/invt/trunk/saliency/src/Beobot/BeobotEffectors.H $
// $Id: BeobotEffectors.H 6795 2006-06-29 20:45:32Z rjpeters $
//

#ifndef BEOBOTEFFECTORS_H_DEFINED
#define BEOBOTEFFECTORS_H_DEFINED

#include "Beobot/BeobotAction.H"
#include "Component/ModelComponent.H"
#include "Devices/BeoChip.H"
#include "Beobot/BeobotConfig.H"

//! This class contains all the effectors of a Beobot
/*! i.e. servos (speed, turn and gear) and LCD display */
class BeobotEffectors : public ModelComponent
{
public:
  //! constructor
  BeobotEffectors(OptionManager& mgr,
                  const std::string& descrName = "Beobot Effectors",
                  const std::string& tagName = "BeobotEffectors");

  //! destructor
  ~BeobotEffectors();

  //! execute a given action
  void performAction(BeobotAction& action);

protected:
  //! our BeoChip controller for motor control and lcd
  nub::soft_ref<BeoChip> myBeoChip;

  //! Beobot config file
  BeobotConfig bbc;

private:

  void center();
  void turn(const float angle);

  void speed(const float sp);
  void stop();

  void changegear(const int gear);

  void display(const char* message);
  void cleardisplay();

};

#endif

// ######################################################################
/* So things look consistent in everyone's emacs... */
/* Local Variables: */
/* indent-tabs-mode: nil */
/* End: */
