#ifndef BATTERY_MONITOR_H
#define BATTERY_MONITOR_H

#include <Arduino.h>
#include "config.h"

class BatteryMonitor {
public:
  BatteryMonitor() {}

  void begin() {
    pinMode(BATTERY_PIN, INPUT);
  }

  float getVoltage() {
    // TODO (Mbu1310):
    // raw = analogRead(BATTERY_PIN)
    // return raw * (5.0 / 1023.0) * VOLTAGE_DIVIDER_RATIO
    return 0.0;
  }

  bool isLow() {
    // TODO (Mbu1310): return getVoltage() < LOW_BATTERY_THRESHOLD
    return false;
  }
};

#endif
