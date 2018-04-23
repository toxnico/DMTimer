#include <dmtimer.h>

/**
 * Demonstrates the simplest use of the Timer class
 */

DMTimer myTimer(1000000); //Create a timer and specify its interval in microseconds

void setup(){
  Serial.begin(115200);
}

void loop(){

  bool some_condition = true;

  if(some_condition) //we can change the interval when we want
    myTimer.setInterval(250000);

  if(myTimer.isTimeReached()){ //check if execution time has been reached
    Serial.println("Tick!"); //call what you need
  }
}
