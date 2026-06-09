# Your Branch: mosa-lgt_navigation

Welcome @mosa-lgt! You own GPS waypoint navigation and path planning.

## Your Role
You make the rover drive autonomously to GPS coordinates.
You combine GPS position, IMU heading, and vision signals to
decide which movement command to send at each moment.

## Files To Create / Edit
- `pi/navigation/gps_reader.py`  ← GPSReader class
- `pi/navigation/waypoint.py`  ← Waypoint dataclass
- `pi/navigation/path_planner.py`  ← PathPlanner class
- `pi/navigation/imu_reader.py`  ← IMUReader class

## What To Implement
1. **Waypoint dataclass** (waypoint.py)
   - `lat: float`, `lon: float`, `arrival_radius_m: float = 2.0`

2. **GPSReader class** (gps_reader.py)
   - `connect(port='/dev/ttyS0', baud=9600)`
   - `get_position()` → (lat, lon) tuple or None
   - Uses pynmea2 to parse NMEA sentences

3. **IMUReader class** (imu_reader.py)
   - `connect()` — open I2C bus 1, address 0x68 (MPU-6050)
   - `get_heading()` → degrees float (0-360)
   - `get_tilt()` → (pitch, roll) tuple in degrees
   - Uses smbus2 library

4. **PathPlanner class** (path_planner.py)
   - `__init__(serial_bridge, gps_reader, imu_reader, vision_detector)`
   - `add_waypoint(waypoint)`
   - `run()` — main loop: get position, calculate bearing to next waypoint,
     compare to heading, send F/L/R/S commands via serial_bridge
   - `distance_to(current, target)` → metres (Haversine formula)
   - `bearing_to(current, target)` → degrees

## How It Connects
- Calls Nkosinathi's `serial_bridge.send_command()` to move the rover
- Reads Maile-sudo's obstacle detector before moving forward
- GPS connects to Pi UART (/dev/ttyS0)
- IMU connects to Pi I2C bus 1

## How To Test
1. Test GPSReader outdoors with clear sky view
2. Test IMUReader: tilt the Pi, get_tilt() should reflect the angle
3. Test PathPlanner with a known waypoint 5 metres away

## Git Instructions
```bash
git add .
git commit -m "feat: implement GPS navigation and PathPlanner"
git push origin mosa-lgt_navigation
```
Then open a Pull Request → target branch: **master_pi_brain**

## Definition of Done
- [ ] GPSReader parses NMEA and returns lat/lon
- [ ] IMUReader returns tilt angles over I2C
- [ ] distance_to() Haversine formula is accurate within 1 metre
- [ ] PathPlanner sends F when heading toward waypoint
- [ ] PathPlanner sends L or R to correct heading drift
- [ ] PathPlanner sends S when within arrival_radius of waypoint
