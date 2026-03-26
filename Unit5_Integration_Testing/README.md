
# Unit 5: ECU Integration Testing

## Project Overview
This unit focuses on **Black Box Integration Testing** of a Wiper Control System using **TraceTronic ecu.test**. The goal is to validate that the `WiperECU` behaves correctly according to the system specification (Truth Tables) using automated CAN bus stimulation.

## System Under Test (SUT)
The system controls windshield wipers based on:
*   **Inputs (CAN IDs 1-3):** Rain Sensor, Wiper Stalk (Off/On/Auto), Vehicle Speed.
*   **Output (CAN ID 4):** Wiper Status (Active/Inactive).

**Logic validated:**
*   *Auto Mode:* Wipers activate only if Rain is detected AND Speed > 0.
*   *Manual Mode:* Wipers active regardless of rain/speed.

## Testing Methodology
Used the **Arrange-Act-Assert (AAA)** pattern in `ecu.test`:
1.  **Arrange:** Stimulate the bus with specific CAN messages (Speed, Rain, Mode).
2.  **Act:** Wait for the ECU to process inputs.
3.  **Assert:** Read the `WiperStatus` CAN message and evaluate the logic.


## Artifacts
*   **Truth Table:** Defines all logical permutations for the wiper system.
*   **Manual Test:** Interactive script instructing a human tester to physically toggle switches (using the `Message Dialog` utility).
*   **Automatic Test:** Fully automated script using `CanWrite` and `CanRead` utilities to validate the logic without human intervention.

## 🧪 Test Automation: CI/CD Report Generation
In a professional CI/CD environment, test tools output raw data that must be parsed for stakeholders. I developed a Python script (`generate_test_report.py`) to parse the semicolon-delimited export from `ecu.test` (`ecu_test_results.csv`) [1].

**Script Features:**
*   Reads test execution data (Test Case ID, Module, Result, Execution Time) [1].
*   Calculates the overall success rate automatically (e.g., identifying 2 SUCCESS and 1 FAILED test cases) [1].
*   Generates a clean, formatted `Unit5_Final_Report.md` summarizing the health of the ECU build.