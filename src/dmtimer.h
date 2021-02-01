#ifndef DMTIMER_H
#define DMTIMER_H

#include "Arduino.h"

class DMTimer
{
private: //private members
public:  //public members
  //DMTimer constructor
  DMTimer();
  DMTimer(unsigned long interval);

  //indicates if next trigger time has been reached
  bool isTimeReached(unsigned long currentTime, unsigned long interval);
  bool isTimeReached(unsigned long currentTime);
  bool isTimeReached() { return isTimeReached(micros()); }

  //resets next trigger time to micros() + interval
  void reset() { setTriggerTime(micros() + _interval); }

  void setTriggerTime(unsigned long time);
  
  void setInterval(unsigned long interval);

private:
  unsigned long _triggerTime = 0;
  unsigned long _interval = 0;

  //indicates if the next trigger time is planned after micros() overflow.
  bool _isNextTimeAfterOverflow;
};

#endif //DMTIMER_H
