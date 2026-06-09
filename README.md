# Branch: master_power

## Purpose
Battery voltage monitoring for the rover.

## File Structure
```
arduino/power/
  battery_monitor.h    ← inline BatteryMonitor class
pi/
  power_manager.py     ← Pi-side battery alert
```

## Collaborator Branches
| Branch         | Owner    | Task                          |
|----------------|----------|-------------------------------|
| Mbu1310_power  | Mbu1310  | Battery voltage monitor impl  |

## Hardware
- Voltage divider (100kΩ + 10kΩ) on A8 for 6S LiPo reading

## How To Merge Back
Open a Pull Request from your collaborator branch targeting **master_power**.
