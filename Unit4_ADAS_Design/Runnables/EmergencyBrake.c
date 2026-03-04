#include <Rte_EmergencyBrakeControl.h>
#include <Sab.h>

void EmergencyBrakeControl_MyEBrake(void)
{
    float32 deceleration = 10.0f;
    boolean emergencyBrake = 0; // Default state: No collision risk
    
    // Read sensor inputs
    float32 currentSpeed = Rte_IRead_MyEBrake_CurrentSpeed_Value();
    float32 distanceLeading = Rte_IRead_MyEBrake_DistanceLeading_Value();
    
    // Calculate required braking distance based on physics kinematics
    float32 brakeDistance = ((currentSpeed * currentSpeed) * 0.27f) / (2.0f * deceleration);
    Sab_SubmitInfo("Calculated brakeDistance: %f", brakeDistance);

    // Collision detection logic:
    // Trigger if required braking distance exceeds the leading distance (minus 2m safety margin)
    if (brakeDistance > (distanceLeading - 2.0f)) {
        emergencyBrake = 1; // Activate emergency brake flag
        Sab_SubmitInfo("CRITICAL: EMERGENCY BRAKE ACTIVATED!");
    }

    // Write the emergency brake flag to the output port.
    // NOTE: This module no longer writes to CC_StateNew to prevent multiple-writer conflicts.
    Rte_IWrite_MyEBrake_EmergencyBrake_Value(emergencyBrake);
}