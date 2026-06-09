#include "imu.h"

IMU::IMU() : _ax(0), _ay(0), _az(0), _gx(0), _gy(0), _gz(0) {}

bool IMU::begin() {
  Wire.begin();
  // Wake MPU-6050
  Wire.beginTransmission(MPU6050_ADDR);
  Wire.write(PWR_MGMT_1);
  Wire.write(0x00);
  Wire.endTransmission(true);
  return true; // TODO: check WHO_AM_I register
}

void IMU::update() {
  // TODO: read 14 bytes from ACCEL_XOUT_H, populate _ax _ay _az _gx _gy _gz
}

float IMU::getPitch() {
  // TODO: atan2 from accelerometer data
  return 0.0;
}

float IMU::getRoll() {
  // TODO: atan2 from accelerometer data
  return 0.0;
}

float IMU::getHeading() {
  // TODO: integrate gyro or fuse with magnetometer
  return 0.0;
}
