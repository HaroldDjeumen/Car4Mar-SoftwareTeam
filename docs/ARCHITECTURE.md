# Car4Mar System Architecture

> Placeholder — fill in system block diagram here.

## High-Level Overview

```
[Pi Camera v3] [GPS NEO-6M] [MPU-6050 IMU]
       |               |            |
       └───────────────┴────────────┘
                       |
              [Raspberry Pi 4]
              (Python brain)
                       |  USB Serial (115200 baud)
                       |
             [Arduino Mega 2560]
             (Real-time controller)
                       |
       ┌───────────────┼───────────────┐
  [VNH5019 #1]   [VNH5019 #2]   [VNH5019 #3]
  FL + ML motor  FR + MR motor  RL + RR motor
```

## Communication Protocol
- Pi → Arduino: single ASCII characters (F/B/L/R/S/P/Q/+/-)
- Arduino → Pi: status strings (OK, ERR, DIST:xx)
