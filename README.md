# Branch: master_comms

## Purpose
WiFi web dashboard for browser-based rover control over the local network.

## File Structure
```
pi/dashboard/
  app.py              ← Flask web server
  templates/
    index.html        ← D-pad control UI
  static/
    style.css         ← dark mobile-friendly theme
```

## Collaborator Branches
| Branch                     | Owner              | Task               |
|----------------------------|--------------------|--------------------|
| tumzamahlaks2004-ui_comms  | tumzamahlaks2004-ui | Flask + HTML UI  |

## Running
```bash
pip install flask
python pi/dashboard/app.py
# Open http://[Pi-IP]:5000 in any browser on the same WiFi
```

## How To Merge Back
Open a Pull Request from your collaborator branch targeting **master_comms**.
