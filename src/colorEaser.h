/*//-------------------------------------------------------------------------------
*  colorEaser.h
*
*  Header file for ColorEaser
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
#ifndef COLOR_EASER_H
#define COLOR_EASER_H

#include "easer.h"
#include "color.h"

//--------------------------------------------------------
// a color easer
class ColorEaser : public Easer
{
  public:
  ColorEaser();
  ColorEaser(easingFunc);

  void setFrom(Color&);
  void setFrom(uint8_t, uint8_t, uint8_t);
  Color& getFrom() {return m_from;};
  
  void setTo(Color&);
  void setTo(uint8_t, uint8_t, uint8_t);
  Color& getTo() {return m_to;};

  void setEasing(bool easing) {m_isEasing = easing;};
  bool isEasing() {return m_isEasing;};

  bool update(unsigned long _now, Color& c);
  
private:
  Color       m_from;
  Color       m_to;
  
  bool     m_isEasing;
};


#endif
