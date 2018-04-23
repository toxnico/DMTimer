#ifndef DMTIMER_H
#define DMTIMER_H

#include "Arduino.h"

class DMTimer {
private: //private members

public: //public members
  //DMTimer constructor
  DMTimer();
  DMTimer(unsigned long interval);

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

#endif //DMTIMER_H
