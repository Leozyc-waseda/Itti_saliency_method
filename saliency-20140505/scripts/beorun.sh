#!/bin/sh

##########################################################################
## The iLab Neuromorphic Vision C++ Toolkit - Copyright (C) 2000-2002   ##
## by the University of Southern California (USC) and the iLab at USC.  ##
## See http://iLab.usc.edu for information about this project.          ##
##########################################################################
## Major portions of the iLab Neuromorphic Vision Toolkit are protected ##
## under the U.S. patent ``Computation of Intrinsic Perceptual Saliency ##
## in Visual Environments, and Applications'' by Christof Koch and      ##
## Laurent Itti, California Institute of Technology, 2001 (patent       ##
## pending; application number 09/912,225 filed July 23, 2001; see      ##
## http://pair.uspto.gov/cgi-bin/final/home.pl for current status).     ##
##########################################################################
## This file is part of the iLab Neuromorphic Vision C++ Toolkit.       ##
##                                                                      ##
## The iLab Neuromorphic Vision C++ Toolkit is free software; you can   ##
## redistribute it and/or modify it under the terms of the GNU General  ##
## Public License as published by the Free Software Foundation; either  ##
## version 2 of the License, or (at your option) any later version.     ##
##                                                                      ##
## The iLab Neuromorphic Vision C++ Toolkit is distributed in the hope  ##
## that it will be useful, but WITHOUT ANY WARRANTY; without even the   ##
## implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR      ##
## PURPOSE.  See the GNU General Public License for more details.       ##
##                                                                      ##
## You should have received a copy of the GNU General Public License    ##
## along with the iLab Neuromorphic Vision C++ Toolkit; if not, write   ##
## to the Free Software Foundation, Inc., 59 Temple Place, Suite 330,   ##
## Boston, MA 02111-1307 USA.                                           ##
##########################################################################
##
## Primary maintainer for this file: Laurent Itti <itti@usc.edu>
## $Id: beoroot.sh 11336 2008-10-01 22:14:04Z itti $
##

# USAGE: beorun.sh <command>
# Will run "command" on all Beowulf nodes specified in /etc/beonodes.
#
# For this to work, you will need to have a passwordless access
# to your nodes via ssh. To enable that, just run:
#
# ssh-keygen -t dsa
# ssh-copy-id -i ~/.ssh/id_dsa.pub node01
# ... and repeat for all your nodes
#
# Then, ssh node01 should log you in without requiring a password.


# find a list of nodes:
if [ -s "${HOME}/.beonodes" ]; then nodes="${HOME}/.beonodes"
elif [ -s '/etc/beonodes' ]; then nodes='/etc/beonodes'
else echo 'Cannot find list of nodes -- ABORT'; exit 1; fi

for n in `/bin/grep -v "#" $nodes`; do
    echo -n "[$n] "
    ssh $n "$*"
done
