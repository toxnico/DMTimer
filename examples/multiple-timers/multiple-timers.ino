#include <dmtimer.h>

/**
 * Demonstrates the simplest use of multiple Timers
 */

DMTimer timer1(1000000); //Create a timer at 1s interval
DMTimer timer2(300000);  //Create a timer at 300ms interval


void setup(){
  Serial.begin(115200);
}

void loop(){
  if(timer1.isTimeReached()){ //check if execution time has been reached
    Serial.println("Timer 1 Tick!"); //call what you need
  }

  if(timer2.isTimeReached()){ //check if execution time has been reached
    Serial.println("Timer 2 Tick!"); //call what you need
  }

}
