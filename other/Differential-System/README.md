# DKS-Basic RC Chassis Differential System

## Overview
The DKS-Basic chassis features a **solid rear axle transmission system**, designed for simplicity and optimal performance in 3D-printed RC applications.

## Technical Specifications

### Current Drivetrain Configuration
- **Transmission Type**: Direct gear drive (spur gear system)
- **Gear Ratio**: 1:1 (configurable with different gear sizes)
- **Axle Type**: Solid rear axle with locked differential behavior
- **Wheel Synchronization**: Both rear wheels rotate at identical speeds

### Key Components
| Component | Description |
|-----------|-------------|
| `Gear-1` | Motor pinion (M1 gear module) |
| `Gear-2` | Axle spur gear (M1 gear module) |
| Rear Axle | 5mm diameter with integrated wheel mounts |
| Bearings | 8x12x3.5mm (front), 12x18x4mm (rear) |

## Performance Characteristics

### Advantages
✔ Simplified mechanical design (fewer moving parts)  
✔ Increased torque transfer efficiency  
✔ Reduced weight (ideal for 3D-printed structures)  
✔ Lower maintenance requirements  

### Limitations
⚠ Reduced turning efficiency on high-traction surfaces  
⚠ Potential for wheel slip during tight turns  
⚠ Higher tire wear in competitive environments  

## Modification Options for Competitive Use

### Differential Upgrade Paths
1. **Printed Open Differential**
   - Requires modification to `Rear-Frame_R` components
   - Recommended materials: ABS or PETG
   - Suggested gear module: M0.8 for smoother operation

2. **Electronic Traction Control**
   - Implement via ESC programming
   - Requires brushless motor system
   - Can simulate limited-slip behavior

3. **Independent Wheel Drive**
   - Dual motor configuration
   - Requires chassis redesign
   - Enables advanced torque vectoring

## Implementation Guide

### Basic Solid Axle Setup
```bash
1. Install Gear-1 on motor shaft (M3 set screws)
2. Mount Gear-2 on rear axle
3. Secure with M3x16mm screws and locknuts
