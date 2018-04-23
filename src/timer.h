#ifndef TIMER_H
#define TIMER_H

#include "Arduino.h"

class Timer {
private: //private members

public: //public members
  //Timer constructor
  Timer();
  Timer(unsigned long interval);

  bool isTimeReached(unsigned long currentTime, unsigned long interval);
  bool isTimeReached(unsigned long currentTime);
  bool isTimeReached() { return isTimeReached(micros()); }

  void reset() { setLastTime(micros()); }
  void setLastTime(unsigned long time) { this->_lastTime = time; }
  void setInterval(unsigned long interval) { this->_interval = interval; }

private:
  unsigned long _lastTime = 0;
  unsigned long _interval = 0;

};

#endif //TIMER_H
