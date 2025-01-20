# Mobile Robot Control System
## Description
This project implements a control module for two DC motors mounted on a mobile robotic platform. The system integrates sensor feedback, a PID controller, and motor control to achieve obstacle avoidance and dynamic speed adjustment.

## Requirements

1. Ultrasonic Sensor:
    - Used for detecting obstacles in front of the platform.
    - The obstacle avoidance distance is configurable.

2. Position Control with PID:
    - A PID controller is used to maintain position stability.
    - The reference signal comes from an Ambient Light Sensor (ALS).
    - The same PID regulator is also used to dynamically adapt the speed.

3. Motor Control:
    - Controlled using an L293 motor driver.
    - PWM signals are generated via an internal microcontroller (MC) timer.

4. Display Information:
    - Robot states and operation steps are displayed on a Nokia LCD screen.

## Features

- Obstacle detection using ultrasonic sensors.
- PID-based position and speed control with real-time adjustments.
- Efficient motor control through PWM signals and a motor driver.
- Clear state updates displayed on a Nokia LCD for real-time feedback.
