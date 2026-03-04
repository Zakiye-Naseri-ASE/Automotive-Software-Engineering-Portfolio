#include <Rte_CruiseControlSWC.h>
#include <Sab.h>

void CruiseControlSWC_Main(void) 
{
    // Read standard inputs
    boolean ccState      = Rte_IRead_Main_CC_State_Value();
    boolean accelPedal   = Rte_IRead_Main_AcceleratorPedal_Value();
    boolean brakePedal   = Rte_IRead_Main_BrakePedal_Value();
    float32 targetSpeed  = Rte_IRead_Main_TargetSpeed_Value();
    float32 currentSpeed = Rte_IRead_Main_CurrentSpeed_Value();
    
    // Read the safety-critical emergency brake signal from the newly defined required port
    boolean eBrake = Rte_IRead_Main_EmergencyBrake_Value();

    // ------------------------------------------------------------------
    // Priority 1 (Highest Safety): Manual Braking OR Emergency Braking
    // ------------------------------------------------------------------
    if (brakePedal || eBrake) {
        ccState = 0; // Immediately and unconditionally deactivate Cruise Control
        Rte_IWrite_Main_CC_StateNew_Value(ccState);
        
        // Ensure the cruise system drops throttle and commands braking
        Rte_IWrite_Main_Accelerate_Value(0);
        Rte_IWrite_Main_Brake_Value(1); 
        
        Sab_SubmitInfo("SAFETY INTERLOCK: CC Deactivated due to Brake/EBrake.");
        return; // Early return to prevent any subsequent logic from executing
    }

    // ------------------------------------------------------------------
    // Priority 2: Driver Override (Accelerator Pedal Pressed)
    // ------------------------------------------------------------------
    if (accelPedal) {
        // Maintain the CC state internally, but yield physical control to the driver
        Rte_IWrite_Main_CC_StateNew_Value(ccState);
        Rte_IWrite_Main_Accelerate_Value(1);
        Rte_IWrite_Main_Brake_Value(0);
        return;
    }

    // ------------------------------------------------------------------
    // Priority 3: Normal Cruise Control Logic (Active State)
    // ------------------------------------------------------------------
    if (ccState) {
        Rte_IWrite_Main_CC_StateNew_Value(ccState); // Renew active state

        if (currentSpeed < targetSpeed) {
            // Accelerate to reach target speed
            Rte_IWrite_Main_Accelerate_Value(1);
            Rte_IWrite_Main_Brake_Value(0);
        } else if (currentSpeed > targetSpeed) {
            // Apply brakes to reduce speed to target
            Rte_IWrite_Main_Accelerate_Value(0);
            Rte_IWrite_Main_Brake_Value(1);
        } else {
            // Coasting: Speed matches the target precisely
            Rte_IWrite_Main_Accelerate_Value(0);
            Rte_IWrite_Main_Brake_Value(0);
        }
    } else {
        // Priority 4: System is OFF and no driver inputs are active
        Rte_IWrite_Main_CC_StateNew_Value(ccState);
        Rte_IWrite_Main_Accelerate_Value(0);
        Rte_IWrite_Main_Brake_Value(0);
    }
}