#ifndef SOLAR_TRACKER_H
#define SOLAR_TRACKER_H

#include <Arduino.h>
#include <Servo.h>
#include "config.h"

class SolarTracker {
public:
  SolarTracker();
  void begin();
  void update(bool roverStopped);
  void park();

private:
  Servo _panServo;
  Servo _tiltServo;
  int   _panAngle;
  int   _tiltAngle;
};

#endif
