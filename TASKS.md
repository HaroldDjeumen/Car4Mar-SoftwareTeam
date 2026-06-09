# TASKS — Mbu1310_power

## Your Job
Implement the solar tracker and battery voltage monitor on Arduino.

## Files To Edit
- `arduino/power/solar_tracker.cpp` — implement all methods
- `arduino/power/battery_monitor.h` — implement getVoltage() and isLow()

## Tasks Checklist
- [ ] SolarTracker.begin() — attach pan (pin 8) and tilt (pin 9) servos, call park()
- [ ] SolarTracker.update(roverStopped) — only track if roverStopped==true
- [ ] update(): read A0 (LDR_LEFT), A1 (LDR_RIGHT), A2 (LDR_TOP), A3 (LDR_BOTTOM)
- [ ] If abs(LEFT-RIGHT) > 15: adjust panAngle by SERVO_STEP toward brighter side
- [ ] If abs(TOP-BOTTOM) > 15: adjust tiltAngle by SERVO_STEP
- [ ] Constrain pan to PAN_MIN=10 / PAN_MAX=170, tilt to TILT_MIN=20 / TILT_MAX=100
- [ ] park() — write PARK_PAN=90 and PARK_TILT=10
- [ ] BatteryMonitor.getVoltage() — analogRead(A8) * (5.0/1023.0) * 11.0
- [ ] BatteryMonitor.isLow() — return getVoltage() < 18.0
- [ ] Test: torch on LDR_LEFT → pan servo rotates left
- [ ] Test: voltage reading matches multimeter within 0.5V
