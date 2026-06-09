"""
SerialBridge — Pi ↔ Arduino USB serial communication
Branch: master_pi_brain
TODO (Nkosinathi): implement the full SerialBridge class
"""

import serial
import time
import queue
import threading


class SerialBridge:
    def __init__(self, port='/dev/ttyACM0', baud=115200):
        self.port   = port
        self.baud   = baud
        self._ser   = None
        self._queue = queue.Queue()
        self._worker = None

    def connect(self):
        # TODO: open serial port, wait 2s for Arduino reset
        pass

    def disconnect(self):
        # TODO: close port cleanly
        pass

    def send_command(self, cmd: str):
        # TODO: send single char to Arduino
        pass

    def read_response(self) -> str:
        # TODO: read one line from Arduino
        return ''

    def is_connected(self) -> bool:
        # TODO: return True if serial port is open
        return False

    def auto_reconnect(self):
        # TODO: retry connection every 3 seconds in background thread
        pass
