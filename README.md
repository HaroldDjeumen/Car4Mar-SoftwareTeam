# Your Branch: segobits_sensors

Welcome @segobits! You own the ultrasonic obstacle sensor driver.

## Your Role
You build the HC-SR04 sensor driver that gives the rover its
closest-range obstacle awareness. Your code runs on the Arduino
and is the last line of defence before a collision.

## Files To Edit
- `arduino/sensors/ultrasonic.h`  ← class declaration
- `arduino/sensors/ultrasonic.cpp`  ← full implementation

## What To Implement
**Ultrasonic class:**
1. `Ultrasonic(int trigPin, int echoPin)`
2. `begin()` — pinMode setup
3. `measureDistance()` → long (returns distance in cm, -1 on timeout)
   - Pull TRIG LOW 2µs, HIGH 10µs, LOW
   - pulseIn(echoPin, HIGH, 30000) — 30ms timeout
   - return duration / 58
4. `getSmoothedDistance()` → long
   - Keep rolling array of last 3 readings
   - Return average, skip -1 (timeout) readings
5. `isObstacleWithin(int threshold_cm)` → bool
   - Returns true if getSmoothedDistance() < threshold_cm

## How It Connects
- sitholekendra61-rgb calls isObstacleWithin(40) in the movement loop
- If true → calls emergencyStop()
- Sensor wired: VCC=5V, GND=GND, TRIG=pin48, ECHO=pin49

## How To Test
1. Wire HC-SR04 to Arduino pins 48 and 49
2. Open Serial Monitor at 115200 baud
3. Print getSmoothedDistance() every 200ms
4. Move hand toward sensor — distance should count down
5. At under 40cm isObstacleWithin(40) should return true

## Git Instructions
```bash
git add .
git commit -m "feat: implement HC-SR04 ultrasonic driver with rolling average"
git push origin segobits_sensors
```
Then open a Pull Request → target branch: **master_sensors**

## Definition of Done
- [ ] measureDistance() returns correct cm values (test with ruler)
- [ ] Returns -1 on timeout (no object detected within 4m)
- [ ] Rolling average smooths out noise correctly
- [ ] isObstacleWithin(40) returns true at 35cm
- [ ] isObstacleWithin(40) returns false at 50cm
- [ ] Class compiles cleanly as a header + cpp pair
