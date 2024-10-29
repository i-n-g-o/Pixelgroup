/*//-------------------------------------------------------------------------------
*  PixelgroupStrobeInterface.h
*
*  Interface for strobing Pixelgroups
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
#ifndef PIXELGROUP_STROBE_INTERFACE_H
#define PIXELGROUP_STROBE_INTERFACE_H

#include <inttypes.h>
#include <stdbool.h>

#include "pixelWriterInterface.h"

//--------------------------------------------------------
// strobing interface
class PixelgroupStrobeInterface
{
public:  
  virtual void setStrobing(bool b) = 0;
  virtual bool isStrobing() = 0;

  virtual void paint(PixelWriterInterface&) = 0;

  virtual void update(unsigned long _now) = 0;
};

#endif
