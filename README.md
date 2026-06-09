# Your Branch: Mbu1310_power

Welcome @Mbu1310! You own the solar tracker and battery monitor.

## Your Role
You keep the rover alive by tracking the sun to charge the battery
and alerting the system when power is getting low. Your code runs
on the Arduino alongside the movement code.

## Files To Edit
- `arduino/power/solar_tracker.h`  ← already has class skeleton
- `arduino/power/solar_tracker.cpp`  ← implement all methods
- `arduino/power/battery_monitor.h`  ← implement voltage reading

## What To Implement
1. **SolarTracker class** (solar_tracker.cpp)
   - `begin()` — attach pan servo (pin 8) and tilt servo (pin 9), call park()
   - `update(bool roverStopped)`
     - Only track if roverStopped == true
     - Read analogRead(A0)=LDR_LEFT, analogRead(A1)=LDR_RIGHT
     - If (LEFT - RIGHT) > THRESHOLD (15): panAngle -= SERVO_STEP (1)
     - If (RIGHT - LEFT) > THRESHOLD (15): panAngle += SERVO_STEP (1)
     - Constrain panAngle between PAN_MIN=10 and PAN_MAX=170
     - Repeat for tilt: A2=LDR_TOP, A3=LDR_BOTTOM, tiltAngle A2 vs A3
     - Constrain tiltAngle between TILT_MIN=20 and TILT_MAX=100
     - Write updated angles to servos
   - `park()` — write PARK_PAN=90 to pan servo, PARK_TILT=10 to tilt servo

2. **BatteryMonitor** (battery_monitor.h)
   - `begin()` — pinMode(A8, INPUT)
   - `getVoltage()` → float
     - raw = analogRead(A8)
     - voltage = raw * (5.0 / 1023.0) * VOLTAGE_DIVIDER_RATIO (11.0)
     - return voltage
   - `isLow()` → bool — return getVoltage() < LOW_BATTERY_THRESHOLD (18.0)

## How It Connects
- Main rover loop calls `solarTracker.update(lastCommand == 'S')`
- If batteryMonitor.isLow() → send alert over Serial to Pi
- LDRs wired to A0-A3, pan servo to pin 8, tilt servo to pin 9
- Voltage divider on A8: battery+ → 100kΩ → A8 → 10kΩ → GND

## How To Test
1. Shine a torch on LDR_LEFT — pan servo should rotate left
2. Shine torch on LDR_RIGHT — pan servo should rotate right
3. Call park() — both servos should return to rest position
4. Check battery voltage reading matches multimeter measurement
5. isLow() should return true when simulating low voltage

## Git Instructions
```bash
git add .
git commit -m "feat: implement solar tracker and battery monitor"
git push origin Mbu1310_power
```
Then open a Pull Request → target branch: **master_power**

## Definition of Done
- [ ] Pan servo tracks light left and right correctly
- [ ] Tilt servo tracks light up and down correctly
- [ ] park() returns panel to flat safe position
- [ ] Tracker only activates when rover is stopped
- [ ] getVoltage() matches multimeter within 0.5V
- [ ] isLow() triggers correctly at 18V threshold
- [ ] No servo jitter when LDR readings are balanced
