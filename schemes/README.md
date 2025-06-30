<h1 align="center">Schematic diagrams</h1>

![Diagrama en blanco (1)](https://github.com/user-attachments/assets/8d994640-49fc-4bd6-ba16-e3e5d442daac)



# 📁 Bill of materials

| Quantity | Component        | Image | Description |
|----------|------------------|-------|-------------|
| 1        | Arduino Uno      | ![Arduino](https://www.videoycomputacion.com.ve/5808-large_default/arduino-uno-r3-atmega-dip-328p-chip-grde.jpg) | Open-source microcontroller board for prototyping. |
| 1        | Breadboard       | ![Breadboard](https://eloctavobit.com/imagenes/2023/06/64799b86081a2.webp) | Reusable platform for temporary circuits. |
| 1        | H-Bridge (L298N) | ![H-Bridge](https://acdn-us.mitiendanube.com/stores/975/836/products/17637-mla20140879523_082014-o-8f0828cf82de8cee6415565106613680-480-0.jpg) | Motor driver to control DC motors direction/speed. |
| 1 | DC Motor with Gearbox | ![DC Motor with gearbox](https://robot.com.ve/wp-content/uploads/2021/08/Motorreductor-con-caja-reductora-6V-1-48-1.jpg) | DC motor with a gear reduction system, ideal for increasing torque and reducing output speed. |
| 1        | Servo (S090)     | ![Servo](https://www.aranacorp.com/wp-content/uploads/towerpro-servo-sg90.jpg) | Compact servo motor (0°-180° rotation). |
| 2        | VL53L0X          | ![VL53L0X](https://naylampmechatronics.com/1620-superlarge_default/sensor-vl53l0x-de-tof.jpg) | Time-of-Flight (ToF) laser distance sensor. |
| 1        | ESP32-WROOM-32D  | ![ESP32](http://wiztech.com.ua/wp-content/uploads/2024/04/ESP32-wroom-32D.webp) | Dual-core Wi-Fi/Bluetooth MCU for IoT. |
| 1        | Pixy2  | ![image](https://github.com/user-attachments/assets/75e9e0f7-ad2d-49d0-8a4a-0eb5d30714c4) | Programmable camera sensor that detects objects by color (up to 7 signatures simultaneously). Ideal for line tracking, object detection, and autonomous robot navigation. |

## ✅ Justification of Component Selection

Each component was selected based on its ability to address specific technical needs of the WRO circuit, ensuring reliable operation, integration, and performance in real-time autonomous navigation.

### 🧠 Arduino Uno
Used in the prototyping phase as a versatile and accessible microcontroller that allowed basic interfacing with sensors, actuators, and debugging tasks. It served as the foundation for early system validation before migrating to a more powerful processing unit.

### 🔌 Breadboard
Employed to expand the number of power and ground distribution points without soldering, the breadboard simplified prototyping and allowed flexible rearrangement of components across multiple testing stages.

### 🔀 L298N H-Bridge
The L298N module was critical for controlling the direction and speed of the DC motor via PWM signals. Its dual output channels made it ideal for simultaneously managing both propulsion and peripheral motion with sufficient current tolerance.

### ⚙️ DC Motor with Gearbox
Chosen for its ability to move the robot efficiently, this motor's built-in reduction gear translated high-speed rotation into greater torque, providing stability and acceleration — essential for covering the competition track rapidly and reliably.

### ↪️ SG90 Servo Motor
Responsible for adjusting the vehicle's heading, this servo was directly linked to the obstacle avoidance system. Based on input from lateral sensors and visual cues, the servo altered the front wheel angle to enable real-time evasive maneuvers.

### 👁️ VL53L0X Sensors
These Time-of-Flight sensors measured lateral distances to nearby walls or barriers. Their data fed into the control logic, triggering servo movements to prevent collisions and maintain central alignment within the circuit.

### 🎥 Pixy2 Camera
Enabled the robot to visually detect critical elements of the course such as colored columns or stoplights. It interpreted multiple color signatures in real time and passed this information to the control algorithm, allowing dynamic decisions such as obstacle avoidance or behavior modulation based on color context.

### 🧠 ESP32-WROOM-32D
Deployed as the final microcontroller for its high processing speed, dual-core architecture, and robust I2C handling. It coordinated simultaneous tasks: managing sensors, computing navigation logic, and driving actuators — all essential for WRO's fast-paced circuit environment.

---
