# Unit 3: AUTOSAR Application Design

## Project Overview
This unit introduces the **AUTOSAR (AUTomotive Open System ARchitecture)** methodology. Instead of writing raw C code, the application structure was designed using a Model-Based Development (MBD) approach and simulated on a Virtual ECU.

## Architecture Design
**Tool:** dSPACE SystemDesk 5.6.

The application consists of a software composition containing two main **Software Components (SWCs)**:
1.  **Counter SWC:** Generates a continuous stream of numbers.
    *   *Port:* `Number` (Provided Port).
    *   *Internal Behavior:* A Runnable triggered by a 500ms **Timing Event**.
2.  **DataLogger SWC:** Receives data and logs it to the console.
    *   *Port:* `DisplayValue` (Required Port).
    *   *Internal Behavior:* A Runnable triggered by a **Data Received Event** (executes immediately when data arrives).

## Implementation & RTE
*   **Interfaces:** defined `IfSingleNumber` (Sender-Receiver interface) with a `uint8` data element to connect the components.
*   **RTE Generation:** Generated the **Runtime Environment (RTE)** to handle the Virtual Functional Bus (VFB) communication.
*   **Runnables:** Implemented C-code stubs using AUTOSAR API calls:
    *   `Rte_IWrite_...` for sending data.
    *   `Rte_IRead_...` for receiving data.

## Simulation
The project was compiled into a **Virtual ECU** and executed using the **dSPACE VEOS Player**. This allowed for validating the communication between components without physical hardware.
