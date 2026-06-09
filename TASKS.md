# TASKS — tttau28-ux_steering

## Your Job
Implement Ackermann steering servo control for 4 corner servos.

## Files To Edit
- `arduino/MARS_Rover_Controller.ino` — add steering functions

## Tasks Checklist
- [ ] Implement `setupServos()` — attach 4 servos, call centerSteering()
- [ ] Implement `steerLeft(int angle)` — front steer left, rear steer right (opposite)
- [ ] Implement `steerRight(int angle)` — mirror of steerLeft
- [ ] Implement `centerSteering()` — all 4 servos to 90 degrees
- [ ] Add L, R, C to handleCommand()
- [ ] Constrain angles with: constrain(angle, 0, SERVO_MAX_ANGLE)
- [ ] Test all 4 servos turn to correct positions
- [ ] Verify no servo jitter at startup
