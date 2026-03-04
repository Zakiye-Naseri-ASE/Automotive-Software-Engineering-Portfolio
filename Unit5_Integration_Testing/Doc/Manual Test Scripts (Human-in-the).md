# Manual Test Scripts (Human-in-the-Loop)

Manual testing requires a test protocol instructing a human tester to bring the system to a desired state via physical inputs.The scripts follow the **AAA (Arrange, Act, Assert)** architecture.

Scenario 1: Wipers Off Verification 
Expected SUT State:`WiperStatus` = 0 [cite: 434]

**ARRANGE**
  * Utility:** `Message Dialog`
  *Instruction to Human:** "Please set Switch 1 (Wipers ON) to OFF. Set Switch 2 (Auto Mode) to OFF. Set Potentiometer to ANY position. Set Light Sensor to ANY state."

**ACT**
  * Utility:** `Wait for User` (Prompt: "Click 'OK' once configured") 

**ASSERT:**
  **Utility:** `Input Dialog` 
  **Question:** "Are the windshield wipers currently active on the WiperECU display?" 
  **Options:** `Yes`, `No` 
  **Logic:** * `If-Then-Else` Condition: `IF (Input_Dialog_Result == "No")`
    `Then`: Utility Exit -> `Rating: SUCCESS` 
    `Else`: Utility Exit -> `Rating: FAILED` 


Scenario 6: Auto Mode Verification 
**Expected SUT State:** `WiperStatus` = 1 (Active)

**ARRANGE**
  **Utility:** `Message Dialog` 
  **Instruction to Human:** "Set Switch 1 to ON. Set Switch 2 to ON (Auto Mode). Turn potentiometer to ANY position EXCEPT far left (Speed > 0). COVER the light sensor (Rain = 1)." 

**ACT**
  **Utility:** `Wait for User`

**ASSERT:**
  **Utility:** `Input Dialog` 
  **Question:** "Are the windshield wipers currently active on the WiperECU display?" 
  **Logic:**
    `If-Then-Else` Condition: `IF (Input_Dialog_Result == "Yes")` 
    `Then`: Utility Exit -> `Rating: SUCCESS` 
    `Else`: Utility Exit -> `Rating: FAILED`