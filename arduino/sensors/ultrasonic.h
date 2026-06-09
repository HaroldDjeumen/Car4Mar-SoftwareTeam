#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include <Arduino.h>

#define ROLLING_WINDOW 3

class Ultrasonic {
public:
  Ultrasonic(int trigPin, int echoPin);
  void begin();
  long measureDistance();        // returns cm, -1 on timeout
  long getSmoothedDistance();    // rolling average of last 3 readings
  bool isObstacleWithin(int threshold_cm);

private:
  int   _trigPin;
  int   _echoPin;
  long  _readings[ROLLING_WINDOW];
  int   _readIndex;
};

#endif
