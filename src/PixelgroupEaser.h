/*//-------------------------------------------------------------------------------
*  PixelgroupEaser.h
*
*  Header file for PixelgroupEaser
*  
*  This file is part of Pixelgroup library.
*  https://github.com/i-n-g-o/Pixelgroup
*
*  Copyright (c) Ingo Randolf, 2014
*
*  This Source Code Form is subject to the terms of the Mozilla Public
*  License, v. 2.0. If a copy of the MPL was not distributed with this
*  file, You can obtain one at https://mozilla.org/MPL/2.0/.
//-------------------------------------------------------------------------------*/
#ifndef PIXELGROUP_EASER_H
#define PIXELGROUP_EASER_H


#include "PixelgroupBase.h"
#include "colorEaser.h"
#include "PixelgroupEaserInterface.h"


//--------------------------------------------------------
// a pixelgroup with color easing ability
class PixelgroupEaser :
  public PixelgroupBase,
  public ColorEaser,
  public PixelgroupEaserInterface
{
public:
  
  PixelgroupEaser();
  PixelgroupEaser(uint8_t count, ...);
  
  // easer interface
  void update(unsigned long _now);
  
};

#endif
