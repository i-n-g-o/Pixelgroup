/*//-------------------------------------------------------------------------------
*  colorEaser.cpp
*
*  Color Easer class based on Easer
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

#include "colorEaser.h"
#include "color.h"


//--------------------------------------------------------
// constructor
ColorEaser::ColorEaser() : Easer()
  ,m_isEasing(false)
{};

ColorEaser::ColorEaser(easingFunc func) : Easer(func)
  ,m_isEasing(false)
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
// return dirty flag
bool ColorEaser::update(unsigned long _now, Color& c)
{
  // we are not easing
  // we are clean
  // return
  if (!m_isEasing) return false;


  // do easing
  double percent;  
  m_isEasing = Easer::update(_now, &percent);

  double rd = m_to.getR() - m_from.getR();
  double gd = m_to.getG() - m_from.getG();
  double bd = m_to.getB() - m_from.getB();

  uint8_t r = (uint8_t)(m_from.getR() + (percent * rd));
  uint8_t g = (uint8_t)(m_from.getG() + (percent * gd));
  uint8_t b = (uint8_t)(m_from.getB() + (percent * bd));

  // set color
  c.setRGB(r, g, b);
  
  // we are dirty
  return true;
}
