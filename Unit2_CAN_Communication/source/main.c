/*
 *	Project Owner	: TU Chemnitz
 *	Project Name	: ASE Tutorial Unit-2
 *	File Name		: main.c
 *	Author			: Zakiye Naseri
 *  Created on		: 25 Feb 2025
 */

/* Includes ******************************************************************/
#include "init.h"
#include <stdio.h>


/* Global variables **********************************************************/
int speed = 0;
int rpm = 0;
int Flag_On = 0;
typedef enum { IDLE, ON } ECU_State;
ECU_State state = IDLE;

void can_send_engine_on(void){

	/* TO-DO: your task implementations **************************************/
    
    CAN_0.BUF[8].DATA.B[0] = 0;    // set payload bytes, if necessary
	CAN_0.BUF[8].CS.B.CODE = 0xC;  // write the correct CODE value to this register to instruct the CAN controller to transmit the CAN message
	LED_Tx = !LED_Tx;              // indicate transmating msg

}

void can_send_speed(int value){
	/* TO-DO: your task implementations **************************************/
    
	uint16_t pot = POT;
	uint16_t speed = (pot * 240) / 4095;
	CAN_0.BUF[9].DATA.B[0] = speed;
	CAN_0.BUF[9].CS.B.CODE = 0xC;

}

void can_send_rpm(void){
	/* TO-DO: your task implementations **************************************/

	static int rpm = 8000;
	static int rpm_dir = -250;
	rpm += rpm_dir;
	if (rpm <= 0 || rpm >= 8000) rpm_dir = -rpm_dir;

	CAN_0.BUF[10].DATA.B[0] = rpm & 0xFF;         // Low byte
	CAN_0.BUF[10].DATA.B[1] = (rpm >> 8) & 0xFF;   // High byte
	CAN_0.BUF[10].CS.B.CODE = 0xC;

}


void can_send_lights(void){
	/* TO-DO: your task implementations **************************************/

    int Led_Data = 0;

	if (SW1 == 0 && SW2 == 0){ 	   Led_Data = 0x00;	    }
	else if(SW1 == 0 && SW2 == 1){ Led_Data = 0x01; 	}
	else if(SW1 == 1 && SW2 == 0){ Led_Data = 0x02;     }
	else if(SW1 == 1 && SW2 == 1){ Led_Data = 0x03;	    }

    CAN_0.BUF[11].DATA.B[0] = Led_Data;
	CAN_0.BUF[11].CS.B.CODE = 0xC;
}

void can_send(void){

	/* TO-DO: your task implementations **************************************/
    can_send_engine_on();
	can_send_speed(POT);
	can_send_rpm();
	can_send_lights();
	/*************************************************************************/
}


/*
 * @brief	Main program
 *
 * @param	void
 * @retval	int
 */
int main(void) {
	/* peripherals initialization */
	peripheralsInit();



	/* TO-DO: your task implementations **************************************/

	/* Configure and start timer channels */
	/* PIT timer channel 1, period = 1000 ms */
    PIT_ConfigureTimer(1,100);
	/*************************************************************************/


	/* main program */
	while(1){
		/* System function */
		systemFunction();

		/* TO-DO: your task implementations **********************************/
		if (Flag_On) { PIT_StartTimer(1);  }
		else         { PIT_StopTimer(1);   
		   
		   LED_Rx=0;
           LED_Tx=0;
           LED_U1=0;
           LED_U2=0;
           LED_U3=0;}
		/*********************************************************************/

		/* 10 ms OS delay */
		osalThreadDelayMilliseconds(10UL);
	}
}


/*
 * @brief	CAN receive interrupt
 *
 * @param   CANDriver   canp	The CAN controller which received a message
 * @param	CANRxFrame	crfp	The message which was received
 * @retval	void
 */
void can_receive(CANRxFrame crfp) {
    if(crfp.IDE == CAN_IDE_STD) // a standard message frame has been received
    {
        /* TO-DO: your task implementations ******************************/
		LED_Rx = !LED_Rx;     // indicate receiving msg

        if (crfp.SID == 0x11 && state == IDLE)       // check the Message ID and ECU state
        {
			state = ON;
			Flag_On =1;        // Flag for receiving signal from start btn
			LED_P = !LED_P;    // indicate engain is On
			LED_U1 = !LED_U1;  // indicate receiving msg with 0x11

        } else if(crfp.SID == 0x10 && state == ON){  // check the Message ID and ECU state

			state = IDLE;
			Flag_On =0;        // Flag for receiving signal from stop btn
			LED_P = 0;         // indicate engain is On
		}
    }
}


/*
 * @brief	PIT timer channel 1 IRQ callback
 *
 * @param	void
 * @retval	void
 */
void PIT_Channel_1(void){
	/* TO-DO: your task implementations **************************************/
	can_send();

}


/*
 * @brief	PIT timer channel 2 IRQ callback
 *
 * @param	void
 * @retval	void
 */
void PIT_Channel_2(void){
	/* TO-DO: your task implementations **************************************/

}


/*
 * @brief	PIT timer channel 3 IRQ callback
 *
 * @param	void
 * @retval	void
 */
void PIT_Channel_3(void){
	/* TO-DO: your task implementations **************************************/


}
