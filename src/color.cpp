/*//-------------------------------------------------------------------------------
*  color.cpp
*
*  Color class
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

#include "color.h"

//--------------------------------------------------------
// color
Color::Color() :
  r(0)
  ,g(0)
  ,b(0)
{
}

Color::Color(uint8_t _r, uint8_t _g, uint8_t _b) :
  r(_r)
  ,g(_g)
  ,b(_b)
{
}

Color::Color(const Color& c) :
  r(c.r)
  ,g(c.g)
  ,b(c.b)
{  
}



void Color::setRGB(uint8_t _r, uint8_t _g, uint8_t _b)
{
  r = _r;
  g = _g;
  b = _b;
}


void Color::setRGB(Color& color)
{
  r = color.getR();
  g = color.getG();
  b = color.getB();
}



void Color::setR(uint8_t _r)
{
  r = _r;
}

void Color::setG(uint8_t _g)
{
  g = _g;
}

void Color::setB(uint8_t _b)
{
  b = _b;
}


void Color::operator*=(double f)
{
  if (f <= 0) {
    r = g = b = 0;
    return;
  }
  
  if (f == 1.0) return;
  
  r *= f;
  g *= f;
  b *= f;
}

Color& Color::operator*(double f)
{
  if (f <= 0) {
    r = g = b = 0;
    return *this;
  }
  
  if (f == 1.0) return *this;
  
  r *= f;
  g *= f;
  b *= f;
  
  return *this;
}