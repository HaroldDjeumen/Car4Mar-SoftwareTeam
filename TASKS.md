# TASKS — mosa-lgt_navigation

## Your Job
Implement GPS waypoint navigation, IMU heading reader, and path planner.

## Files To Create / Edit
- `pi/navigation/gps_reader.py` — GPSReader class
- `pi/navigation/waypoint.py` — Waypoint dataclass
- `pi/navigation/path_planner.py` — PathPlanner class
- `pi/navigation/imu_reader.py` — IMUReader class

## Tasks Checklist
- [ ] Waypoint dataclass: lat, lon, arrival_radius_m=2.0
- [ ] GPSReader.connect(port, baud) — open serial
- [ ] GPSReader.get_position() → (lat, lon) or None
- [ ] Use pynmea2 to parse NMEA sentences from NEO-6M
- [ ] IMUReader.connect() — I2C bus 1, address 0x68 (MPU-6050)
- [ ] IMUReader.get_heading() → degrees (0-360)
- [ ] IMUReader.get_tilt() → (pitch, roll) in degrees
- [ ] PathPlanner.add_waypoint(waypoint)
- [ ] PathPlanner.run() — main navigation loop
- [ ] PathPlanner.distance_to(current, target) — Haversine formula in metres
- [ ] PathPlanner.bearing_to(current, target) → degrees
- [ ] PathPlanner reads vision OBSTACLE signals before sending forward command
