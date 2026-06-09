# Your Branch: Maile-sudo_vision

Welcome @Maile-sudo! You own the camera vision pipeline on the Raspberry Pi.

## Your Role
You process the live camera feed and tell the rover what it sees.
Your output is a navigation signal that the path planner uses to
decide whether to stop, go left, or go right.

## Files To Create / Edit
- `pi/vision/camera.py`  ← Camera class
- `pi/vision/obstacle_detector.py`  ← ObstacleDetector class
- `pi/vision/object_classifier.py`  ← ObjectClassifier skeleton

## What To Implement
1. **Camera class** (camera.py)
   - `__init__(index=0, width=640, height=480)`
   - `start()` — open cv2.VideoCapture
   - `get_frame()` → numpy array (BGR frame)
   - `stop()` — release capture

2. **ObstacleDetector class** (obstacle_detector.py)
   - `__init__(frame_width=640)`
   - `detect(frame)` → signal string
   - Returns one of: `"CLEAR"` / `"STOP"` / `"OBSTACLE_LEFT"` / `"OBSTACLE_RIGHT"`
   - Use HSV colour thresholding or contour detection on the lower
     third of the frame to detect close obstacles

3. **ObjectClassifier skeleton** (object_classifier.py)
   - `classify(frame)` → label string
   - Skeleton only — leave TODO comments for model loading later

## How It Connects
- mosa-lgt (navigation) calls detect() to decide if path is clear
- Your STOP signal triggers send_command('S') via Nkosinathi's bridge
- Camera connects to Pi CSI port (use cv2 index 0)

## How To Test
1. Connect Pi Camera v3 to CSI port
2. Run: `python3 pi/vision/camera.py`
3. Should open a window showing live camera feed
4. Hold an object in front — detect() should return STOP or OBSTACLE

## Git Instructions
```bash
git add .
git commit -m "feat: implement Camera class and ObstacleDetector pipeline"
git push origin Maile-sudo_vision
```
Then open a Pull Request → target branch: **master_pi_brain**

## Definition of Done
- [ ] Camera opens and captures frames without errors
- [ ] detect() returns CLEAR when path is open
- [ ] detect() returns STOP when obstacle is close and centred
- [ ] detect() returns OBSTACLE_LEFT or OBSTACLE_RIGHT for side obstacles
- [ ] stop() releases camera cleanly
- [ ] No OpenCV import errors on Raspberry Pi
