/*//-------------------------------------------------------------------------------
*  PixelgroupE.h
*
*  Header file for Packetizer
*  
*  written by: Ingo Randolf - 2014
*
*
*  This library is free software; you can redistribute it and/or
*  modify it under the terms of the GNU Lesser General Public
*  License as published by the Free Software Foundation; either
*  version 2.1 of the License, or (at your option) any later version.
*
*  This library is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
*  Lesser General Public License for more details.
//-------------------------------------------------------------------------------*/
#ifndef PIXELGROUP_E_H
#define PIXELGROUP_E_H


#include "colorEaser.h"


//--------------------------------------------------------
// color easing
class PixelgroupE : public ColorEaser
{
public:
  
  PixelgroupE();
  
  // color easer
  void setEasing(boolean easing) {m_isEasing = easing;};
  boolean isEasing() {return m_isEasing;};
  
  boolean tick(Color&);
  boolean tick(unsigned long _now, Color&);


private:  
  boolean        m_isEasing;  
  
};

#endif
