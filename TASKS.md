# TASKS — tumzamahlaks2004-ui_comms

## Your Job
Implement the Flask web dashboard for WiFi-based rover control.

## Files To Edit
- `pi/dashboard/app.py` — implement all Flask routes
- `pi/dashboard/templates/index.html` — build the control UI
- `pi/dashboard/static/style.css` — dark mobile-friendly theme

## Tasks Checklist
- [ ] app.py: import SerialBridge and connect to Arduino
- [ ] GET / → render index.html
- [ ] POST /command → receive {"cmd": "F"}, call bridge.send_command(), return {"status":"ok","cmd":cmd}
- [ ] GET /telemetry → return JSON with battery_v, speed_pwm, gps_lat, gps_lon, obstacle_cm
- [ ] Run Flask on host='0.0.0.0', port=5000
- [ ] index.html: 5 D-pad buttons (F/B/L/R/S)
- [ ] index.html: speed slider 0-220
- [ ] index.html: telemetry panel (battery, GPS, obstacle, speed)
- [ ] Auto-refresh telemetry every 1 second with fetch()
- [ ] Mobile-friendly layout (no horizontal scroll on phone)
- [ ] Stop button clearly red and prominent
- [ ] Test: python3 pi/dashboard/app.py → open localhost:5000 in browser
