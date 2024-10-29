/*//-------------------------------------------------------------------------------
*  PixelgroupStrobe.h
*
*  Header file for PixelgroupStrobe
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
#ifndef PIXELGROUP_STROBE_H
#define PIXELGROUP_STROBE_H

#include "PixelgroupBase.h"
#include "strobe.h"
#include "PixelgroupStrobeInterface.h"


//--------------------------------------------------------
// a pixelgroup with strobing ability
class PixelgroupStrobe :
  public PixelgroupBase,
  public Strobe,
  public PixelgroupStrobeInterface
{
public:
  
  PixelgroupStrobe();
  PixelgroupStrobe(uint8_t count, ...);
  
  // Pixelgroup strobe interface
  void setStrobing(bool b);
  bool isStrobing() {return Strobe::isStrobing();};

  void update(unsigned long _now);
  
  void paint(PixelWriterInterface&);
};

#endif
