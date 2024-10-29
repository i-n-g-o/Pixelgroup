/*//-------------------------------------------------------------------------------
*  easerTypes.h
*
*  EaserTypes
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
#ifndef EASER_TYPES_H
#define EASER_TYPES_H


typedef enum easingFunc_t {
  EASING_BACK = 0,
  EASING_BOUNCE,
  EASING_CIRCULAR,
  EASING_CUBIC,
  EASING_ELASTIC,
  EASING_EXPONENTIAL,
  EASING_LINEAR,
  EASING_QUADRATIC,
  EASING_QUARTIC,
  EASING_QUINTIC,
  EASING_SINE,
  
  EASING_MAX
} easingFunc;


typedef enum easingType_t {
  EASING_IN = 0,
  EASING_OUT,
  EASING_IN_OUT,
  
  EASING_TYPE_MAX
} easingType;


typedef enum easingLoop_t {
  EASING_LOOP_NONE = 0,
  EASING_LOOP_LOOP,
  EASING_LOOP_BOUNCE,
  
  EASING_LOOP_MAX
} easingLoop;


#endif
