# 🚀 Autonomous Robot Project - WRO Future Engineers

## 🎯 Project Objective
This project aims to build and program an autonomous robot using open-source hardware. The robot is designed to assess its environment using sensors and computer vision, enabling efficient navigation and challenge resolution along a predetermined path. Through planning, sensor integration, and optimal control strategies, the team seeks to improve its problem-solving, teamwork, and engineering development capabilities.

## 🔧 Components Used
Our robot is equipped with the following components:
- **Arduino board** – Main microcontroller to manage the sensors and motor control.
- **NXT motor** – Provides propulsion and movement control.
- **H-bridge** – Controls the direction and speed of the motor.
- **Ultrasonic sensors (x2)** – Detects obstacles and assists in navigation.
- **ESP32 with integrated camera** – Used for computer vision and trajectory analysis.
- **VL53L0X distance sensor** – Measures precise distances for obstacle avoidance.
- **Protoboard** – Used for wiring and connecting electronic components.

## 💻 Required Software
To compile and upload the code to the robot, you need:
- **Arduino IDE**: Development software for programming the Arduino board.
- **Necessary Libraries**:
- Libraries for the ultrasonic sensors.
- Libraries specific to the ESP32 camera.

## 🔌 Installation and Runtime Instructions
1. Download and install **Arduino IDE** from [arduino.cc](https://www.arduino.cc/).
2. Connect the Arduino board to the computer using a **USB cable**.
3. Install the necessary libraries in the Arduino IDE:
- Open **Arduino IDE**.
- Go to **Library Manager** and search for the corresponding libraries.
- Install the libraries and ensure they are loaded correctly.
4. Upload the source code to the Arduino board:
- Open the `.ino` file within the Arduino IDE.
- Select the correct port where the board is connected.
- Compile and upload the code to the board.
5. Verify the robot's functionality in walk tests.

## 📜 Documentation and Development
- The project's source code is located in this repository and is documented with explanatory comments.
- Images of the robot from different angles and photos of the participating team are included.
- The robot will be tested in different scenarios to validate its accuracy and stability in solving missions.
