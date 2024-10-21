# Room Temperature Sensor with Distance Detection

This Arduino project integrates a room temperature sensor and an ultrasonic distance sensor to monitor both ambient temperature and proximity. When a person is detected within a defined range, the system displays a welcoming message along with the current room temperature.

## Features
- Measures room temperature using an analog temperature sensor.
- Detects proximity using an ultrasonic sensor (HC-SR04).
- Displays a personalized welcome message when a person is detected.
- Shows the room temperature on a 16x2 LCD screen.

## Components Used
- **Arduino Uno** (or compatible microcontroller)
- **HC-SR04 Ultrasonic Sensor**: Measures distance to determine if a person is nearby.
- **16x2 LCD Display**: Displays the temperature and welcome message.
- **Temperature Sensor** (e.g., LM35): Measures the room temperature.
- **Breadboard and Jumper Wires**: Connects the components.

## How It Works
This project uses an ultrasonic sensor to measure distance and an analog temperature sensor to measure the room temperature. When an object (such as a person) is detected within 10 inches, the LCD screen displays a personalized "Welcome Home Tim" message along with the current room temperature in Celsius. If no one is detected, the LCD shows "Standing by."

The primary components are:
- **Ultrasonic Sensor (HC-SR04)**: Emits an ultrasonic pulse and measures the time it takes to bounce back, allowing calculation of the distance.
- **Temperature Sensor**: Reads the analog voltage and converts it to a temperature value in Celsius.

## Project Images
![Arduino Setup](arduino-sensor.png)
![Arduino Video](arduino-sensor.mov)

## License
Feel free to use and modify this project for personal use.