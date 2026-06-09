# Your Branch: Mbu1310_power

Welcome @Mbu1310! You own the battery voltage monitor.

## Your Role
You keep the rover alive by monitoring battery voltage and alerting
the system when power is getting low. Your code runs on the Arduino
alongside the movement code.

## Files To Edit
- `arduino/power/battery_monitor.h` — implement voltage reading

## What To Implement
**BatteryMonitor** (battery_monitor.h)
- `begin()` — pinMode(A8, INPUT)
- `getVoltage()` → float
  - raw = analogRead(A8)
  - voltage = raw * (5.0 / 1023.0) * VOLTAGE_DIVIDER_RATIO (11.0)
  - return voltage
- `isLow()` → bool — return getVoltage() < LOW_BATTERY_THRESHOLD (18.0)

## How It Connects
- If batteryMonitor.isLow() → send alert over Serial to Pi
- Voltage divider on A8: battery+ → 100kΩ → A8 → 10kΩ → GND

## How To Test
1. Check battery voltage reading matches multimeter measurement
2. isLow() should return true when simulating low voltage

## Git Instructions
```bash
git add .
git commit -m "feat: implement battery monitor"
git push origin Mbu1310_power
```
Then open a Pull Request → target branch: **master_power**

## Definition of Done
- [ ] getVoltage() matches multimeter within 0.5V
- [ ] isLow() triggers correctly at 18V threshold
