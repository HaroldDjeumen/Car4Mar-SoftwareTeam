"""
MARS Rover Dashboard — Flask Web Server
Branch: master_comms
TODO (tumzamahlaks2004-ui): implement all routes
"""

from flask import Flask, render_template, request, jsonify
import sys
import os

sys.path.insert(0, os.path.join(os.path.dirname(__file__), '..'))

app = Flask(__name__)

# TODO: import and initialise SerialBridge from pi.serial_bridge
# bridge = SerialBridge()
# bridge.connect()

@app.route('/')
def index():
    # TODO: return render_template('index.html')
    return '<h1>M.A.R.S. Rover Control</h1><p>Dashboard not yet implemented.</p>'

@app.route('/command', methods=['POST'])
def command():
    # TODO: parse {"cmd": "F"} from request.json
    # TODO: call bridge.send_command(cmd)
    # TODO: return {"status": "ok", "cmd": cmd}
    data = request.get_json(silent=True) or {}
    cmd  = data.get('cmd', '')
    return jsonify(status='not_implemented', cmd=cmd)

@app.route('/telemetry')
def telemetry():
    # TODO: pull real values from battery monitor, GPS, ultrasonic
    return jsonify(
        battery_v   = 0.0,
        speed_pwm   = 0,
        gps_lat     = 0.0,
        gps_lon     = 0.0,
        obstacle_cm = 0,
        tracking    = False
    )

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000, debug=True)
