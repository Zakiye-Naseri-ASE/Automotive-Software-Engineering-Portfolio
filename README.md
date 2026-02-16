# Automotive-Software-Engineering-Portfolio
This repository contains my practical work for the "Embedded Programming" and "Automotive Software Engineering" Internship (Summer Semester 2025). The projects progress from low-level register manipulation on an SPC56EL60 microcontroller to high-level AUTOSAR application design and integration testing.
Implemented a binary counter and sensor readers by directly accessing the SIU (System Integration Unit) registers of the microcontroller. Configured Periodic Interrupt Timers (PIT) for precise timing.
Configured the CAN controller to interface with a Virtual Cockpit. Implemented message filtering (Mask/Acceptance registers) to ignore irrelevant bus traffic and transmitted dashboard status messages.
Designed a modular Cruise Control and Emergency Brake system using AUTOSAR methodology.
• Tools: dSpace SystemDesk, VEOS Player.
• Architecture: Created SensorSWC, ActuatorSWC, and ControllerSWC connected via Sender-Receiver interfaces.
• Simulation: Validated the logic using a 2D Driving Simulator connected via a Virtual ECU.
 (upload screenshot here)
Developed automated test scripts using TraceTronic ecu.test. Validated the Wiper ECU logic using the Arrange-Act-Assert (AAA) pattern and truth tables to ensure safety-critical compliance
