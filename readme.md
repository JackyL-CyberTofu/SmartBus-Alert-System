# SmartBus Alert System

The SmartBus Alert System is a dynamic notification platform designed to enhance public transit accessibility through real-time updates and personalized alert settings. Developed primarily in C for Embedded Linux systems, this project integrates with the Translink API to display real-time bus information on LCD screens and provides audio departure alerts for visually impaired users.

## Features

- **Real-Time Bus Updates**: Utilizes the Translink API to fetch and display real-time updates directly on an LCD display.
- **NFC Integration**: Personalized alert settings can be adjusted using NFC technology, enhancing user convenience and satisfaction.
- **Text-to-Speech**: Audio alerts for bus departures help ensure effective communication, especially for visually impaired users.
- **Multithreading**: Supports concurrent execution to handle real-time data processing efficiently.
- **Communication Protocols**: Implements I2C and SPI protocols for robust and efficient communication with LCD and NFC peripherals.

## Getting Started

### Prerequisites

- Embedded Linux platform (Beaglebone Green with Zen Cape, Debian)
- Adafruit 2.2" 18-bit color TFT LCD display with microSD card breakout - EYESPI Connector
- NXP PN532 V3 Kit Reader
- USB Audio Adapter with 3.5mm Speaker-Headphone
- Wireless USB adapter
- Joystick Buttons + External Button

### Setup

Compile the json parse
1. sudo dpkg --add-architecture armhf
2. sudo apt-get install libjson-c-dev
2. sudo apt-get install libjson-c-dev:armhf
3. sudo apt-get install libcurl4-openssl-dev:armhf
4. sudo apt-get install libnfc-dev:armhf
5. sudo apt-get install libnfc-bin:armhf
6. sudo apt-get install libnfc-examples:armhf
7. sudo apt-get install flite:armhf

### Demo Images

![PXL_20240412_101536334 RAW-01 COVER](https://github.com/JackyL-CyberTofu/SmartBus-Alert-System/assets/67818606/e5a52abe-1da4-43ef-9610-f9cb79b3d3e6)
![PXL_20240412_101447714 RAW-01 COVER](https://github.com/JackyL-CyberTofu/SmartBus-Alert-System/assets/67818606/92227552-183f-45a0-8816-0fb4d16f8736)
