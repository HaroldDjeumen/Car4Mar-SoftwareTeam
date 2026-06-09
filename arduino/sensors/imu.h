#ifndef IMU_H
#define IMU_H

#include <Arduino.h>
#include <Wire.h>

#define MPU6050_ADDR 0x68
#define PWR_MGMT_1   0x6B
#define ACCEL_XOUT_H 0x3B
#define GYRO_XOUT_H  0x43

class IMU {
public:
  IMU();
  bool begin();                            // returns false if not found on I2C
  void update();                           // read raw registers
  float getPitch();                        // degrees
  float getRoll();                         // degrees
  float getHeading();                      // approximate heading degrees

private:
  int16_t _ax, _ay, _az;
  int16_t _gx, _gy, _gz;
};

#endif
