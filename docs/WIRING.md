# Car4Mar Wiring Reference

> Placeholder — add wiring diagrams and pin tables here.

## Arduino Mega Pin Assignment

| Function          | Pin(s)      | Type     |
|-------------------|-------------|----------|
| Motor PWM (×6)    | 2–7         | PWM Out  |
| Motor DIR (×12)   | 22–33       | Digital  |
| Servo corners (×4)| 44–47       | PWM Out  |
| Ultrasonic TRIG   | 48          | Digital  |
| Ultrasonic ECHO   | 49          | Digital  |
| Pan servo (solar) | 8           | PWM Out  |
| Tilt servo (solar)| 9           | PWM Out  |
| LDR sensors       | A0–A3       | Analog   |
| Battery voltage   | A8          | Analog   |
| I2C (IMU)         | SDA=20, SCL=21 | I2C  |

## Power Rail
- 6S LiPo 22.2V → BEC 5V → Servos + logic
- Arduino Vin (7–12V) from step-down converter
- Pi 5V from USB-C BEC
