# Branch: master_power

## Purpose
Solar panel tracking system and battery voltage monitoring.

## File Structure
```
arduino/power/
  solar_tracker.h      ← SolarTracker class declaration
  solar_tracker.cpp    ← implementation (TODO: Mbu1310)
  battery_monitor.h    ← inline BatteryMonitor class
pi/
  power_manager.py     ← Pi-side battery alert
```

## Collaborator Branches
| Branch         | Owner    | Task                                  |
|----------------|----------|---------------------------------------|
| Mbu1310_power  | Mbu1310  | Solar tracker + battery monitor impl  |

## Hardware
- 4x LDR sensors on A0–A3
- Pan servo on pin 8, tilt servo on pin 9
- Voltage divider (100kΩ + 10kΩ) on A8 for 6S LiPo reading

## How To Merge Back
Open a Pull Request from your collaborator branch targeting **master_power**.
