# Aircraft Engine Monitoring System 

## Overview
The **Aircraft Engine Monitoring System** is an IoT-based real-time monitoring platform designed to simulate aircraft engine supervision using an ESP32 microcontroller, MQTT communication, and a Node-RED dashboard.

The project monitors and visualizes critical engine parameters such as:

- Engine Temperature (EGT)
- Oil Pressure
- Engine Vibrations
- Fuel Flow

The system provides a modern dashboard inspired by aviation EICAS (Engine Indication and Crew Alerting System) interfaces.

---

## Features 

- Real-time engine monitoring
- Dual-engine simulation
- MQTT communication protocol
- Interactive Node-RED dashboard
- ESP32 integration
- Dynamic gauges and charts
- Alert management system
- Fuel flow visualization
- Engine temperature curves
- IoT architecture

---

## System Architecture 

```txt
Sensors → ESP32 → MQTT Broker → Node-RED → Dashboard
```

### Components Used
- ESP32
- DHT22 Sensors
- Potentiometers
- MQTT Broker
- Node-RED Dashboard

---

## Dashboard Preview 

### Main Dashboard
- Engine 1 monitoring
- Engine 2 monitoring
- Fuel Flow indicator
- Oil Pressure gauges
- Vibration monitoring
- Temperature curves

---

## Project Structure 📁

```txt
Aircraft-Engine-Monitoring/
│
├── README.md
├── LICENSE
├── .gitignore
│
├── docs/
├── esp32/
├── node-red/
├── mqtt/
├── dashboard/
├── data/
├── simulation/
└── presentation/
```

---

## MQTT Topics 

```txt
avion/moteur1/data
avion/moteur2/data
```

---

## Installation 

### 1. Clone the repository

```bash
git clone https://github.com/your-username/aircraft-engine-monitoring.git
```

---

### 2. Install Node-RED

```bash
npm install -g --unsafe-perm node-red
```

---

### 3. Install Required Libraries (ESP32)

Install:
- WiFi.h
- PubSubClient
- DHT sensor library

---

### 4. Run MQTT Broker

Example using Mosquitto:

```bash
mosquitto
```

---

### 5. Import Node-RED Flow

- Open Node-RED
- Menu → Import
- Select `flows.json`

---

## Hardware Connections 

### Sensors
- DHT22 for temperature simulation
- Potentiometers for:
  - Oil pressure
  - Vibrations
  - Fuel flow

### ESP32
Handles:
- Sensor acquisition
- MQTT publishing
- Real-time communication

---

## Technologies Used 

| Technology | Role |
|---|---|
| ESP32 | Main microcontroller |
| MQTT | Communication protocol |
| Node-RED | Dashboard & data processing |
| DHT22 | Temperature sensor |
| JavaScript | Node-RED functions |
| JSON | Data exchange |

---

## Future Improvements 

- Predictive maintenance using AI
- Real aircraft sensor integration
- Cloud database storage
- Mobile application
- Alarm notification system
- Historical data analytics

---

## Screenshots 

Add your screenshots inside:

```txt
docs/
dashboard/screenshots/
```

Example:
- Dashboard view
- Node-RED flow
- ESP32 wiring
- Simulation setup

---

## Author 

Developed by **Basma Elhaddaoui**

Student Project — Aircraft Engine IoT Monitoring System

---

## License 📄

This project is licensed under the MIT License.

---

## Acknowledgments 🙏

- ESP32 Community
- Node-RED
- MQTT
- Open-source IoT ecosystem
