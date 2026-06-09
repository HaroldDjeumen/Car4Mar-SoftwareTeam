#include "ultrasonic.h"

Ultrasonic::Ultrasonic(int trigPin, int echoPin)
  : _trigPin(trigPin), _echoPin(echoPin), _readIndex(0)
{
  for (int i = 0; i < ROLLING_WINDOW; i++) _readings[i] = -1;
}

void Ultrasonic::begin() {
  // TODO (segobits): set pinMode for trig and echo
}

long Ultrasonic::measureDistance() {
  // TODO (segobits): implement HC-SR04 pulse sequence
  // Pull TRIG LOW 2µs, HIGH 10µs, LOW
  // pulseIn(echoPin, HIGH, 30000)
  // return duration / 58
  return -1;
}

long Ultrasonic::getSmoothedDistance() {
  // TODO (segobits): rolling average, skip -1 values
  return -1;
}

bool Ultrasonic::isObstacleWithin(int threshold_cm) {
  // TODO (segobits): return getSmoothedDistance() < threshold_cm
  return false;
}
