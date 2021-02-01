#include "dmtimer.h"

/**
* Constructor
*/
DMTimer::DMTimer()
{
}

DMTimer::DMTimer(unsigned long interval)
{
  setInterval(interval);
}

bool DMTimer::isTimeReached(unsigned long currentTime)
{
  return isTimeReached(currentTime, this->_interval);
}

bool DMTimer::isTimeReached(unsigned long currentTime, unsigned long interval)
{
  if (!_isNextTimeAfterOverflow) //easy case
  {
    if (currentTime >= _triggerTime)
    {
      setTriggerTime(_triggerTime + interval);
      return true;
    }
  }
  else //next trigger time will be is after micros() overflow
  {
    //calculate the idle time window
    unsigned long maxInteger = 0;
    maxInteger--;
    unsigned long from = maxInteger - interval;
    unsigned long to = maxInteger;

    if(currentTime > from && currentTime <= to)
    {
      return false;
    }
    else
    {
      if(currentTime >= _triggerTime)
      {
        setTriggerTime(_triggerTime + interval);
        return true;
      }
    }
  }
  return false;
}

void DMTimer::setInterval(unsigned long interval)
{
  this->_interval = interval;
  this->_triggerTime = micros() + interval;
}

void DMTimer::setTriggerTime(unsigned long time)
{
  //is next time before the current next time ? if so, we'll consider the overflow of micros()
  this->_isNextTimeAfterOverflow = time < this->_triggerTime;

  this->_triggerTime = time;
}