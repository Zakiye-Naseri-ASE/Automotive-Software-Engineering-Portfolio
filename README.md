# Automotive Software Engineering Portfolio

This repository contains my practical work for the "Embedded Programming" and "Automotive Software Engineering" courses. The projects progress from low-level register manipulation on an SPC56EL60 microcontroller to high-level AUTOSAR application design, culminating in Automated Software-in-the-Loop (SiL) testing.

## 🛠️ Test Automation & Validation (Python)
To demonstrate a complete validation workflow suitable for modern CI/CD pipelines, I have integrated **Python-based test automation scripts** alongside the C/AUTOSAR implementations:
*   **Unit 2:** Custom Python parser to evaluate exported CAN bus trace logs, converting raw hex payloads into physical values (e.g., km/h) and verifying signal transmission.
*   **Unit 4:** Automated evaluation script to verify the AUTOSAR Emergency Brake logic against virtual simulation data, calculating real-time physical braking limits.
*   **Unit 5:** Custom report generator that converts raw `ecu.test` CSV exports into readable Markdown summaries for management.

---

## Project Overview

| Unit | Focus | Key Technologies |
| :--- | :--- | :--- |
| **Unit 1** | **Microcontroller I/O** | C, Registers, ADC, Digital I/O, Interrupts (PIT) |
| **Unit 2** | **CAN Bus** | CAN Controller Setup, Message Filtering, Transceivers, Python Log Parsing |
| **Unit 3** | **AUTOSAR Basics** | SystemDesk, SWC Design, RTE Generation, V-ECU |
| **Unit 4** | **ADAS Functionality** | Cruise Control, Sensor Fusion, SiL Testing, Python Data Validation |
| **Unit 5** | **Testing (HIL/SIL)** | Black Box Testing, TraceTronic ecu.test, Automated Python Reporting |

*(Navigate to individual Unit folders for specific source code, models, and test reports.)*