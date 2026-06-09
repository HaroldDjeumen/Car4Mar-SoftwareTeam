# Your Branch: tumzamahlaks2004-ui_comms

Welcome @tumzamahlaks2004-ui! You own the WiFi web dashboard.

## Your Role
You build the browser-based control interface that lets anyone
on the same WiFi network drive the rover from their phone or laptop.
Your Flask app sits on the Pi and bridges the web UI to the Arduino.

## Files To Edit
- `pi/dashboard/app.py`  ← Flask server, implement all routes
- `pi/dashboard/templates/index.html`  ← control page UI
- `pi/dashboard/static/style.css`  ← styling

## What To Implement
1. **Flask app** (app.py)
   - Import SerialBridge from pi.serial_bridge
   - `GET /`  → render index.html
   - `POST /command`  → body: `{"cmd": "F"}` → calls bridge.send_command(cmd)
                      → returns `{"status": "ok", "cmd": cmd}`
   - `GET /telemetry`  → returns JSON:
     ```json
     {"battery_v": 0.0, "speed_pwm": 0, "gps_lat": 0.0, "gps_lon": 0.0, "obstacle_cm": 0, "tracking": false}
     ```
   - Run on host='0.0.0.0', port=5000

2. **index.html dashboard**
   - Title: "M.A.R.S. Rover Control"
   - D-pad control buttons: Forward (▲), Back (▼), Left (◀), Right (▶), Stop (■)
   - Speed slider: 0 to 220
   - Telemetry panel: battery voltage, GPS coords, obstacle distance
   - Each button sends POST /command with the right letter
   - Auto-refresh telemetry every 1 second via fetch()
   - Mobile-friendly layout (works on phone screen)

3. **style.css**
   - Dark theme background (#1a1a2e)
   - Buttons large enough to tap on mobile (min 60x60px)
   - Stop button in red
   - Telemetry values in a clear grid

## How It Connects
- Imports and uses Nkosinathi's SerialBridge to send commands to Arduino
- GET /telemetry will eventually pull data from mosa-lgt (GPS) and
  Mbu1310 (battery) — for now return placeholder values
- Accessible at http://[Pi-IP-address]:5000 from any browser on WiFi

## How To Test
1. Run: `python3 pi/dashboard/app.py`
2. Open browser to http://localhost:5000
3. Click Forward button — POST /command should send "F"
4. Check /telemetry returns valid JSON
5. Test on mobile browser — buttons must be tappable

## Git Instructions
```bash
git add .
git commit -m "feat: implement Flask dashboard with D-pad controls and telemetry"
git push origin tumzamahlaks2004-ui_comms
```
Then open a Pull Request → target branch: **master_comms**

## Definition of Done
- [ ] Flask server starts without errors
- [ ] GET / serves the control dashboard page
- [ ] All 5 D-pad buttons send correct commands to Arduino
- [ ] Speed slider works and updates rover speed
- [ ] GET /telemetry returns valid JSON
- [ ] Telemetry panel auto-refreshes every second
- [ ] Page works on mobile screen (no horizontal scroll)
- [ ] Stop button is clearly red and prominent
