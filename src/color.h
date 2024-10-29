/*//-------------------------------------------------------------------------------
*  color.h
*
*  Header file for color
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

#ifndef COLOR_H
#define COLOR_H

#include <inttypes.h>

//--------------------------------------------------------
// color
class Color
{  
public:
  Color();
  Color(uint8_t, uint8_t, uint8_t);  
  Color(const Color&);
  
  void operator*=(double f);
  Color& operator*(double f);
  
  void setRGB(uint8_t, uint8_t, uint8_t);
  void setRGB(Color&);
  void setR(uint8_t);
  void setG(uint8_t);
  void setB(uint8_t);
  uint8_t getR() {return r;};
  uint8_t getG() {return g;};
  uint8_t getB() {return b;};
  
  
private:
  uint8_t  r;
  uint8_t  g;
  uint8_t  b;
};


#endif
