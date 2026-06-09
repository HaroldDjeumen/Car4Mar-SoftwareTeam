# TASKS — sitholekendra61-rgb_movement

## Your Job
Implement the complete 6-motor skid-steer drive system on the Arduino Mega.

## Files To Edit
- `arduino/MARS_Rover_Controller.ino`
- Do NOT change `arduino/config.h`

## Tasks Checklist
- [ ] Implement `setMotor(side, pos, speed, direction)`
- [ ] Implement `driveForward(speed)`
- [ ] Implement `driveBackward(speed)`
- [ ] Implement `emergencyStop()`
- [ ] Implement `applyMotors()` with soft-start ramp (RAMP_STEP = 5)
- [ ] Implement `pivotTurn(bool pivotLeft)` — left side reverse, right forward
- [ ] Handle F/B/S/P/Q/+/- in `handleCommand()`
- [ ] Inner wheel speed on turns: 60% of outer wheel speed
- [ ] Test all commands from Arduino Serial Monitor at 115200 baud
