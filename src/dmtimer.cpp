#include "dmtimer.h"

/**
* Constructor
*/
DMTimer::DMTimer(){

}

DMTimer::DMTimer(unsigned long interval){
  setInterval(interval);
}

bool DMTimer::isTimeReached(unsigned long currentTime){
  return isTimeReached(currentTime, this->_interval);
}

bool DMTimer::isTimeReached(unsigned long currentTime, unsigned long interval){
  if(currentTime > _lastTime + interval)
  {
    _lastTime = currentTime;
    return true;
  }
  return false;
}
