%/*!@file Robots/matlab/localization/drawEllipse.m  */
%
%
%// //////////////////////////////////////////////////////////////////// //
%// The iLab Neuromorphic Vision C++ Toolkit - Copyright (C) 2001 by the //
%// University of Southern California (USC) and the iLab at USC.         //
%// See http://iLab.usc.edu for information about this project.          //
%// //////////////////////////////////////////////////////////////////// //
%// Major portions of the iLab Neuromorphic Vision Toolkit are protected //
%// under the U.S. patent ``Computation of Intrinsic Perceptual Saliency //
%// in Visual Environments, and Applications'' by Christof Koch and      //
%// Laurent Itti, California Institute of Technology, 2001 (patent       //
%// pending; application number 09/912,225 filed July 23, 2001; see      //
%// http://pair.uspto.gov/cgi-bin/final/home.pl for current status).     //
%// //////////////////////////////////////////////////////////////////// //
%// This file is part of the iLab Neuromorphic Vision C++ Toolkit.       //
%//                                                                      //
%// The iLab Neuromorphic Vision C++ Toolkit is free software; you can   //
%// redistribute it and/or modify it under the terms of the GNU General  //
%// Public License as published by the Free Software Foundation; either  //
%// version 2 of the License, or (at your option) any later version.     //
%//                                                                      //
%// The iLab Neuromorphic Vision C++ Toolkit is distributed in the hope  //
%// that it will be useful, but WITHOUT ANY WARRANTY; without even the   //
%// implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR      //
%// PURPOSE.  See the GNU General Public License for more details.       //
%//                                                                      //
%// You should have received a copy of the GNU General Public License    //
%// along with the iLab Neuromorphic Vision C++ Toolkit; if not, write   //
%// to the Free Software Foundation, Inc., 59 Temple Place, Suite 330,   //
%// Boston, MA 02111-1307 USA.                                           //
%// //////////////////////////////////////////////////////////////////// //
%//
%// Primary maintainer for this file: Lior Elazary <elazary@usc.edu>
%// $HeadURL $
%// $Id $
%//


%-------- Drawing Covariance -----%
function eH = drawEllipse(x,P,nSigma)
eH = [];
P = P(1:2,1:2); % only plot x-y part
x = x(1:2);
if(~any(diag(P)==0))
    [V,D] = eig(P);
    y = nSigma*[cos(0:0.1:2*pi);sin(0:0.1:2*pi)];
    el = V*sqrtm(D)*y;
    el = [el el(:,1)]+repmat(x,1,size(el,2)+1);
    eH = line(el(1,:),el(2,:));
end