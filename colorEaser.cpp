/*//-------------------------------------------------------------------------------
*  colorEaser.cpp
*
*  Color Easer class based on Easer
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

#include "colorEaser.h"
#include "color.h"


//--------------------------------------------------------
// constructor
ColorEaser::ColorEaser() : Easer()
{};

ColorEaser::ColorEaser(easingFunc func) :  Easer(func)
{};



//--------------------------------------------------------
void ColorEaser::setFrom(Color& _c)
{
  m_from.setRGB(_c);
}

void ColorEaser::setFrom(uint8_t r, uint8_t g, uint8_t b)
{
  m_from.setRGB(r, g, b);
}

void ColorEaser::setTo(Color& _c)
{
  m_to.setRGB(_c);
}

void ColorEaser::setTo(uint8_t r, uint8_t g, uint8_t b)
{
  m_to.setRGB(r, g, b);
}


//--------------------------------------------------------
boolean ColorEaser::tick(Color& c)
{
  unsigned long _now = millis();
  
  return tick(_now, c);
}


boolean ColorEaser::tick(unsigned long _now, Color& c)
{
  double percent;  
  boolean result = Easer::tick(_now, &percent);
  
  if (percent >= 1.0) {
    switch (getLoop())
    {
      case EASING_LOOP_LOOP:
      while (percent > 1.0) {
        percent -= 1.0;
      }
      break;
    
      case EASING_LOOP_BOUNCE:
      {
        // reverse to from
        Color _c;
        _c.setRGB(m_from);
    
        setFrom(m_to);
        setTo(_c);
        
        while (percent > 1.0) {
          percent -= 1.0;
        }
      }
      break;
    
      case EASING_LOOP_NONE:
      default:
        // stop easing
        percent = 1.0;
      break;
    }
  }
  
  double rd = m_to.getR() - m_from.getR();
  double gd = m_to.getG() - m_from.getG();
  double bd = m_to.getB() - m_from.getB();
  
  uint8_t r = m_from.getR() + (uint8_t)(percent * rd);
  uint8_t g = m_from.getG() + (uint8_t)(percent * gd);
  uint8_t b = m_from.getB() + (uint8_t)(percent * bd);

  // set color
  c.setRGB(r, g, b);
  
  return result;
}