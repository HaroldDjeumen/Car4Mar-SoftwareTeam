"""
MARS Rover — Raspberry Pi Main Entry Point
Branch: master_pi_brain
"""

import time
from serial_bridge import SerialBridge

SERIAL_PORT = '/dev/ttyACM0'
BAUD_RATE   = 115200

def main():
    bridge = SerialBridge(port=SERIAL_PORT, baud=BAUD_RATE)
    bridge.connect()

    print("MARS Rover Pi brain started. Waiting for commands...")

    try:
        while True:
            # TODO (Nkosinathi): command dispatch from navigation/vision goes here
            # TODO (mosa-lgt): call path_planner.run() here
            # TODO (Maile-sudo): call obstacle_detector.detect() here
            time.sleep(0.05)
    except KeyboardInterrupt:
        bridge.send_command('S')
        bridge.disconnect()
        print("Shutdown complete.")

if __name__ == '__main__':
    main()
