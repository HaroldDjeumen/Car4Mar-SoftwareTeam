# Your Branch: sitholekendra61-rgb_movement

Welcome @sitholekendra61-rgb! You own the core Arduino movement engine.

## Your Role
You are responsible for all 6-motor drive logic on the Arduino Mega 2560.
Your code is the lowest layer of the rover — when the Raspberry Pi says
"go forward", your code is what actually spins the wheels.

## Files To Edit
- `arduino/MARS_Rover_Controller.ino`  ← main file, fill in all functions
- `arduino/config.h`  ← all pin defines are already here, do not change

## What To Implement
1. `setMotor(side, pos, speed, direction)`
   - side: 0=left, 1=right | pos: 0=front, 1=mid, 2=rear
   - speed: 0-255 PWM | direction: 1=forward, -1=backward, 0=coast
2. `driveForward(speed)` — sets all 6 motors forward at given PWM
3. `driveBackward(speed)` — sets all 6 motors in reverse
4. `emergencyStop()` — immediately cuts all motors to 0
5. `applyMotors()` — pushes currentSpeed with soft-start ramp
6. `pivotTurn(bool pivotLeft)` — left wheels reverse, right forward
7. `handleCommand(char cmd)` — switch on F/B/S/P/Q/+/-
   - F = forward at SPEED_DEFAULT
   - B = backward at SPEED_DEFAULT
   - S = emergency stop
   - P = pivot left, Q = pivot right
   - + = increase targetSpeed by 20 (max SPEED_MAX=220)
   - - = decrease targetSpeed by 20 (min SPEED_CRAWL=80)

## How It Connects
- Arduino receives single char commands from Raspberry Pi over USB Serial (Serial0)
- tttau28-ux is building the steering on top of your movement code
- segobits is building the ultrasonic sensor which will call emergencyStop()

## How To Test
1. Upload sketch to Arduino Mega via Arduino IDE
2. Open Serial Monitor at 115200 baud
3. Type F — wheels should spin forward
4. Type S — wheels should stop
5. Type P — left wheels reverse, right forward (pivot)
6. Check soft-start: speed should ramp up gradually, not jump

## Git Instructions
```bash
git add .
git commit -m "feat: implement 6-motor drive logic and handleCommand"
git push origin sitholekendra61-rgb_movement
```
Then open a Pull Request → target branch: **master_movement**

## Definition of Done
- [ ] All 6 motors spin forward on F command
- [ ] All 6 motors reverse on B command
- [ ] emergencyStop() cuts power instantly
- [ ] Soft-start ramp works (no sudden speed jumps)
- [ ] Pivot turn works (left side reverses, right side forward)
- [ ] Speed +/- commands adjust targetSpeed within bounds
- [ ] Code compiles without errors in Arduino IDE
