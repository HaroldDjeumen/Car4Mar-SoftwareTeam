# Branch: master_sensors

## Purpose
Arduino sensor drivers for the HC-SR04 ultrasonic sensor and MPU-6050 IMU.

## File Structure
```
arduino/sensors/
  ultrasonic.h     ← HC-SR04 class declaration
  ultrasonic.cpp   ← implementation
  imu.h            ← MPU-6050 class declaration
  imu.cpp          ← implementation
```

## Collaborator Branches
| Branch            | Owner      | Task                              |
|-------------------|------------|-----------------------------------|
| segobits_sensors  | segobits   | HC-SR04 ultrasonic implementation |

## Integration
- Include in main sketch: `#include "sensors/ultrasonic.h"`
- `Ultrasonic sonar(TRIG_PIN, ECHO_PIN);`
- Call `sonar.isObstacleWithin(40)` inside movement loop

## How To Merge Back
Open a Pull Request from your collaborator branch targeting **master_sensors**.
