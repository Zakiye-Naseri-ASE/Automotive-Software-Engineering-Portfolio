/*
 *	Project Owner	: TU Chemnitz
 *	Project Name	: ASE Tutorial Unit-2
 *	File Name		: siu.c
 *	Author			: ASE Admin
 *  Created on		: 25 Feb 2024
 */

/* Includes ******************************************************************/
#include "xpc56el.h"  //all macros for accecing prephirals registers also defined here
#include "siu.h"
#include "init.h"
#include "adc.h"



/*
 * @brief	SIU pin configuration function
 *
 * @param	void
 * @retval	void
 */
void SIU_Init(void)
{
	// Configure all pins which are required for your task here

	/* TO-DO: your task implementations **************************************/


	/* Input pin configurations */

	//SIU.PCR[...].R = ...;
	SIU.PCR[52].R = 0x100; //Switch 1
	SIU.PCR[53].R = 0x100; //Switch 2
	SIU.PCR[54].R = 0x100; //Switch 3
	SIU.PCR[55].R = 0x100; //Switch 4
	SIU.PCR[60].R = 0x100; //BT1
	SIU.PCR[61].R = 0x100; //BT2



	/* Output pin configurations */

	//SIU.PCR[...].R = ...;
    SIU.PCR[56].R = 0x200; //Red LED
	SIU.PCR[57].R = 0x200; //Yellow LED
	SIU.PCR[58].R = 0x200; //Yellow LED
	SIU.PCR[59].R = 0x200; //Green LED
	SIU.PCR[43].R = 0x200; //Green LED
	SIU.PCR[6].R = 0x200; //Green LED



	/* Analog pin configurations */

	//SIU.PCR[...].R = ...;
	SIU.PCR[66].R = 0x2500; //Potentiometer
	SIU.PCR[32].R = 0x2500; //Light sensor

	/*************************************************************************/
}
