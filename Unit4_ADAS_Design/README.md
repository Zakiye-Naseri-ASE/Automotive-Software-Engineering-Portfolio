# Unit 4: ADAS Function Design (Cruise Control & AEB)

## Project Overview
This unit involves the design and implementation of Advanced Driver Assistance Systems (ADAS) using AUTOSAR. The system controls a virtual vehicle in a 2D driving simulator, implementing **Adaptive Cruise Control (ACC)** and **Automatic Emergency Braking (AEB)**.

## System Architecture
The logic is encapsulated in the `AdasComposition` which sits between a Sensor SWC and an Actuator SWC.

### Components Developed:
1.  **CruiseControl SWC:**
    *   **Logic:** Maintains a driver-defined `TargetSpeed`. It calculates acceleration or braking commands based on the deviation from `CurrentSpeed`.
    *   **Features:**
        *   Automatic deactivation if the brake pedal is pressed.
        *   Manual override (acceleration) allowed without deactivation.
        *   Target speed adjustment via steering wheel buttons.

2.  **EmergencyBrake SWC:**
    *   **Logic:** Monitors the `DistanceLeading` (distance to car in front).
    *   **Physics:** Calculates the required braking distance using the formula: $d = v^2 / (2 * a)$.
    *   **Action:** Triggers a full emergency brake if the physical distance drops below the safety threshold, overriding all other inputs.

3.  **Target Speed Controller:**
    *   Processes button inputs (Up/Down) to increment or decrement the set speed.

## Simulation Environment
*   **Simulator:** CE Virtual Car 2D (provides physics and visual feedback).
*   **Execution:** The AUTOSAR V-ECU runs in **dSPACE VEOS**, exchanging data with the driving simulator in real-time.


## 🧪 Test Automation: Software-in-the-Loop (SiL) Validation
Instead of relying purely on visual confirmation in the 2D simulator, I implemented a Python evaluation script (`evaluate_adas.py`) to validate the AUTOSAR logic mathematically using the exported VEOS simulation trace (`veos_adas_log.csv`).

**Automated Validation Logic:**
The script reads the simulated vehicle speed and distance, and calculates the physical braking limit using the dynamic formula:
`d = v^2 / (2 * a)` (where deceleration `a` = 10 m/s²).

It checks every timestamp to assert that the `EmergencyBrake` SWC successfully triggers *only* when the distance falls below the calculated safety threshold, automatically generating an `ADAS_Test_Report.md` with pass/fail metrics for the execution timeline.
