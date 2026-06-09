# TASKS — segobits_sensors

## Your Job
Implement the HC-SR04 ultrasonic sensor driver on Arduino.

## Files To Edit
- `arduino/sensors/ultrasonic.h` — class declaration (skeleton provided)
- `arduino/sensors/ultrasonic.cpp` — full implementation

## Tasks Checklist
- [ ] `begin()` — pinMode(trigPin, OUTPUT) and pinMode(echoPin, INPUT)
- [ ] `measureDistance()` — pull TRIG LOW 2µs, HIGH 10µs, LOW; pulseIn timeout 30ms; return duration/58
- [ ] Return -1 on pulseIn timeout
- [ ] `getSmoothedDistance()` — rolling array of 3 readings, average non-(-1) values
- [ ] `isObstacleWithin(int threshold_cm)` — return true if smoothed < threshold
- [ ] Wire to TRIG=pin48, ECHO=pin49, VCC=5V
- [ ] Test: print distance every 200ms in Serial Monitor
- [ ] Test: hand at 35cm → isObstacleWithin(40) returns true
