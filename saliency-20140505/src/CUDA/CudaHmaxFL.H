/*!@file CUDA/CudaHmaxFL.H Modified from T. Serre's HMAX model with feature learning  */

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
// $HeadURL: svn://isvn.usc.edu/software/invt/trunk/saliency/src/CUDA/CudaHmaxFL.H $
// $Id: CudaHmaxFL.H 12962 2010-03-06 02:13:53Z irock $
//

#ifndef CUDAHMAXFL_H_DEFINED
#define CUDAHMAXFL_H_DEFINED

#include "CUDA/CudaImage.H"
#include "CUDA/CudaHmax.H"
#include <vector>

#include <cmath>
#include <string>
#include <vector>
#include <dirent.h>

#define C1_PATCH_FILE_NAME "C1Patches"

//! Object recognition model inspired from Riesenhuber & Poggio's HMAX model
/*! See Riesenhuber & Poggio, Nature Neuroscience, 1999.
 */

class CudaHmaxFL : public CudaHmax {
public:
  //! Default constructor. Need to call init() later.
  CudaHmaxFL();

  //! Constructor
  CudaHmaxFL(MemoryPolicy mp, int dev, const int nori, const std::vector<int>& spacess,
         const std::vector<int>& scaless, const int c1spaceol = 2,
         const bool angleflag = true, const float s2t = 1.0F,
         const float s2s = 1.0F, const float gamma = 0.3F, const float divstart = 4.05F,
         const float divstep = -0.05F, const int fsmin = 5, const int fsstep = 2);

  //! Initialization
  void init(MemoryPolicy mp, int dev, const int nori, const std::vector<int>& spacess,
            const std::vector<int>& scaless, const int c1spaceol = 2,
            const bool angleflag = true, const float s2t = 1.0F,
            const float s2s = 1.0F, const float gamma = 0.3F, const float divstart = 4.05F,
            const float divstep = -0.05F, const int fsmin = 5, const int fsstep = 2);

  void initFilters(const float gamma, const float divstart, const float divstep, const int fsmin , const int fsstep);

  //! Free internal memory
  void freeMem();
  void freeC1Patches();

  //! Destructor
  ~CudaHmaxFL();

  //! Compute C2 responses from an input image
  void getC2(const CudaImage<float>& input, float**& c2Res);

  //! Randomly extract a set of C1Patches from positive training images
  void extractRandC1Patches(Image<float> *& posTrainingImages, int numPosTrainImages, std::vector<int> patchSizes, int nPatchesPerSize, int no);

  //! Set the c1patches that should be used
  void setC1Patches(CudaImage<float>***&patches,std::vector<int> patchSizes,int numPatchesPerSize);
  void readInC1Patches(std::string fileName);
  void writeOutC1Patches(std::string fileName);
  std::vector<int> getC1PatchSizes();
  int getC1PatchesPerSize();

  //! Get the c1patches that are being used
  CudaImage<float>***& getC1Patches();

  //! Calculate the distance from a patch to an image
  void windowedPatchDistance(CudaImage <float>*& images, int nimages, CudaImage <float> * &patches, int npatches, CudaImage<float>& D, float sumSquaredPatch);


protected:
  int nswb; //!< number of scales within a scale band
  CudaImage<float> ***c1Patches; //!< patches that should be compared in S2 activation c1Patches[patchSizes][patchesPerSize]
  float **sumPSq;
  std::vector<int> c1PatchSizes; //!< Number of square patch sizes of c1Patches
  int nC1PatchesPerSize; //!< Number of patches per patch size of c1Patches
};

#endif

// ######################################################################
/* So things look consistent in everyone's emacs... */
/* Local Variables: */
/* indent-tabs-mode: nil */
/* End: */
