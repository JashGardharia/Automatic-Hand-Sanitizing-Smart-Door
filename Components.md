# Components Required
## Automatic Hand Sanitizing Door Handle System

This document lists all hardware components required to build the Automatic Hand Sanitizing Smart Door Handle System.

---

# 1. Microcontroller

- 1 × Arduino Uno

Purpose  
Acts as the central controller for the system. It processes keypad input, reads sensor data, and controls actuators such as servos, pump, and door lock.

---

# 2. Authentication System

- 1 × 4×4 Matrix Keypad

Purpose  
Used to enter the password required to unlock the door.

---

# 3. Door Lock Mechanism

Option A

- 1 × 12V Solenoid Door Lock

Option B

- 1 × High Torque Servo Motor (MG996R)

Purpose  
Locks or unlocks the door when the correct password is entered.

---

# 4. Door Detection Sensor

Choose one:

- 1 × IR Obstacle Sensor Module

or

- 1 × HC-SR04 Ultrasonic Sensor

Purpose  
Detects when the door opens so the sanitizing sequence can begin.

---

# 5. Sanitizer Dispensing System

Option A

- 1 × 5V Mini Liquid Pump
- 1 × Silicone Tube
- 1 × Sanitizer Bottle

Option B

- 1 × SG90 Servo Motor (used to press sanitizer bottle)

Purpose  
Dispenses sanitizer automatically when the door is used.

---

# 6. Door Handle Cleaning Mechanism

- 1 × MG996R Servo Motor
- Cleaning Sponge or Microfiber Pad
- Servo Arm / Mounting Bracket

Purpose  
Moves the cleaning pad around the door handle to sanitize it.

---

# 7. Control and Switching Components

- 1 × 5V Relay Module
- 1 × N-Channel MOSFET (IRFZ44N or similar)

Purpose  
Used to control higher power components like pumps and locks safely from the Arduino.

---

# 8. Indicators and Alerts

- 1 × Buzzer
- 1 × Green LED
- 1 × Red LED

Purpose  

Green LED → Access granted  
Red LED → Access denied  
Buzzer → Audio feedback for user input

---

# 9. Display (Optional)

- 1 × 16×2 LCD Display with I2C Module

Purpose  
Displays system messages such as password prompts and system status.

---

# 10. Power Supply System

- 1 × 12V 2A Power Adapter
- 1 × LM2596 Buck Converter

Purpose  
Provides stable power and converts voltage from 12V to 5V for electronics.

---

# 11. Mechanical Components

- Door handle mounting bracket
- Servo mounting brackets
- Sanitizer container holder
- Cleaning sponge or microfiber pad
- Screws and nuts
- Optional 3D printed enclosure

---

# 12. Basic Electronics

- Breadboard or PCB
- Jumper wires
- Resistors (220Ω, 1kΩ)
- Diodes (1N4007)
- Capacitors (100µF)

Purpose  
Used for circuit connections and electrical stability.

---

# Component Summary

| Category | Components |
|--------|-----------|
| Controller | Arduino Uno |
| Input | Matrix Keypad |
| Sensors | IR Sensor or Ultrasonic Sensor |
| Actuators | Servo Motors, Pump, Door Lock |
| Output | LEDs, Buzzer, LCD |
| Power | 12V Adapter, Buck Converter |
| Mechanical | Mounts, Sponge, Container |

---

# Notes

Ensure that all motors and pumps are powered using appropriate drivers or relay modules to prevent damage to the Arduino.
