#include <Rte_TargetSpeedControlSWC.h>
#include <Sab.h>

void TargetSpeedControlSWC_Main(void)
{
    // Read the current state of the target speed adjustment button
    uint8 btnState = Rte_IRead_Main_TargetSpeedButtonState_Value();

    // Static variable to maintain the target speed value across execution cycles
    static float32 targetSpeed = 10.0f;

    // Update target speed based on the button logic
    if (btnState == 1) {
        // Increment command
        targetSpeed += 5.0f;
        if (targetSpeed > 130.0f) {
            targetSpeed = 130.0f; // Upper limit saturation
        }
    } 
    else if (btnState == 2) {
        // Decrement command
        targetSpeed -= 5.0f;
        if (targetSpeed < 10.0f) {
            targetSpeed = 10.0f; // Lower limit saturation
        }
    }
    // Else: btnState == 0 or invalid -> maintain current target speed

    // Write the updated target speed to the output port
    Rte_IWrite_Main_TargetSpeed_Value(targetSpeed);

    // Optional: Submit debug information
    Sab_SubmitInfo("Target Speed updated to: %.1f km/h", targetSpeed);
}