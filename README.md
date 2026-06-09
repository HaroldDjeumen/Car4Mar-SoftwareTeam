# Car4Mar — Autonomous Rover

**Car4Mar** is a 6-wheel skid-steer autonomous rover designed for outdoor terrain navigation,
autonomous waypoint following, and solar-powered extended operation.

## Hardware

| Component              | Details                                    |
|------------------------|--------------------------------------------|
| High-level brain       | Raspberry Pi 4 (4GB RAM)                  |
| Movement controller    | Arduino Mega 2560                          |
| Drive motors           | 6x DC gear motors                          |
| Motor drivers          | 3x VNH5019 dual-channel motor drivers      |
| Corner steering        | 4x DS3218 servo (Ackermann geometry)       |
| Obstacle detection     | HC-SR04 ultrasonic sensor                  |
| IMU                    | MPU-6050 (I2C)                             |
| GPS                    | NEO-6M (UART)                              |
| Camera                 | Raspberry Pi Camera v3 (CSI)               |
| Solar tracking         | LDR sensors + pan/tilt servos              |
| Battery                | 6S LiPo 22.2V (30-40kg payload rated)     |

## Serial Command Reference

| Command | Action                        |
|---------|-------------------------------|
| F       | Drive forward                 |
| B       | Drive backward                |
| L       | Steer left                    |
| R       | Steer right                   |
| S       | Emergency stop                |
| P       | Pivot turn left               |
| Q       | Pivot turn right              |
| +       | Increase speed (+20 PWM)      |
| -       | Decrease speed (-20 PWM)      |
| T       | Enable solar tracking         |
| X       | Disable solar tracking / park |

## Branch Map

| Branch                        | Owner              | Parent Branch    | Purpose                              |
|-------------------------------|--------------------|------------------|--------------------------------------|
| main                          | HaroldDjeumen      | —                | Stable merged code                   |
| master_movement               | team               | main             | Arduino drive + steering firmware    |
| master_pi_brain               | team               | main             | Raspberry Pi Python code             |
| master_sensors                | team               | main             | Arduino sensor drivers               |
| master_comms                  | team               | main             | WiFi dashboard (Flask)               |
| master_power                  | team               | main             | Solar tracker + battery monitor      |
| sitholekendra61-rgb_movement  | sitholekendra61    | master_movement  | 6-motor drive logic implementation   |
| tttau28-ux_steering           | tttau28-ux         | master_movement  | Ackermann steering servo control     |
| Nkosinathi_pi_brain           | Nkosinathi         | master_pi_brain  | SerialBridge Pi↔Arduino comm         |
| Maile-sudo_vision             | Maile-sudo         | master_pi_brain  | OpenCV obstacle detection pipeline   |
| mosa-lgt_navigation           | mosa-lgt           | master_pi_brain  | GPS waypoint navigation + path plan  |
| segobits_sensors              | segobits           | master_sensors   | HC-SR04 ultrasonic sensor driver     |
| Mbu1310_power                 | Mbu1310            | master_power     | Solar tracker + battery monitor impl |
| tumzamahlaks2004-ui_comms     | tumzamahlaks2004-ui| master_comms     | Flask web dashboard UI               |

## Setup

### Clone the repo
```bash
git clone https://github.com/HaroldDjeumen/Car4Mar-SoftwareTeam.git
cd Car4Mar-SoftwareTeam
```

### Raspberry Pi setup
```bash
pip install -r requirements.txt
python pi/main.py
```

### Arduino setup
1. Open `arduino/MARS_Rover_Controller.ino` in Arduino IDE
2. Install libraries: `Servo` (built-in)
3. Select board: Arduino Mega 2560
4. Upload sketch
5. Open Serial Monitor at 115200 baud

### Web dashboard
```bash
python pi/dashboard/app.py
# Open http://[Pi-IP-address]:5000 in any browser on same WiFi
```

## Contributing

Each collaborator works on their own branch:
1. Check out your branch: `git checkout <your-branch-name>`
2. Read the `README.md` and `TASKS.md` in your branch
3. Implement the tasks
4. Commit and push: `git push origin <your-branch-name>`
5. Open a Pull Request targeting your **parent master branch** (not main)

## System Architecture

```
[Pi Camera v3] [GPS NEO-6M] [MPU-6050 IMU]
       |               |            |
       └───────────────┴────────────┘
                       |
              [Raspberry Pi 4]
              Python brain (main.py)
              ├── serial_bridge.py  →─────────────┐
              ├── navigation/                      │
              ├── vision/                          │ USB Serial
              ├── dashboard/ (Flask :5000)         │ 115200 baud
              └── power_manager.py                 │
                                                   ▼
                                        [Arduino Mega 2560]
                                        ├── MARS_Rover_Controller.ino
                                        ├── sensors/ultrasonic
                                        └── power/solar_tracker
                                                   |
                                   ┌───────────────┼───────────────┐
                              [VNH5019 #1]   [VNH5019 #2]   [VNH5019 #3]
                              FL + ML        FR + MR        RL + RR
```
