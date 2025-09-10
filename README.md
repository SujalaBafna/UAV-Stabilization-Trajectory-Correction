# UAV Stabilization & Trajectory Correction

## 🎯 Problem Statement  
Unmanned Aerial Vehicles (UAVs), especially fixed-wing platforms, often suffer from **trajectory drift and orientation instability** due to environmental disturbances like wind gusts and sensor noise.  
Conventional stabilization relies heavily on motor-based thrust vectoring, which is **power-intensive and unsuitable for long-endurance missions**.  

This project addresses the problem by developing a **lightweight, low-power PID-based control framework** that uses aerodynamic control surfaces (ailerons, elevators, rudder) instead of motors for stabilization.  

---

## ✅ Solution Overview  
This repository contains firmware, simulations, and hardware design for a **PID-based control system** for real-time orientation correction in fixed-wing UAVs.  
The system fuses IMU sensor data with PID control and actuates control surfaces via RC servos, implemented on an STM32 microcontroller with a custom shield.

---

## 📂 Structure
- **Src/**: Source code (STM32 + PID)
- **simulations/**: MATLAB PID simulation & plots
- **docs/**: Hardware documentation (Altium + exports)

---

## 🚀 Features
- PID-based roll, pitch, yaw stabilization
- STM32F446RE implementation
- Custom shield hardware (Altium files)
- MATLAB simulation of control response

---

## 🛠️ How to Run
1. Open in STM32CubeIDE  
2. Replace HAL stubs with real STM32 HAL  
3. Build and flash to STM32F446RE  
4. Connect IMU via UART 4/5
5. **Note:** “Certain proprietary libraries (developed under NDA) were excluded. Equivalent stubs provided for structure demonstration.”

---

## 📡 Hardware
See [docs/Hardware/README.md](docs/Hardware/README.md) for schematics and PCB exports.
