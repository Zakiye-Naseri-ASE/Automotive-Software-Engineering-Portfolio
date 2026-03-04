#include <Rte_Adder.h>
uint8 InputA= 0;
uint8 InputB= 0;
uint8 sum= 0;
void Adder_Compute()
{
 InputA = Rte_IRead_Compute_InputA_Value();
 InputB = Rte_IRead_Compute_InputB_Value();
 sum = InputA + InputB;
 Rte_IWrite_Compute_Sum_Value(sum);

}