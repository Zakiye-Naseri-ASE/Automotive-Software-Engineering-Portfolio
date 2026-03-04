#include <Rte_DataLogger.h>
#include <Sab.h>
void DataLogger_Log()
{
    uint8 value = Rte_IRead_Log_DisplayNumber_Value();
    Sab_SubmitInfo("Receive data: %d", value);
}