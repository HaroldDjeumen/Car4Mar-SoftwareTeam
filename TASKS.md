# TASKS — Mbu1310_power

## Your Job
Implement the battery voltage monitor on Arduino.

## Files To Edit
- `arduino/power/battery_monitor.h` — implement getVoltage() and isLow()

## Tasks Checklist
- [ ] BatteryMonitor.begin() — pinMode(A8, INPUT)
- [ ] BatteryMonitor.getVoltage() — analogRead(A8) * (5.0/1023.0) * 11.0
- [ ] BatteryMonitor.isLow() — return getVoltage() < 18.0
- [ ] Test voltage reading matches multimeter within 0.5V
- [ ] isLow() triggers correctly at 18V threshold
