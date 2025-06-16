## 🚀 Autonomous Robot Project for WRO – Future Engineers Category


## 🎯 Project Objective
The goal of this project is to design, build, and program an autonomous robot using open-source hardware, sensor-driven decision-making, and adaptive movement algorithms. Our robot dynamically analyzes its environment through embedded processing and sensor feedback, ensuring efficient navigation while overcoming obstacles autonomously.

Primary Objectives:
- Strengthen problem-solving and teamwork in real-world engineering.
- Apply sensor-based movement control for precise navigation.
- Develop an optimized, autonomous driving strategy for robotics challenges.
- Contribute to open-source robotics by documenting our solution for future teams.


## 🔹 Who We Are
We are a team from Instituto Técnico Jesús Obrero (ITJO) in Venezuela, passionate about robotics and automation.
Team Members:
- José Lapeira – Expert in embedded programming, electronic systems, and software development.
- Keiner Duran – Specializes in algorithm optimization, robotics AI integration, and movement logic design.
- Mauricio Sánchez – Focused on Arduino firmware, motor control, and electronics applications.


## 🔧 Components Used
Our robot is built using precision hardware to ensure stability, responsiveness, and automation.
Key Electronics & Hardware:
- Arduino Uno – Main microcontroller handling sensor input and motion control.
- NXT Motor & H-Bridge – Provides precise movement and speed adjustments.
- ESP32 with Integrated Camera – Enables real-time object detection and navigation algorithms.
- VL53L0X Distance Sensor – Supports high-accuracy obstacle detection and movement corrections.
- Protoboard & Wiring System – Ensures structured electrical connections and component stability.
- Voltage Regulators – Maintain consistent power distribution across the robot’s systems.
- Servo Motor – Provides additional motion control and interactive functionalities.

Sensor Processing and Autonomous Navigation
The VL53L0X sensor plays a crucial role in obstacle detection, allowing the robot to measure distance in real time and adjust its movement accordingly. The robot follows a sensor-driven movement algorithm, continuously refining its motor speed and navigation logic.
- Obstacle Detection: The distance sensor identifies objects and dynamically adjusts the robot’s path.
- ESP32-Based Camera Input: Processes real-time images for terrain analysis and movement decisions.
- Motor Control Logic: The Arduino Uno manages speed control using PWM signals and servo adjustments.


## Measure
- _Width: 18 centimeters._
- _Length: 26 centimeters_


## 💻 Required Software & Development Tools

Programming & Compilation Tools:
- Arduino IDE – Used for coding, compiling, and uploading firmware.
- Tinkercad - 

Essential Libraries:
- Wire.h – Supports sensor communication and data collection.
- Adafruit_VL53L0X.h – Controls distance measurement operations.
- Servo.h – Manages servo motor positioning and control feedback.


## 🔌 Installation and Runtime Instructions
How to Deploy the Robot's Firmware:
- Download Arduino IDE and install all required board drivers.
- Connect the Arduino Uno via USB and ensure proper recognition in the IDE.
- Install all necessary libraries (VL53L0X, Servo, Wire, Adafruit Motor Control).
- Compile and upload the firmware, initializing sensor-driven movement algorithms.
- Test distance sensor performance using Serial Monitor readings.
- Run autonomous navigation trials and fine-tune movement responses.


## 🏆 Testing & Evaluation
Performance Validation Tests:
- Sensor Precision Test: Confirms reliable obstacle detection and distance accuracy.
- Motor Speed Calibration: Ensures smooth movement transitions and speed adjustments.
- Servo Motor Alignment: Evaluates reaction time and angle precision for additional motion handling.
- Camera-Based Navigation: Assesses real-time terrain recognition and edge detection capabilities.

⚙ Competitive Strategy and Adaptability
Our robot is designed to react dynamically in competition settings, ensuring maximum precision and adaptability:
- Real-Time Sensor Feedback: The robot adjusts movement instantly based on incoming distance measurements.
- Vision-Based Edge Detection: The ESP32 processes camera input, determining safe paths and barrier avoidance.
- Energy-Efficient Motion Handling: Reduces excess movement waste for optimized navigation cycles.
- Configurable Control Logic: Adjusts servo responsiveness and motor calibration as needed.
  
Extended Competitive Approach
In a robotics competition, autonomous movement must be fast, reactive, and strategic. Our robot integrates:
- Trajectory Adjustment Algorithms: The system learns from past movement data, optimizing path corrections.
- Surface Adaptation Logic: Adjusts behavior based on floor texture, barriers, and environmental conditions.
- Emergency Recovery Sequences: In case of sensor disruption, the robot applies fallback decision routines.
- Performance Logging & Debugging: Captures sensor analysis results, improving future optimization cycles.


## 🚀 Future Development & Contribution
Our long-term vision for the project includes:
- Expanding servo motor control capabilities to allow for greater precision in movement adjustments.
- Optimizing ESP32 vision-based object tracking for advanced competition scenarios.
- Developing smart battery management strategies to improve operational longevity and efficiency.
- Publishing open-source documentation on sensor-based autonomous navigation solutions.
