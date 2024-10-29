/*//-------------------------------------------------------------------------------
*  PixelgroupEaserInterface.h
*
*  Interface for Pixelgroup Easer
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
#ifndef PIXELGROUP_EASER_INTERFACE_H
#define PIXELGROUP_EASER_INTERFACE_H


//--------------------------------------------------------
// strobing interface
class PixelgroupEaserInterface
{
public:

  virtual void update(unsigned long _now) = 0;
};

#endif
