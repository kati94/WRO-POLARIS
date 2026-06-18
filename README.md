# WRO FUTURE ENGINEERS 2026 - TEAM POLARIS

> An autonomous vehicle developed for the World Robot Olympiad (WRO) Future Engineers category, designed to navigate autonomously, complete three laps, avoid obstacles, and return to the starting area using sensor-based decision making and computer vision.

---

# Team Polaris

## Team Members

Walid Bouzarouata

  Lead Programmer

* Arduino Programming
* Sensor Integration
* Navigation Algorithms
* Testing and Calibration

Adam Saibi

  Mechanical & Electronics Engineer**

* 3D Design and Printing
* Chassis Assembly
* Wiring and Power Management
* Hardware Optimization

---

# Overview

Team Polaris developed a fully autonomous vehicle capable of navigating a WRO Future Engineers track without human intervention.

The robot uses an Arduino Uno as the main controller and combines multiple sensors to perceive its environment and make real-time decisions.

The vehicle is able to:

* Follow track boundaries
* Detect corners
* Count laps
* Detect obstacles
* Perform autonomous navigation
* Return to the starting area

The entire chassis was designed and manufactured using 3D printing technology.

---

# Repository Structure

## photos

Contains photographs of the robot from different angles:

* Front
* Rear
* Left
* Right
* Top
* Bottom

## video

Contains links to demonstration videos.

## schemes

Contains:

* Wiring diagrams
* Electrical schematics
* System architecture

## src

Contains all Arduino source code.

### Main Modules

* Motor Control
* Steering Control
* Ultrasonic Navigation
* MPU6050 Integration
* ESP32-CAM Vision System

## models

Contains STL files for all custom 3D printed parts.

## documentation

Contains engineering notes, testing results, and design explanations.

---

# Project Description

## Challenge

Develop a self-driving vehicle capable of completing the WRO Future Engineers challenges autonomously.

The robot must:

* Complete 3 laps
* Detect corners
* Avoid obstacles
* Adapt to clockwise and counter-clockwise directions
* Return to the starting area

---

# Hardware Used

## Arduino Uno

The Arduino Uno serves as the central controller responsible for:

* Sensor acquisition
* Motor control
* Steering management
* Navigation decisions

---

## HC-SR04 Ultrasonic Sensors

Three ultrasonic sensors are used for:

* Front obstacle detection
* Left wall detection
* Right wall detection

These sensors provide real-time distance measurements that allow the vehicle to navigate safely.

---

## MPU6050 Gyroscope and Accelerometer

The MPU6050 provides orientation data and helps:

* Maintain heading
* Improve turn accuracy
* Measure angular rotation

---

## ESP32-CAM

The ESP32-CAM is used for computer vision tasks including:

* Red obstacle detection
* Green obstacle detection
* Image processing
* Autonomous decision support

---

## MG90S Steering Servo

The steering system uses an MG90S servo motor.

Current steering calibration:

* Right Maximum = 0°
* Center = 80°
* Left Maximum = 150°

---

## DC Motors

The vehicle uses two DC gear motors:

* Front axle drive
* Rear axle drive

The motors provide sufficient torque for autonomous navigation and obstacle avoidance.

---

## Power System

The robot is powered using:

* Rechargeable AA battery pack
* External power bank for logic components

This configuration ensures stable power delivery for motors, sensors, and control electronics.

---

# Software

## Arduino IDE

The vehicle software is developed using Arduino IDE.

---

## Libraries Used

### Servo Library

Used for steering control.

### Wire Library

Used for I²C communication.

### MPU6050 Library

Used for orientation sensing.

### ESP32 Camera Library

Used for image acquisition and processing.

---

# Navigation Strategy

## Open Challenge

The robot:

1. Starts autonomously.
2. Detects the driving direction.
3. Follows track boundaries.
4. Detects corners.
5. Counts laps.
6. Completes three laps.
7. Returns to the starting area.

---

## Obstacle Challenge

The robot:

1. Detects red and green obstacles.
2. Determines the correct passing side.
3. Adjusts its trajectory.
4. Continues lap counting.
5. Completes the challenge autonomously.

---

# 3D Printed Components

Several custom components were designed and manufactured using 3D printing:

* Main chassis
* Sensor mounts
* Camera support
* Battery holder
* Electronic supports
* Steering assemblies

This approach reduced weight and allowed rapid prototyping and testing.

---

# Future Improvements

Planned improvements include:

* Enhanced vision processing
* Improved obstacle classification
* Sensor fusion algorithms
* More precise autonomous parking
* Faster lap completion times

---

# Videos

## Mobility Test

Demonstration of vehicle movement and steering.

## Open Challenge

Three autonomous laps on the official track.

## Obstacle Challenge

Obstacle detection and avoidance demonstration.

---

# Acknowledgments

We would like to thank:

* Our teachers and mentors
* Our school administration
* The WRO organization
* Our families for their support

---

# Team Polaris

**World Robot Olympiad – Future Engineers**

Morocco 🇲🇦

"Learning, Building, Innovating."
