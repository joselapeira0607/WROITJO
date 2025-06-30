<h1 align="center">Technical Report</h1>
<h2 align="center">Development of an Autonomous Robot for the World Robot Olympiad (WRO)</h2>

<p align="center"><i>Complete documentation of the design, optimization, and results of an autonomous mobile robot prepared to navigate obstacle-filled closed circuits.</i></p>

---

## 🧭 Introduction

This document provides a detailed description of the design, assembly, optimization, and validation process of an autonomous robot created to compete in the World Robot Olympiad (WRO). The primary technical objective was to enable the robot to complete three laps within a closed circuit while precisely avoiding walls and intermediate obstacles.

Throughout the process, we addressed challenges in three fundamental areas: mechanics, electronics, and intelligent control. Technical iterations allowed us to refine both the hardware and navigation algorithm, resulting in a robust and reliable system.

> 📷 ![460205220-4385875f-8fb5-4cfd-8109-ed76797ce5a7](https://github.com/user-attachments/assets/7eeb1662-5465-4cd8-8b95-888d35d6f3af)

---

## 🧪 Initial Phase: LEGO Prototyping (March)

The initial stage focused on building a functional prototype using LEGO Mindstorms components, given their modular versatility and ease of testing.

### Mechanical Design

We developed a basic chassis with LEGO components, which incorporated:
- A differential steering system
- Front wheels connected to a 3D-printed toothed beam actuated by a servo motor
- Rear wheels with traction provided by an NXT motor

### Electronic Circuit

The initial control and detection system consisted of:
- **Microcontroller:** Arduino UNO  
- **Motor control:** L298N H-bridge  
- **Sensing:** Two HC-SR04 ultrasonic sensors positioned front and side  
- **Power:** Three 4V rechargeable batteries connected in series (12V total) distributed via breadboard  

> 📷 ![IMG_20250425_150937_312](https://github.com/user-attachments/assets/b59a5c2e-5463-4042-b58e-b8d414681b3f)

### Identified Technical Issues

During initial testing, we identified significant limitations:
- High sensitivity to ultrasonic noise in HC-SR04 sensors, causing false detections
- Limited precision in tight turns due to structural flexibility of the LEGO differential system
- Torque loss and vibrations from NXT motor overheating at high speeds

---

## 🔧 Optimization: Sensors and Controller

Based on the identified issues, we restructured the sensing and control system.

### Migration to VL53L0X Sensors

The ultrasonic system was replaced with VL53L0X Time-of-Flight sensors, which offered:
- Millimeter resolution with high stability
- Immunity to environmental acoustic interference
- Adjustable detection range up to 2 meters

**Resulting challenges:**
- Sensor performance was affected by excessive lighting
- I2C protocol readings required higher processing speed

### ESP32 Integration

To improve parallel reading and processing capability, we integrated an ESP32 that provided:
- Dual-core processing for multitasking (parallel sensor reading and motor control)
- More efficient I2C communication without bus congestion

---

## ⚙️ Mechanical Redesign: DKS-Basic Chassis

### LEGO Chassis Limitations
- Low structural rigidity under dynamic loads
- Play in mobile connections
- Excessive weight, reducing agility and autonomy

### DKS-Basic Advantages

We transitioned to a professional metal chassis (DKS-Basic) that offered:
- Greater resistance thanks to anodized aluminum
- Ball bearing system reducing friction
- More compact geometry optimizing tight turns
- Compatibility with commercial DC motors

### Traction System Upgrade
- Replaced NXT motor with gear-reduced DC motor
- Improved torque and speed control with PWM signal
- Custom CAD-designed 3D-printed wheels adapted to the new chassis bearings

> 📷 ![left-view](https://github.com/user-attachments/assets/24d5cb4c-50c7-49b2-b633-ab05e7ddc39f)

---

## 🧠 Final Sensing and Control System

### Sensor Configuration

The final version incorporated a hybrid sensor architecture:
- 1x HC-SR04 (front position) for long-range obstacle detection
- 2x VL53L0X (side) for curve navigation and precise avoidance

### Avoidance Algorithm

We implemented deterministic logic firmware using a finite state machine (FSM) defining three operation modes:
1. **Free movement:** no detected obstacles
2. **Lateral turn:** partial wall presence
3. **Braking and reverse:** critical front wall detection

Readings were filtered using a median algorithm to eliminate anomalous values.

---

## 📈 Evaluation and Results

### Performance Metrics

| Parameter               | Achieved Value  |
|-------------------------|------------------|
| Maximum speed           | 1.2 m/s          |
| Average lap time        | 15 seconds       |
| Turning precision       | ±2 cm            |
| Detection accuracy      | 98%              |

### Lessons Learned
- Sensor redundancy significantly improves reliability
- A professional chassis greatly contributes to dynamic stability
- The ESP32 proves highly suitable for real-time navigation systems requiring simultaneous multitasking

---

## 🏁 Conclusion

The developed robotic system not only met the WRO competition requirements but exceeded precision and stability expectations. The implementation of hybrid sensors, a high-performance controller like the ESP32, and a professional mechanical chassis were determining factors in the project's success.

Beyond its competition participation, this robot represents a solid technical foundation for developing future autonomous navigation platforms in dynamic environments.

---

## 👥 Development Team

**Author:** JO SLD  
**Year:** 2025  
**Collaborators:** *Keiner Duran, Jose Lapeira, Mauricio Sanchez*
