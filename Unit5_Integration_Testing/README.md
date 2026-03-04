# Unit 5: ECU Integration Testing

## Project Overview
This unit focuses on **Black Box Integration Testing** of the Wiper Control System. The goal is to validate that the `WiperECU` behaves correctly according to the system specification using automated test scripts.

## System Under Test (SUT)
The system controls windshield wipers based on:
*   **Inputs (CAN IDs 1-3):** Rain Sensor, Wiper Stalk (Off/On/Auto), Vehicle Speed.
*   **Output (CAN ID 4):** Wiper Status (Active/Inactive).

**Logic validated:**
*   *Auto Mode:* Wipers activate only if Rain is detected AND Speed > 0.
*   *Manual Mode:* Wipers active regardless of rain/speed.

## Testing Methodology
Used **TraceTronic ecu.test** to implement the **Arrange-Act-Assert (AAA)** pattern:
1.  **Arrange:** Stimulate the bus with specific CAN messages (e.g., Speed=50, Rain=1, Mode=Auto).
2.  **Act:** Wait for the ECU to process inputs.
3.  **Assert:** Read the `WiperStatus` CAN message and compare it against the expected value from the Truth Table.

## Artifacts
*   **Truth Table:** Defines all logical permutations for the wiper system.
*   **Manual Test:** Interactive script instructing a human tester to physically toggle switches (using the `Message Dialog` utility).
*   **Automatic Test:** Fully automated script using `CanWrite` and `CanRead` utilities to validate the logic without human intervention.
