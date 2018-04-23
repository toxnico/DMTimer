#include <dmtimer.h>

/**
 * Demonstrates the use of multiple timers sharing the same time reference.
 * By doing this, we are sure there will be no time drift between timers
 * in case of long execution in one or the other.
 */

DMTimer timer1(1000000); //Create a timer at 1s interval
DMTimer timer2(300000);  //Create a timer at 300ms interval


void setup(){
  Serial.begin(115200);
}

void loop(){
  unsigned long now = micros();

  if(timer1.isTimeReached(now)){ //we pass the micros() value retrieved at loop() start
    Serial.println("Timer 1 Tick!"); //call what you need, it can be a long execution
  }

  if(timer2.isTimeReached(now)){ //we pass the same micros() value here
    Serial.println("Timer 2 Tick!"); //call what you need
  }

}
