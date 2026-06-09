#include "solar_tracker.h"

SolarTracker::SolarTracker() : _panAngle(PARK_PAN), _tiltAngle(PARK_TILT) {}

void SolarTracker::begin() {
  // TODO (Mbu1310): attach servos and call park()
}

void SolarTracker::update(bool roverStopped) {
  // TODO (Mbu1310):
  // Only track if roverStopped == true
  // Read A0-A3 LDRs
  // Adjust _panAngle and _tiltAngle based on LDR differences
  // Constrain angles and write to servos
}

void SolarTracker::park() {
  // TODO (Mbu1310): write PARK_PAN and PARK_TILT to servos
}
