<h1 align="center"> Autonomous Robot Project for WRO - Future Engineers Category </h1>

<p align="center"> <img src="https://github.com/DexterTaha/WRO-2024-FUTURE-ENGINEERS/assets/130682580/d9385136-f971-4c95-ba80-ffc14f7c0a4e" alt="banner" width="1500"> </p>

<br>
<h1 align="center"> World Robot Olympiad </h1>

<p align="center"> <img src="https://www.wroguatemala.org/wp-content/uploads/2023/07/Sticker_100x1006.png" width="300"> </p>
<br>

The World Robot Olympiad (WRO) is a prestigious international robotics competition that stimulates the imagination of students worldwide. It challenges participants to demonstrate their creativity, problem-solving skills, and technical expertise in designing and programming robots for various tasks and challenges.

One of the most dynamic categories in WRO is Future Engineers. In this category, participants are tasked with developing innovative solutions to real-world problems using robotics and automation. This category serves as a breeding ground for future innovators, encouraging critical and creative thinking among students, laying the foundation for a new generation of engineers and technologists.

This year, the Future Engineers category presents an exciting challenge: creating an autonomous car. This challenge pushes participants to explore cutting-edge robotics, adding complexity and innovation to an already thrilling competition.

# 📁 Repository Structure

| Directory      | Type       | Description | Required |
|----------------|------------|-------------|-----------|
| **/t-photos**  | 📸 Photos   | - 1 official team photo (`team_official.jpg`)<br>- 1 informal group photo (`team_fun.jpg`) | ✅ Required |
| **/v-photos**  | 🖼️ Photos  | - 6 technical views of the robot (front, side, rear, top, bottom, detail)<br>- Minimum resolution: 1920x1080<br>- Format: `robot_[angle].jpg` | ✅ Required |
| **/video**     | 🎥 Multimedia | `video.md` file containing:<br>- YouTube link (public/unlisted)<br>- Minimum 30-second demonstration<br>- Must show autonomous navigation | ✅ Required |
| **/schemes**   | 📐 Diagrams | Diagrams in JPEG/PNG/PDF of:<br>- Electronic schematic<br>- Wiring connections<br>- Mechanical layout | ✅ Required |
| **/src**       | 💻 Code  | Recommended structure:<br>- `/firmware` (Arduino/ESP32 code)<br>- `/vision` (image processing)<br>- `/docs` (technical manuals) | ✅ Required |
| **/models**    | 🖨️ 3D/CNC | Optional files:<br>- Formats: STL, DXF, STEP<br>- Organized by component | ❌ Optional |
| **/other**     | 📄 Extra   | Additional documentation:<br>- Communication protocols<br>- Technical specifications<br>- Calibration guides | ❌ Optional |

## Project Objective
The objective of this project is to design, build, and program an autonomous robot using open-source hardware, sensor-based decision making, and adaptive movement algorithms. Our robot dynamically analyzes its environment through integrated processing and sensor feedback, ensuring efficient navigation while autonomously overcoming obstacles.

Main objectives:
* Strengthen problem-solving and teamwork in real-world engineering
* Implement sensor-based motion control for precise navigation
* Develop an optimized autonomous driving strategy for robotics challenges
* Contribute to open-source robotics by documenting our solution for future teams

## Components Used

Our robot is built with precision hardware to ensure stability, responsiveness, and energy optimization.

<table>
  <tr>
    <th width="150">Component</th>
    <th>Image</th>
    <th>Technical Description</th>
  </tr>
  
  <tr>
    <td><strong>Arduino Uno</strong></td>
    <td><img src="https://www.videoycomputacion.com.ve/5808-large_default/arduino-uno-r3-atmega-dip-328p-chip-grde.jpg" width="120" alt="Arduino Uno"></td>
    <td>Main microcontroller managing sensor input (I2C, digital) and motion control (PWM).<br>
    <em>Specifications:</em> ATmega328P, 16MHz, 32KB flash, 14 digital I/O</td>
  </tr>

  <tr>
    <td><strong>L298N H-Bridge</strong></td>
    <td><img src="https://acdn-us.mitiendanube.com/stores/975/836/products/17637-mla20140879523_082014-o-8f0828cf82de8cee6415565106613680-480-0.jpg" width="120" alt="L298N H-Bridge"></td>
    <td>Dual-channel motor controller for direction and speed.<br>
    <em>Specifications:</em><br>
    • Logic voltage: 5V<br>
    • Motor voltage: +5V to +35V<br>
    • Peak current: 2A per channel<br>
    • Maximum power: 25W<br>
    • Protection: Built-in suppression diodes<br>
    <em>Arduino connection:</em><br>
    • ENA/ENB → PWM pins (speed)<br>
    • IN1/IN2 → Digital pins (direction)<br>
    • +12V → External 9V source<br>
    <em>Project use:</em> Bidirectional control of NXT motor</td>
  </tr>

<tr>
  <td><strong>DC Motor with Gearbox</strong></td>
  <td><img src="https://robot.com.ve/wp-content/uploads/2021/08/Motorreductor-con-caja-reductora-6V-1-48-1.jpg" width="120" alt="DC Motor"></td>
  <td>Compact brushed DC motor with built-in gear reduction system.<br>
  <em>Specifications:</em><br>
  • Voltage: 6–12V DC<br>
  • Gear ratio: varies by model (e.g., 48:1)<br>
  • Shaft: 6mm D-type<br>
  • Torque and speed optimized for robotic applications<br>
  <em>Wiring:</em> Two terminal leads (red: +, black: -) for connection to an L298N driver or similar H-bridge controller</td>
</tr>
  
  <tr>
    <td><strong>ESP32-WROOM-32D</strong></td>
    <td><img src="http://wiztech.com.ua/wp-content/uploads/2024/04/ESP32-wroom-32D.webp" width="120" alt="ESP32-WROOM-32D"></td>
    <td>Wi-Fi/Bluetooth MCU for IoT and embedded systems.<br>
    <em>Capabilities:</em> Dual-core 240MHz, 4MB Flash, 520KB SRAM, 802.11 b/g/n Wi-Fi, Bluetooth 4.2, low-power modes.</td>
  </tr>

  <tr>
    <td><strong>VL53L0X Sensors</strong></td>
    <td><img src="https://naylampmechatronics.com/1620-superlarge_default/sensor-vl53l0x-de-tof.jpg" width="120" alt="VL53L0X"></td>
    <td>Time-of-Flight (ToF) sensor for obstacle detection.<br>
    <em>Range:</em> 50-1200mm, ±3% accuracy, I2C interface</td>
  </tr>

  <tr>
    <td><strong>Breadboard</strong></td>
    <td><img src="https://eloctavobit.com/imagenes/2023/06/64799b86081a2.webp" width="120" alt="Breadboard"></td>
    <td>Prototyping platform for quick interconnections.<br>
    <em>Configuration:</em> 830 points, power bus distribution</td>
  </tr>

  <tr>
    <td><strong>Voltage Regulators</strong></td>
    <td><img src="https://robot.com.ve/wp-content/uploads/2021/08/AR0202-lm317-_v1.jpg" width="120" alt="LM7805 Regulator"></td>
    <td>Power management system.<br>
    <em>Specifications:</em> LM7805 (5V, 1A), LM1117 (3.3V), with heat sinks</td>
  </tr>

  <tr>
    <td><strong>SG90 Servomotor</strong></td>
    <td><img src="https://www.aranacorp.com/wp-content/uploads/towerpro-servo-sg90.jpg" width="120" alt="SG90 Servo"></td>
    <td>Direction control and auxiliary mechanisms.<br>
    <em>Specifications:</em> 4.8-6V, 180° rotation, 1.8kg/cm torque</td>
  </tr>

  <tr>
    <td><strong>Pixy2 Camera</strong></td>
    <td><img src="https://m.media-amazon.com/images/I/71ciGcchSaL.jpg" width="120" alt="Pixy2 Camera"></td>
    <td>Embedded vision system for color-based object detection.<br>
    <em>Specifications:</em><br>
    • Dual-core NXP LPC4330 processor (200MHz)<br>
    • Resolution: 1296x976 (RAW), 316x208 (processed)<br>
    • Color signatures: 7 simultaneous detections<br>
    • Interfaces: SPI, I2C, UART, USB<br>
    • Power consumption: 140mA @ 5V<br>
    <em>Connection:</em> SPI (recommended) + 5V power supply<br>
    <em>Project use:</em> Target detection through color codes (signatures 3 & 4)</td>
  </tr>
</table>


## Sensor Processing and Autonomous Navigation
The VL53L0X sensor plays a crucial role in obstacle detection, allowing the robot to measure distance in real time and adjust its movement accordingly. The robot follows a sensor-driven motion algorithm, continuously refining motor speed and navigation logic.

* Obstacle detection: The distance sensor identifies objects and dynamically adjusts the robot's path
* ESP32 camera input: Processes real-time images for terrain analysis and movement decisions
* Motor control logic: The Arduino Uno manages speed control through PWM signals and servo adjustments

## Required Software and Development Tools
Programming and compilation tools:
* Arduino IDE - Used for coding, compiling and uploading firmware
* Tinkercad - Virtual electronics simulation tool for circuit prototyping

Essential libraries:
* Wire.h - Supports sensor communication and data collection
* Adafruit_VL53L0X.h - Controls distance measurement operations
* Servo.h - Manages servo motor positioning and feedback control

## Installation and Operation Instructions
How to deploy the robot firmware:
1. Download Arduino IDE and install all necessary board drivers
2. Connect Arduino Uno via USB and verify IDE recognition
3. Install all required libraries (VL53L0X, Servo, Wire, Adafruit Motor Control)
4. Compile and upload firmware, initializing sensor motion algorithms
5. Test sensor performance using Serial Monitor readings
6. Run autonomous navigation tests and fine-tune movement responses

## Diagnostics and Evaluation
Performance validation tests:
* Sensor accuracy test: Confirms obstacle detection reliability and distance precision
* Motor speed calibration: Ensures smooth motion transitions and speed adjustments
* Servo alignment: Evaluates response time and angle precision for additional motion control
* Camera-based navigation: Assesses terrain recognition and edge detection capabilities

## Competitive Strategy and Adaptability
Our robot is designed to react dynamically in competition environments, ensuring maximum precision and adaptability:

* Real-time sensor data: The robot instantly adjusts movement based on incoming distance measurements
* Vision-based edge detection: The ESP32 processes camera input to determine safe paths and avoid barriers
* Energy-efficient motion management: Reduces unnecessary movement to optimize navigation cycles
* Configurable control logic: Adjusts servo responsiveness and motor calibration as needed

## Future Development and Contribution
Our long-term vision for the project includes:

* Expanding servo control capabilities for more precise motion adjustments
* Optimizing ESP32 vision-based object tracking for advanced competition scenarios
* Developing smart battery management strategies to improve longevity and operational efficiency
* Publishing open-source documentation on sensor-based autonomous navigation solutions
