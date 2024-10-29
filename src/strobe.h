/*//-------------------------------------------------------------------------------
*  strobe.h
*
*  Header file for Strobe
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
#ifndef STROBE_H
#define STROBE_H

#include <inttypes.h>
#include <stdbool.h>

//--------------------------------------------------------
//
class Strobe
{
public:
  Strobe();


  void setOnTime(uint16_t time) {m_strobeOnTime = time;};
  void setOnTimeSec(double time) {m_strobeOnTime = (uint16_t)(time*1000.0);};
  uint16_t getOnTime() {return m_strobeOnTime;};
  
  void setOffTime(uint16_t time) {m_strobeOffTime = time;};
  void setOffTimeSec(double time) {m_strobeOffTime = (uint16_t)(time*1000.0);};
  uint16_t getOffTime() {return m_strobeOffTime;};
  
  void setStrobeState(bool);
  void setStrobeState(bool, unsigned long _now);
  bool getStrobeState() {return m_state;};  
  
  void setStrobing(bool);
  bool isStrobing() {return m_isStrobing;};
  
  bool update(unsigned long _now);
  
private:
  uint16_t        m_strobeOffTime; // in ms (max 65.535 ms)
  uint16_t        m_strobeOnTime; // in ms (max 65.535 ms)
  
  unsigned long   m_lastUpdate;
  bool            m_state;
  
  bool            m_isStrobing;
};


#endif
