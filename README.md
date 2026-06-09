# Branch: master_movement

## Purpose
This branch holds the Arduino Mega firmware for all 6-motor skid-steer drive
and the 4-servo Ackermann corner steering system.

## File Structure
```
arduino/
  MARS_Rover_Controller.ino   ← main firmware sketch
  config.h                    ← all pin and constant defines
```

## Hardware
- 6x DC gear motors via 3x VNH5019 dual-channel motor drivers
- 4x DS3218 corner steering servos
- Arduino Mega 2560 (USB serial at 115200 baud)

## Collaborator Branches (branch from here)
| Branch                    | Owner            | Task                      |
|---------------------------|------------------|---------------------------|
| sitholekendra61-rgb_movement | sitholekendra61 | Motor drive logic        |
| tttau28-ux_steering       | tttau28-ux       | Steering servo control    |

## How To Merge Back
1. Do your work on your collaborator branch
2. Open a Pull Request targeting **master_movement**
3. Request review before merging

## How To Merge master_movement → main
When all collaborator PRs are merged and tested:
```bash
git checkout main
git merge master_movement --no-ff -m "merge: master_movement into main"
git push origin main
```
