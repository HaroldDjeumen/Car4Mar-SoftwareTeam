#ifndef CONFIG_H
#define CONFIG_H

// Motor PWM pins (EN pins on VNH5019)
#define PWM_FL 2
#define PWM_ML 3
#define PWM_RL 4
#define PWM_FR 5
#define PWM_MR 6
#define PWM_RR 7

// Motor direction pins (INA/INB on VNH5019)
// Left side
#define DIR_FL_A 22
#define DIR_FL_B 23
#define DIR_ML_A 24
#define DIR_ML_B 25
#define DIR_RL_A 26
#define DIR_RL_B 27
// Right side
#define DIR_FR_A 28
#define DIR_FR_B 29
#define DIR_MR_A 30
#define DIR_MR_B 31
#define DIR_RR_A 32
#define DIR_RR_B 33

// Corner steering servo pins
#define SERVO_FL 44
#define SERVO_FR 45
#define SERVO_RL 46
#define SERVO_RR 47

// Ultrasonic sensor
#define TRIG_PIN 48
#define ECHO_PIN 49

// Solar tracker servos
#define PAN_SERVO_PIN  8
#define TILT_SERVO_PIN 9

// LDR pins (analog)
#define LDR_LEFT  A0
#define LDR_RIGHT A1
#define LDR_TOP   A2
#define LDR_BOTTOM A3

// Battery voltage divider pin
#define BATTERY_PIN A8

// Speed constants
#define SPEED_DEFAULT 150
#define SPEED_MAX     220
#define SPEED_CRAWL    80
#define RAMP_STEP       5

// Servo limits
#define SERVO_CENTER    90
#define SERVO_MAX_ANGLE 35
#define PAN_MIN   10
#define PAN_MAX  170
#define TILT_MIN  20
#define TILT_MAX 100
#define PARK_PAN  90
#define PARK_TILT 10

// Solar tracker
#define LDR_THRESHOLD 15
#define SERVO_STEP     1

// Battery
#define VOLTAGE_DIVIDER_RATIO 11.0
#define LOW_BATTERY_THRESHOLD 18.0

#endif
