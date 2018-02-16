# Timer
Another Arduino Timer

The simplest use could be:
```cpp
Timer myTimer(1000000); //Create a timer and specify its interval in microseconds

void setup(){
  Serial.begin(115200);
}

void loop(){
  if(myTimer.isTimeReached()){ //check if execution time has been reached
    Serial.println("Tick!"); //call what you need
  }
}


```
