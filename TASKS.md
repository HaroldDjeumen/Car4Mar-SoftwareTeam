# TASKS — Maile-sudo_vision

## Your Job
Build the OpenCV camera pipeline: capture frames, detect obstacles, classify objects.

## Files To Create / Edit
- `pi/vision/camera.py` — Camera class
- `pi/vision/obstacle_detector.py` — ObstacleDetector class
- `pi/vision/object_classifier.py` — ObjectClassifier skeleton

## Tasks Checklist
- [ ] Camera.__init__(index, width, height)
- [ ] Camera.start() — open cv2.VideoCapture
- [ ] Camera.get_frame() — returns numpy BGR array
- [ ] Camera.stop() — release capture
- [ ] ObstacleDetector.detect(frame) — returns "CLEAR"/"STOP"/"OBSTACLE_LEFT"/"OBSTACLE_RIGHT"
- [ ] Use lower third of frame for close-range obstacle detection
- [ ] ObjectClassifier.classify(frame) — skeleton with TODO comments
- [ ] Test: camera opens, shows live feed, detect() responds to hand in front
- [ ] No OpenCV import errors on Raspberry Pi
