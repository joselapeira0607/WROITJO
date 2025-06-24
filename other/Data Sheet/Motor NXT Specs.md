# 🏗️ LEGO NXT Motor + H-Bridge Adapter Setup  

<div align="center">
  <img src="https://github.com/user-attachments/assets/e4982d0b-655d-41dc-9d93-b7c6aee5f688" width="500" alt="NXT Motor with H-Bridge Adapter">
  <br>  
  <em>LEGO NXT Motor modified with custom RJ12-to-Dupont adapter for H-Bridge control</em>
</div>

---

## 🔧 **Technical Specifications**  

| **Parameter**       | **Details**                              |
|---------------------|------------------------------------------|
| **Motor Type**      | DC Brushed + Optical Encoder             |
| **Operating Voltage** | 9V DC (7-12V range)                    |
| **No-Load Speed**   | 170-180 RPM                             |
| **Stall Torque**    | 15 N·cm                                 |
| **Encoder Resolution** | 3 pulses per revolution (±1° precision) |
| **Connection**      | Custom RJ12 → Dupont adapter to H-Bridge |

---

## ⚡ **H-Bridge Wiring Diagram**  
```plaintext
NXT Motor Cable       H-Bridge (L298N)  
───────────────────────────────────────  
Red (+)    →→→  OUTPUT 1  
Black (-)  →→→  OUTPUT 2  
White      →→→  (Encoder - Not Connected)  
Yellow     →→→  (Encoder - Not Connected)  
```

**Key Connection Notes:**  
- 🟢 **Power**: Use separate 9V supply for motors (not Arduino 5V).  
- 🔄 **Direction Control**: Swap `OUTPUT 1`/`OUTPUT 2` to reverse rotation.  
- 🎛️ **Speed Control**: Connect `ENA` (PWM) to Arduino (e.g., Pin 9).  
