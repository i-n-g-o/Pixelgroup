/*//-------------------------------------------------------------------------------
*  PixelgroupS.h
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
#ifndef PIXELGROUP_S_H
#define PIXELGROUP_S_H


#include "strobe.h"


//--------------------------------------------------------
// strobing on/off
class PixelgroupS : public Strobe
{
public:
  
  PixelgroupS();

  // strobe
//   void setStrobing(boolean b);
//   boolean isStrobing() {return m_isStrobing;};
//   Strobe& getStrobe() {return m_strobe;};
  void setStrobing(boolean);
  boolean isStrobing() {return m_isStrobing;};
  
  boolean tick();
  boolean tick(unsigned long _now);
  

private:
  boolean        m_isStrobing;
};

#endif
