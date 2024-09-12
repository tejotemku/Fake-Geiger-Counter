# Fake Geiger Counter
Esp32 based simple fake geiger counter intended for larping.

This repository contains: 
1. C++ code for esp32
2. Project files for platformio
3. 3D printable models of container (in few parts) with holes for the esp32 microcontroler and all used sensors
4. Instruction on how to setup the fake geiger counter

## Table of Contents

- [ESP32 and used parts](#esp32-and-used-parts)
  - [Parts](#parts)
  - [Configuration](#configuration)  
    - [Potentiometer](#potentiometer)
    - [Diode](#diode)
    - [Servo motor](#servo-motor)
    - [PAM8302 Amplifier to ESP32](#pam8302-amplifier-to-esp32)
    - [Speaker to PAM8302 Amplifier](#speaker-to-pam8302-amplifier)
- [Code setup](#code-setup)
- [Geiger counter sound](#geiger-counter-sound)
- [3D model](#3d-model)

## ESP32 and used parts
#### Parts
- ESP32
- Breadbord
- Potentiometer
- Speaker
- Amplifier
- Diode
- Connecting cables
- Servomotor

<details>
  <summary style="font-size: 12px">Links to parts I used </summary>

- [ESP32 WROOM](https://botland.store/esp32-wifi-and-bt-modules/8893-esp32-wifi-bt-42-platform-with-module-5904422337438.html)
- [Breadbord](https://botland.store/breadoards/19943-breadboard-justpi-830-holes-5904422328610.html)
- [Potentiometer DFRobot Gravity](https://botland.store/gravity-encoders-and-potentiometers/11258-dfrobot-gravity-54k-slide-potentiometer-6959420901036.html)
- [Speaker](https://botland.store/analog-speakers/19458-mini-oval-speaker-1w-8ohm-30x20x5mm-adafruit-4227-5904422354848.html)
- [PAM8302 Amplifier Adafruit](https://botland.store/mp3-wav-ogg-midi-players/6381-mono-25w-class-d-audio-amplifier-pam8302-adafruit-2130-5904422348960.html)
- [Diodes](https://botland.store/leds/19985-set-of-5mm-leds-justpi-30pcs-5904422329259.html)
- [Short connecting cables](https://botland.store/male-to-male-connecting-cables/19947-connecting-cables-male-male-justpi-10cm-40pcs-5904422328689.html)
- [Servomotor](https://botland.store/micro-servos/13128-servo-sg-90-micro-180-5904422350338.html)

</details>

ESP32 can be easily powered by a powerbank to be portable.

#### Configuration
Connect peripherals to esp using connecting cables and breadboard
###### Potentiometer

|Part Pin|ESP32 Pin|
|-------|---------|
|  VIN ($${\color{red}red}$$)  |  3V3    |
|  GND/VOUT (ussually $${\color{black}black}$$ or $${\color{brown}brown}$$)  |  GND    |
|  Data (often $${\color{blue}blue}$$)  |  D15 or any other ADC (Analog-to-Digital Converter) pin    |

###### Diode

| Diode legs |ESP32 Pin|
|-------|---------|
|  Short leg |  GND    |
|  Long leg  |  D22 or any other free data pin  |

###### Servo motor

|Part Pin|ESP32 Pin|
|-------|---------|
|  VIN ($${\color{red}red}$$)  |  3V3    |
| GND/VOUT (ussually $${\color{black}black}$$ or $${\color{brown}brown}$$)  |  GND    |
|  Data (often $${\color{orange}orange}$$)  |  D18 or any other free data pin    |

###### PAM8302 Amplifier to ESP32

|Part Pin|ESP32 Pin|
|-------|---------|
|  VIN  |  3V3    |
| GND   |  GND    |
| A+  |  D23 or any other free data pin    |
| A-  |  GND   |
| SD  |  Unused in this project, leave unconnected  |

###### Speaker to PAM8302 Amplifier

|Speaker Pin|PAM8302 Pin|
|-------|---------|
|  $${\color{red}red}$$  |  +    |
| $${\color{black}black}$$  |  -    |


Example [ESP32 Wroom PINout diagram](https://lastminuteengineers.com/wp-content/uploads/iot/ESP32-Pinout.png) - while order and placement on the controller are not always the same between manufacturers, pin technologies and characteristics will.

## Code setup
The code itself does not need any changes other than seting correct pins to potentiometer, speaker, diode and servo motor. It can be easily built and uploaded to ESP32 using [Platformio extension for VsCode](https://platformio.org/install/ide?install=vscode). Quick tutorial on how to use it from [Dave's Garage YT channel](https://youtu.be/XLQa1sX9KIk?si=jZ_BQljqpmHXpXcT&t=441). Once uploaded the code will run automatically every time when powered on by a charging cable or a powerbank. It does not need to be connected to a computer to work.

## Geiger counter sound
Speaker will emit clicks based on potentiometer's input value. The higher the value, the higher the click volume range and the frequency of click. Algorithm inspired by this [youtube video](https://youtu.be/d4pHbYvz6tU?si=e8RVInphm-453VID).

This code, in it's current state, generates simple speaker clicks so they will sound a little bit digital.

## 3D Model
3D model had been created for the [linked parts](#esp32-and-used-parts). It has speaker holes for sound transmission on the side, hole for a diode and a servomotor dial and it's screws on the front. On the bottom it has a hole through with power cable can be connected to esp32. It is ment to be a base for holding the esp32 parts, that can be customized. You can add some buttons and other gizmos as you please.
