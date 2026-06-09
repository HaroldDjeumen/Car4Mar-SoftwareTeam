/*
 * MARS Rover Controller — Arduino Mega 2560
 * Branch: master_movement
 *
 * Receives single-char commands over USB Serial from Raspberry Pi:
 *   F=forward  B=backward  L=left  R=right  S=stop
 *   P=pivot_left  Q=pivot_right  +=speed_up  -=speed_down
 */

#include <Servo.h>
#include "config.h"

// --- Globals ---
int targetSpeed   = SPEED_DEFAULT;
int currentSpeed  = 0;
char lastCommand  = 'S';

// Corner steering servos
Servo servoFL, servoFR, servoRL, servoRR;

// -------------------------------------------------------
void setup() {
  Serial.begin(115200);

  // Motor PWM pins
  int pwmPins[] = {PWM_FL, PWM_ML, PWM_RL, PWM_FR, PWM_MR, PWM_RR};
  for (int i = 0; i < 6; i++) pinMode(pwmPins[i], OUTPUT);

  // Motor direction pins
  int dirPins[] = {DIR_FL_A, DIR_FL_B, DIR_ML_A, DIR_ML_B,
                   DIR_RL_A, DIR_RL_B, DIR_FR_A, DIR_FR_B,
                   DIR_MR_A, DIR_MR_B, DIR_RR_A, DIR_RR_B};
  for (int i = 0; i < 12; i++) pinMode(dirPins[i], OUTPUT);

  // Attach servos
  servoFL.attach(SERVO_FL);
  servoFR.attach(SERVO_FR);
  servoRL.attach(SERVO_RL);
  servoRR.attach(SERVO_RR);

  // TODO (tttau28-ux): centerSteering() goes here

  Serial.println("MARS Rover Controller ready.");
}

// -------------------------------------------------------
void loop() {
  if (Serial.available() > 0) {
    char cmd = Serial.read();
    handleCommand(cmd);
  }

  // TODO (sitholekendra61-rgb): applyMotors() with soft-start ramp
  delay(20);
}

// -------------------------------------------------------
// TODO (sitholekendra61-rgb): implement these movement functions

void setMotor(int side, int pos, int speed, int direction) {
  // side: 0=left, 1=right  |  pos: 0=front, 1=mid, 2=rear
  // speed: 0-255  |  direction: 1=fwd, -1=rev, 0=coast
  // TODO
}

void driveForward(int speed) {
  // TODO
}

void driveBackward(int speed) {
  // TODO
}

void emergencyStop() {
  // TODO — cut all motors immediately
}

void applyMotors() {
  // TODO — soft-start ramp toward targetSpeed
}

void pivotTurn(bool pivotLeft) {
  // TODO — left wheels reverse, right forward (or vice versa)
}

// TODO (tttau28-ux): implement these steering functions
void setupServos() { }
void steerLeft(int angle) { }
void steerRight(int angle) { }
void centerSteering() { }

// -------------------------------------------------------
void handleCommand(char cmd) {
  lastCommand = cmd;
  switch (cmd) {
    case 'F': driveForward(targetSpeed);  break;
    case 'B': driveBackward(targetSpeed); break;
    case 'S': emergencyStop();            break;
    case 'L': steerLeft(SERVO_MAX_ANGLE); break;
    case 'R': steerRight(SERVO_MAX_ANGLE);break;
    case 'P': pivotTurn(true);            break;
    case 'Q': pivotTurn(false);           break;
    case '+': targetSpeed = min(targetSpeed + 20, SPEED_MAX);   break;
    case '-': targetSpeed = max(targetSpeed - 20, SPEED_CRAWL); break;
    default: break;
  }
  Serial.print("CMD:"); Serial.println(cmd);
}
