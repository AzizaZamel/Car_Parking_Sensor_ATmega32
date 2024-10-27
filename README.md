# Car Parking Sensor

## Overview
This project designs a car parking sensor system that helps drivers detect obstacles and avoid collisions by measuring the distance between the car and an obstacle using an ultrasonic sensor. The system displays the distance on an LCD, uses LEDs for proximity indication, and activates a buzzer when the object is too close.

## Features
- **Ultrasonic Distance Measurement**: Accurately measures the distance between the car and obstacles.
- **LCD Display**: Shows the distance to the nearest obstacle in real time.
- **LED Indicators**:
  - **All LEDs Flashing (Red, Green, Blue)**: Indicates distance ≤ 5 cm, buzzer sounds, and LCD shows "Stop."
  - **All LEDs ON (Red, Green, Blue)**: Indicates 6 cm ≤ Distance ≤ 10 cm, no buzzer.
  - **Red and Green LEDs ON**: Indicates 11 cm ≤ Distance ≤ 15 cm, Blue LED OFF.
  - **Only Red LED ON**: Indicates 16 cm ≤ Distance ≤ 20 cm, others OFF.
  - **All LEDs OFF**: Indicates Distance > 20 cm, buzzer OFF.
- **Buzzer Alert**: Sounds when the car is too close to an obstacle.
- **User-Friendly Interface**: Easy to understand and operate.

## Hardware Components
- **Microcontroller**: ATmega32
- **Sensors**:
  - **Ultrasonic Sensor (HC-SR04)**: Used for measuring distance.
- **Display**:
  - **LCD Display (16x2)**: Shows the measured distance.
- **LED Indicators**: As described above.
- **Buzzer**: Alerts when the distance is below a certain threshold.

## System Overview
The ATmega32 microcontroller receives signals from the ultrasonic sensor to measure the distance to obstacles. This distance is displayed on the LCD, while the LED indicators provide visual feedback. If the measured distance falls below a safe threshold, the buzzer will sound, alerting the driver to the proximity of an obstacle.
