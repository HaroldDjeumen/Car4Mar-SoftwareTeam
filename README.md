# Your Branch: Nkosinathi_pi_brain

Welcome @Nkosinathi! You own the Python serial bridge between the Pi and Arduino.

## Your Role
You build the communication backbone. Every movement command the Pi
brain sends to the Arduino passes through your SerialBridge class.
Without your code, the Raspberry Pi cannot control anything.

## Files To Edit
- `pi/serial_bridge.py`  ← main file, implement full class
- `pi/main.py`  ← wire up SerialBridge in the main loop

## What To Implement
SerialBridge class with:
1. `__init__(port='/dev/ttyACM0', baud=115200)`
2. `connect()` — open serial port, wait 2 seconds for Arduino reset
3. `disconnect()` — close port cleanly
4. `send_command(cmd: str)` — send single char, e.g. send_command('F')
5. `read_response() -> str` — read one line back from Arduino
6. `is_connected() -> bool`
7. `auto_reconnect()` — if port drops, retry every 3 seconds in background thread
8. A command queue using queue.Queue and threading.Thread so commands
   never block the main Pi navigation loop

## How It Connects
- Arduino listens on Serial0 (USB, /dev/ttyACM0 on Pi)
- Nkosinathi feeds commands → Maile-sudo (vision) and mosa-lgt (navigation)
  both call send_command() through your bridge
- tumzamahlaks2004-ui (dashboard) also calls send_command() via Flask POST

## How To Test
1. Connect Arduino Mega to Pi via USB
2. Upload any sketch that echoes serial back to confirm connection
3. Run:
```bash
python3 -c "from pi.serial_bridge import SerialBridge; b = SerialBridge(); b.connect(); b.send_command('F')"
```
4. Check Arduino serial monitor shows 'F' received

## Git Instructions
```bash
git add .
git commit -m "feat: implement SerialBridge class with threading and auto-reconnect"
git push origin Nkosinathi_pi_brain
```
Then open a Pull Request → target branch: **master_pi_brain**

## Definition of Done
- [ ] connect() opens serial port without errors
- [ ] send_command('F') sends F to Arduino
- [ ] auto_reconnect() retries on disconnect
- [ ] Command queue prevents blocking the main loop
- [ ] is_connected() returns correct state
- [ ] No import errors, passes basic unit test
