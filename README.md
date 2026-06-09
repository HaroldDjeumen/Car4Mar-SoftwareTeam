# Branch: master_pi_brain

## Purpose
This branch holds all Raspberry Pi 4 Python code: serial bridge to Arduino,
camera vision pipeline, GPS navigation, and the web dashboard interface.

## File Structure
```
pi/
  main.py               ← entry point, wires all subsystems together
  serial_bridge.py      ← USB serial communication with Arduino
  power_manager.py      ← battery level monitoring
  navigation/
    __init__.py
    gps_reader.py       ← NEO-6M GPS via UART
    waypoint.py         ← Waypoint dataclass
    path_planner.py     ← autonomous waypoint navigation
    imu_reader.py       ← MPU-6050 over I2C
  vision/
    __init__.py
    camera.py           ← Pi Camera v3 capture
    obstacle_detector.py ← obstacle detection from camera frames
    object_classifier.py ← object recognition skeleton
  dashboard/
    app.py              ← Flask web server
    templates/
      index.html        ← control dashboard
    static/
      style.css
requirements.txt
```

## Collaborator Branches (branch from here)
| Branch                | Owner        | Task                        |
|-----------------------|--------------|-----------------------------|
| Nkosinathi_pi_brain   | Nkosinathi   | SerialBridge implementation |
| Maile-sudo_vision     | Maile-sudo   | OpenCV vision pipeline      |
| mosa-lgt_navigation   | mosa-lgt     | GPS + path planning         |

## Setup
```bash
cd pi/
pip install -r requirements.txt
python main.py
```

## How To Merge Back
Open a Pull Request from your collaborator branch targeting **master_pi_brain**.

## How To Merge master_pi_brain → main
```bash
git checkout main
git merge master_pi_brain --no-ff -m "merge: master_pi_brain into main"
git push origin main
```
