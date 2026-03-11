# Automatic Hand Sanitizing Smart Door System

An embedded system that unlocks a door using a keypad password and automatically sanitizes the door handle after use.

## Overview
This project improves hygiene in shared environments by combining a password-protected door lock with an automated sanitization mechanism.

Once the correct password is entered through a matrix keypad, the door unlocks. After the door is opened and closed, the system waits for 10 seconds and then activates a sanitizing spray while servo motors clean the door handle.

## Features

- Password protected door access
- IR sensor door detection
- Automatic sanitizing spray
- Servo-based handle cleaning mechanism
- Adjustable sanitizing delay
- Microcontroller-based automation

## Components Used

- Arduino Nano / Arduino Uno
- 4x4 Matrix Keypad
- IR Sensor
- Servo Motors (SG90)
- Sanitizing Spray Pump
- Relay Module
- Power Supply
- Door Lock Solenoid

## Working Principle

1. User enters password through keypad.
2. If password is correct, the door lock opens.
3. IR sensor detects door movement.
4. After 10 seconds, the sanitizing pump sprays disinfectant.
5. Servo motors rotate to wipe/clean the door handle.

## Applications

- Hospitals
- Schools
- Public buildings
- Offices
- Smart homes

## Future Improvements

- WiFi control using ESP32
- Mobile app unlock
- Face recognition access
- Usage data logging

# Project Difficulty: Intermediate Embedded System

# Development Time: 2 weeks

## Author

Embedded Systems Project by #Jash.