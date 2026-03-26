# Unit 2: CAN Bus Communication

## Project Overview
This unit implements a Controller Area Network (CAN) communication stack. The ECU communicates with a **Virtual Cockpit** (a dashboard simulation) to display vehicle status (RPM, Speed, Indicators) and receive control commands (Start/Stop Engine).

## Features

### 1. CAN Controller Configuration
*   Configured the physical layer pins (TX/RX) on the microcontroller.
*   Set up **Message Buffers** for both transmission and reception of Data Frames.

### 2. Message Filtering (Hardware Level)
Implemented hardware filtering to reduce CPU load by ignoring irrelevant bus traffic.
*   **Logic:** Calculated **Mask** and **Acceptance** register values to allow only specific Message IDs (e.g., `0x10` and `0x11`) to trigger interrupts.
*   **Goal:** Ensure the ECU only wakes up/reacts to "Start Engine" or "Stop Engine" commands.

### 3. Signal Transmission
The ECU transmits the following telemetry data to the dashboard every 100ms:
*   **Engine On (0xDA0):** Keeps the virtual dashboard active.
*   **RPM (0x280):** Simulates engine revs (0 to 8000 RPM) using a sawtooth wave logic.
*   **Speed (0x5A0):** Maps the physical potentiometer position to vehicle speed (0–240 km/h).
*   **Indicators (0x470):** Controls Left/Right/Hazard blinkers based on physical switch inputs.

## 🧪 Test Automation: CAN Log Parsing
To validate the C-code implementation, I developed a Python script (`can_parser.py`) that acts as an automated validation tool for exported CAN bus traffic (`can_trace_log.csv`).

**Capabilities of the Script:**
*   Parses semicolon-separated trace files dynamically handling variable Data Length Codes (DLC).
*   Extracts specific data bytes (e.g., `d1`, `d2`) and converts raw Hexadecimal payloads into human-readable decimal integers (e.g., converting hex `3A` to `58 km/h`).
*   Automatically generates a `CAN_Test_Report.md` verifying that all expected signals were correctly transmitted on the bus.


## Technical Details
*   **Protocol:** CAN 2.0A (Standard 11-bit ID) and CAN 2.0B (Extended 29-bit ID).
*   **Tools:** Vector/TinyCAN Interface, Virtual Cockpit software.
