# Hardware Programmer Assignment

A PlatformIO-based ESP32 project that uses an MPU6050 sensor to detect tilt and visually indicate orientation with four LEDs.

## Overview

This project turns an ESP32 DevKit V1 into a simple tilt/angle indicator. It reads acceleration data from the MPU6050, calculates roll and pitch angles, and lights up LEDs depending on the direction of tilt.

The system is designed to detect whether the board is tilted:
- Right
- Left
- Front
- Back

The logic uses a 15 degree threshold to activate each LED.

## Hardware

- ESP32 DOIT DevKit V1
- MPU6050 6-axis motion sensor
- 4 LEDs connected to the ESP32 GPIO pins

### Pin mapping

| Component | GPIO |
| --- | --- |
| Right LED | 15 |
| Left LED | 2 |
| Back LED | 4 |
| Front LED | 5 |
| MPU6050 SDA | 21 |
| MPU6050 SCL | 22 |

## Software stack

- PlatformIO
- ESP32 platform: `espressif32@6.10.0`
- Framework: Arduino
- Sensor library: `Adafruit MPU6050`

## Project structure

```text
CobAaja/
├── include/
│   ├── LEDController.h
│   ├── MPU6050Manager.h
│   └── Orientation.h
├── src/
│   ├── LEDController.cpp
│   ├── MPU6050Manager.cpp
│   ├── Orientation.cpp
│   └── main.cpp
├── .gitignore
├── platformio.ini
└── README.md
```

## How it works

1. The ESP32 initializes I2C communication with the MPU6050.
2. The sensor reports acceleration values on the X, Y, and Z axes.
3. The application computes roll and pitch using trigonometric calculations.
4. Each LED is activated based on the direction and magnitude of the tilt.
5. Sensor readings and computed angles are printed to the serial monitor for debugging.

## Build and upload

### Requirements

- VS Code
- PlatformIO extension
- USB cable connected to the ESP32

### Commands

```bash
pio run
pio run -t upload
pio device monitor
```

Or use the PlatformIO VS Code tasks or toolbar commands.

## Serial monitor

The project initializes the serial monitor at:

```text
115200 baud
```

It prints sensor values such as:

```text
AX: ... | AY: ... | AZ: ...
Roll: ... deg | Pitch: ... deg
```

## Notes

- The project halts with an infinite loop if the MPU6050 is not detected.
- The LEDs are tested at startup for 500 ms before normal operation begins.
- The threshold is set to `15.0` degrees, so small tilts do not trigger the indicator.

## License

This project is intended for educational and prototype use.
