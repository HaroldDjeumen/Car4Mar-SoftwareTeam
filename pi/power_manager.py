"""
Pi Power Manager — battery level monitoring and low-power alerts
Branch: master_power
"""

import time

LOW_BATTERY_V = 18.0

class PowerManager:
    def __init__(self, serial_bridge=None):
        self._bridge = serial_bridge

    def check_battery(self) -> float:
        """Read battery voltage reported by Arduino. Returns float volts."""
        # TODO: read voltage from Arduino telemetry via serial_bridge
        return 0.0

    def is_low(self) -> bool:
        return self.check_battery() < LOW_BATTERY_V

    def run_monitor(self):
        """Background loop: alert if battery is low."""
        while True:
            if self.is_low():
                print("WARNING: Low battery!")
                if self._bridge and self._bridge.is_connected():
                    self._bridge.send_command('S')
            time.sleep(30)
