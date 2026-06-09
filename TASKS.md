# TASKS — Nkosinathi_pi_brain

## Your Job
Implement the Python SerialBridge class for Pi ↔ Arduino communication.

## Files To Edit
- `pi/serial_bridge.py` — implement the full SerialBridge class
- `pi/main.py` — wire up SerialBridge in the main loop

## Tasks Checklist
- [ ] `__init__(port, baud)` — store port and baud, create queue and thread
- [ ] `connect()` — open serial.Serial, sleep 2s for Arduino reset
- [ ] `disconnect()` — close port cleanly
- [ ] `send_command(cmd: str)` — encode and write single char
- [ ] `read_response() -> str` — readline() and decode
- [ ] `is_connected() -> bool` — check if serial port is open
- [ ] `auto_reconnect()` — background thread, retry every 3s on disconnect
- [ ] Command queue using queue.Queue + threading.Thread
- [ ] Wire up in main.py (bridge.connect() + bridge.send_command())
- [ ] Test with Arduino connected: send 'F', verify Arduino receives it
