# Your Branch: tttau28-ux_steering

Welcome @tttau28-ux! You own the steering servo system.

## Your Role
You implement Ackermann-style corner steering using 4 DS3218 servos.
When the rover turns, your code rotates the front and rear corner wheels
in opposite directions to achieve a tight turning radius.

## Files To Edit
- `arduino/MARS_Rover_Controller.ino`  ← add steering functions here
- `arduino/config.h`  ← servo pin defines already set (pins 44-47)

## What To Implement
1. `setupServos()` — attach all 4 servos and call centerSteering()
2. `steerLeft(int angle)`
   - Front-left servo: CENTER - angle
   - Front-right servo: CENTER - angle
   - Rear-left servo: CENTER + angle  ← rear steers OPPOSITE to front
   - Rear-right servo: CENTER + angle
3. `steerRight(int angle)` — mirror of steerLeft
4. `centerSteering()` — all 4 servos write(90)
5. Servo limits: CENTER=90, MAX_ANGLE=35 degrees, use constrain()
6. Add L and R to handleCommand():
   - L = steerLeft(SERVO_MAX_ANGLE)
   - R = steerRight(SERVO_MAX_ANGLE)
   - C = centerSteering()

## How It Connects
- sitholekendra61-rgb owns motor speed — you own wheel angle
- The Servo power wire (red) connects to 5V BEC, NOT Arduino 5V pin
- Signal wires only go to Arduino pins 44, 45, 46, 47

## How To Test
1. Attach servos to pins 44-47 and power from BEC
2. Upload and open Serial Monitor at 115200 baud
3. Type L — all front wheels should angle left, rear wheels angle right
4. Type R — opposite
5. Type C — all wheels should return to straight ahead (90 degrees)
6. Verify physical servo travel does not exceed 35 degrees each side

## Git Instructions
```bash
git add .
git commit -m "feat: implement Ackermann steering servo control"
git push origin tttau28-ux_steering
```
Then open a Pull Request → target branch: **master_movement**

## Definition of Done
- [ ] All 4 servos centre at 90 degrees on startup
- [ ] steerLeft rotates front wheels left and rear wheels right
- [ ] steerRight is the mirror opposite
- [ ] Servo angles are constrained to 35 degrees max
- [ ] L, R, C commands work from Serial Monitor
- [ ] No servo jitter or overshooting at startup
