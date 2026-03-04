# Automated Test Scripts (CAN Bus Stimulation)

Automated tests isolate the `WiperECU` by shutting down the `SensorECU` and simulating its inputs via direct CAN bus message injection (`Can.read` / `Can.write`).

Scenario: Always ON Mode Validation 
**Objective:** Verify that injecting `WiperButton = 1` yields `WiperStatus = 1` across the CAN bus .

1. ARRANGE (Stimulate SUT)
Write baseline parameters to the CAN bus to establish environmental context.

Utility: Can.write('WiperButton', 1)    // Switch to Always On 
Utility: Can.write('CurrentSpeed', 0)   // Vehicle stationary
Utility: Can.write('RainSensor', 0)     // No rain

Utility: Wait(100)                      // Wait 100ms for SUT state update

Variable Definition: int actualWiperStatus = Can.read('WiperStatus')

Utility: If-Then-Else
Condition: IF (actualWiperStatus == 1)  // Check if wipers activated
Then Block:
    Utility: Exit (Rating: SUCCESS)     // Test Passed 
Else Block:
    Utility: Exit (Rating: FAILED)      // Test Failed 