# Unit 1: Embedded Programming Basics

## Project Overview
This unit focuses on the fundamentals of programming an automotive Electronic Control Unit (ECU) using the SPC56EL60 microcontroller. The project involves direct register manipulation to control digital I/O and reading analog sensors.

## Hardware & Tools
*   **Microcontroller:** STMicroelectronics SPC56EL60
*   **IDE:** SPC5-Studio (Eclipse-based)
*   **Simulation:** Virtual ECU (vECU) running on Windows/Linux
*   **Peripherals:** Evaluation board with LEDs, Switches, Buttons, Potentiometer, and Light Sensor.

## Implemented Features

### 1. Analog Sensor Reading (ADC)
Configured the **Analog-to-Digital Converter (ADC)** to read values from:
*   **Potentiometer (Speed):** Mapped the raw voltage value (0–4095) to a visual scale using 6 LEDs (Red, Yellow, Green) to represent intensity.
*   **Activated only when `Switch 1` is ON. It visualizes the Speed Value.
*   **Light Sensor (LDR):** Activated only when `Switch 2` is ON. It visualizes ambient light intensity on the LED array.

### 2. Binary Counter (Timer Interrupts)
Implemented a 3-bit binary counter displayed on LEDs `U1`, `U2`, and `U3` (counting 0 to 7).
*   **PIT (Periodic Interrupt Timer):** Configured the hardware timer to trigger an Interrupt Service Routine (ISR) every 1 second.
*   **Control Logic:**
    *   `Button 1`: Sets counter mode to **Count Up**.
    *   `Button 2`: Sets counter mode to **Count Down**.
    *   `Switch 4`: Pauses/Resumes the counter updates.

### 3. Low-Level Driver Configuration
*   **SIU (System Integration Unit):** Manually configured the Pad Configuration Registers (PCR) to set pins as Input, Output, or Analog.
*   **GPDO/GPDI:** Used General Purpose Digital Output/Input registers to write to LEDs and read switch states.

## Key Code Snippets
*   **Pin Configuration:** Writing `0x0200` to PCR registers for Output and `0x0100` for Input.
*   **ISR Handling:** Implementing logic inside `PIT_Channel_X` to handle asynchronous timer events.
