#include "timer.h"

/**
* Constructor
*/
Timer::Timer(){

}

Timer::Timer(unsigned long interval){
  setInterval(interval);
}

bool Timer::isTimeReached(unsigned long currentTime){
  return isTimeReached(currentTime, this->_interval);
}

bool Timer::isTimeReached(unsigned long currentTime, unsigned long interval){
  if(currentTime > _lastTime + interval)
  {
    _lastTime = currentTime;
    return true;
  }
  return false;
}
