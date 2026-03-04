/*
 *	Project Owner	: TU Chemnitz
 *	Project Name	: ASE Tutorial Unit-1
 *	File Name		: main.c
 *	Author			: ASE Admin
 *  Created on		: 25 Feb 2024
 */

/* Includes ******************************************************************/
#include "xpc56el.h"
#include "siu.h"
#include "init.h"
#include "pit.h"



/* Global variables **********************************************************/
int counter = 0;
int led_count = 0;
bool btn1,btn2,sw1,sw2,sw3,sw4 = 0;



/* Task-2 implementation *****************************************************/
void task_pot(int x){

	/* TO-DO: your task implementations **************************************/
	//  map 0-4095 to 0-6  led_count = (x * 6 )/ 4096;
	led_count = (x * 6 )/ 4096;
	if      ( led_count == 0 )
		    {
				SIU.GPDO[56].R = 1;    //p    red   assigning a value to digital output
				SIU.GPDO[57].R = 0;    //Rx   yellow
				SIU.GPDO[58].R = 0;    //Tx   yellow
			    SIU.GPDO[6].R  = 0;    //U3   green
				SIU.GPDO[43].R = 0;    //U2   green
				SIU.GPDO[59].R = 0;    //U1   green
		    }
		else if ( led_count == 1)
		{
				SIU.GPDO[56].R = 1;    //p    red
				SIU.GPDO[57].R = 1;    //Rx   yellow
				SIU.GPDO[58].R = 0;    //Tx   yellow
			    SIU.GPDO[6].R  = 0;    //U3   green
				SIU.GPDO[43].R = 0;    //U2   green
				SIU.GPDO[59].R = 0;    //U1   green
		    }
		else if ( led_count == 2)
		{
			SIU.GPDO[56].R = 1;    //p    red
			SIU.GPDO[57].R = 1;    //Rx   yellow
			SIU.GPDO[58].R = 1;    //Tx   yellow
			SIU.GPDO[6].R  = 0;    //U3   green
			SIU.GPDO[43].R = 0;    //U2   green
			SIU.GPDO[59].R = 0;    //U1   green
		}
		else if (led_count == 3)
		{
			SIU.GPDO[56].R = 1;    //p    red
			SIU.GPDO[57].R = 1;    //Rx   yellow
			SIU.GPDO[58].R = 1;    //Tx   yellow
			SIU.GPDO[6].R  = 1;    //U3   green
			SIU.GPDO[43].R = 0;    //U2   green
			SIU.GPDO[59].R = 0;    //U1   green
		}
		else if (led_count == 4)
		{
			SIU.GPDO[56].R = 1;    //p    red
			SIU.GPDO[57].R = 1;    //Rx   yellow
			SIU.GPDO[58].R = 1;    //Tx   yellow
			SIU.GPDO[6].R  = 1;    //U3   green
			SIU.GPDO[43].R = 1;    //U2   green
			SIU.GPDO[59].R = 0;    //U1   green
		}
		else if (led_count == 5 )
		{
			SIU.GPDO[56].R = 1;    //p    red
			SIU.GPDO[57].R = 1;    //Rx   yellow
			SIU.GPDO[58].R = 1;    //Tx   yellow
			SIU.GPDO[6].R  = 1;    //U3   green
			SIU.GPDO[43].R = 1;    //U2   green
			SIU.GPDO[59].R = 1;    //U1   green
		}
		else
	    {
			// Do nothing
		}

		



	/*************************************************************************/
}

/* Task-3 implementation *****************************************************/
void task_ldr(int x){

	/* TO-DO: your task implementations **************************************/
	//  map 0-4095 to 0-6  led_count = (x * 6 )/ 4096;
	led_count = (x * 6 )/ 4096;
			if ( led_count == 0 )
			    {
					SIU.GPDO[56].R = 1;    //p    red
					SIU.GPDO[57].R = 0;    //Rx   yellow
					SIU.GPDO[58].R = 0;    //Tx   yellow
				    SIU.GPDO[6].R  = 0;    //U3   green
					SIU.GPDO[43].R = 0;    //U2   green
					SIU.GPDO[59].R = 0;    //U1   green
			    }
			else if ( led_count == 1)
			{
					SIU.GPDO[56].R = 1;    //p    red
					SIU.GPDO[57].R = 1;    //Rx   yellow
					SIU.GPDO[58].R = 0;    //Tx   yellow
				    SIU.GPDO[6].R  = 0;    //U3   green
					SIU.GPDO[43].R = 0;    //U2   green
					SIU.GPDO[59].R = 0;    //U1   green
			    }
			else if ( led_count == 2 )
			{
				SIU.GPDO[56].R = 1;    //p    red
				SIU.GPDO[57].R = 1;    //Rx   yellow
				SIU.GPDO[58].R = 1;    //Tx   yellow
				SIU.GPDO[6].R  = 0;    //U3   green
				SIU.GPDO[43].R = 0;    //U2   green
				SIU.GPDO[59].R = 0;    //U1   green
			}
			else if (led_count == 3 )
			{
				SIU.GPDO[56].R = 1;    //p    red
				SIU.GPDO[57].R = 1;    //Rx   yellow
				SIU.GPDO[58].R = 1;    //Tx   yellow
				SIU.GPDO[6].R  = 1;    //U3   green
				SIU.GPDO[43].R = 0;    //U2   green
				SIU.GPDO[59].R = 0;    //U1   green
			}
			else if (led_count == 4)
			{
				SIU.GPDO[56].R = 1;    //p    red
				SIU.GPDO[57].R = 1;    //Rx   yellow
				SIU.GPDO[58].R = 1;    //Tx   yellow
				SIU.GPDO[6].R  = 1;    //U3   green
				SIU.GPDO[43].R = 1;    //U2   green
				SIU.GPDO[59].R = 0;    //U1   green
			}
			else if ( led_count == 5 )
			{
				SIU.GPDO[56].R = 1;    //p    red
				SIU.GPDO[57].R = 1;    //Rx   yellow
				SIU.GPDO[58].R = 1;    //Tx   yellow
				SIU.GPDO[6].R  = 1;    //U3   green
				SIU.GPDO[43].R = 1;    //U2   green
				SIU.GPDO[59].R = 1;    //U1   green
			}
			else
		    {
				// Do nothing
			}

	/*************************************************************************/
}

/* Task-4 implementation *****************************************************/
void task_counter(void){

	/* TO-DO: your task implementations **************************************/
    btn1 = SIU.GPDI[60].R;
	btn2 = SIU.GPDI[61].R;

	int counter_dir = 0; // up counter by default

		if   (btn1 == 1 && btn2 == 0)   { counter_dir = 1;          //up counter
		}
		else if(btn2 == 1 && btn1 == 0) { counter_dir = 0;          // down counter
		}
		if(counter_dir == 1)
		{
			counter++;
			if(counter > 7) {	counter = 0;}
            switch(counter)
			{
			case 0:
				SIU.GPDO[59].R = 0;  /* U1 */
				SIU.GPDO[43].R = 0;  /* U2 */
				SIU.GPDO[6].R  = 0;  /* U3 */
				break;
			case 1:
				SIU.GPDO[59].R = 1;  /* U1 */
				SIU.GPDO[43].R = 0;  /* U2 */
				SIU.GPDO[6].R  = 0;  /* U3 */
				break;
			case 2:
				SIU.GPDO[59].R = 0;  /* U1 */
				SIU.GPDO[43].R = 1;  /* U2 */
				SIU.GPDO[6].R  = 0;  /* U3 */
				break;
			case 3:
				SIU.GPDO[59].R = 1;  /* U1 */
				SIU.GPDO[43].R = 1;  /* U2 */
				SIU.GPDO[6].R  = 0;  /* U3 */
				break;
			case 4:
				SIU.GPDO[59].R = 0;  /* U1 */
				SIU.GPDO[43].R = 0;  /* U2 */
				SIU.GPDO[6].R  = 1;  /* U3 */
				break;
			case 5:
				SIU.GPDO[59].R = 1;  /* U1 */
				SIU.GPDO[43].R = 0;  /* U2 */
				SIU.GPDO[6].R  = 1;  /* U3 */
				break;
			case 6:
				SIU.GPDO[59].R = 0;  /* U1 */
				SIU.GPDO[43].R = 1;  /* U2 */
				SIU.GPDO[6].R  = 1;  /* U3 */
				break;
			case 7:
				SIU.GPDO[59].R = 1;  /* U1 */
				SIU.GPDO[43].R = 1;  /* U2 */
				SIU.GPDO[6].R  = 1;  /* U3 */
				break;
			default:
				SIU.GPDO[59].R = 0;  /* U1 */
				SIU.GPDO[43].R = 0;  /* U2 */
				SIU.GPDO[6].R  = 0;  /* U3 */
				break;
			}
		}
		else if (counter_dir == 0)
		{
			counter--;
			if (counter < 0) {counter = 7;	}
			switch(counter)
			{
				case 0:
				SIU.GPDO[59].R = 1;  /* U1 */
				SIU.GPDO[43].R = 1;  /* U2 */
				SIU.GPDO[6].R  = 1;  /* U3 */
				break;
			case 1:
				SIU.GPDO[59].R = 0;  /* U1 */
				SIU.GPDO[43].R = 1;  /* U2 */
				SIU.GPDO[6].R  = 1;  /* U3 */
				break;
			case 2:
				SIU.GPDO[59].R = 1;  /* U1 */
				SIU.GPDO[43].R = 0;  /* U2 */
				SIU.GPDO[6].R  = 1;  /* U3 */
				break;
			case 3:
				SIU.GPDO[59].R = 0;  /* U1 */
				SIU.GPDO[43].R = 0;  /* U2 */
				SIU.GPDO[6].R  = 1;  /* U3 */
				break;
			case 4:
				SIU.GPDO[59].R = 1;  /* U1 */
				SIU.GPDO[43].R = 1;  /* U2 */
				SIU.GPDO[6].R  = 0;  /* U3 */
				break;
			case 5:
				SIU.GPDO[59].R = 0;  /* U1 */
				SIU.GPDO[43].R = 1;  /* U2 */
				SIU.GPDO[6].R  = 0;  /* U3 */
				break;
			case 6:
				SIU.GPDO[59].R = 1;  /* U1 */
				SIU.GPDO[43].R = 0;  /* U2 */
				SIU.GPDO[6].R  = 0;  /* U3 */
				break;
			case 7:
				SIU.GPDO[59].R = 0;  /* U1 */
				SIU.GPDO[43].R = 0;  /* U2 */
				SIU.GPDO[6].R  = 0;  /* U3 */
				break;
			default:
				SIU.GPDO[59].R = 1;  /* U1 */
				SIU.GPDO[43].R = 1;  /* U2 */
				SIU.GPDO[6].R  = 1;  /* U3 */
				break;
			}
		}else{}

	}

	/*
	 * @brief	Main program
	 *
	 * @param	void
	 * @retval	int
	 */
	int main(void) {
		/* peripherals initialization, do not remove */
		peripheralsInit();

	    // all LEDs = 0
		SIU.GPDO[56].R = 0;  /* P */
		SIU.GPDO[57].R = 0;  /* Rx */
		SIU.GPDO[58].R = 0;  /* Tx */
		SIU.GPDO[59].R = 0;  /* U1 */
		SIU.GPDO[43].R = 0;  /* U2 */
		SIU.GPDO[6].R  = 0;  /* U3 */

	

		/* TO-DO: your task implementations **************************************/


		/* Configure and start timer channels */
	    // PIT_ConfigureTimer(<channel>, <interval in milliseconds>);

		PIT_ConfigureTimer(1, 1000);
		
	    //if(SIU.GPDI[52].R == 0 && SIU.GPDI[53].R == 0 && SIU.GPDI[54].R == 1 && SIU.GPDI[55].R == 1) /* SW1, SW2, SW3 */      		
		//{		
		//PIT_StartTimer(1);
		//}
		
	/*************************************************************************/

	/* main program */
	while(1){
		/* System function */
		systemFunction();
		sw1 = SIU.GPDI[52].R;
		sw2  = SIU.GPDI[53].R;
        sw3 = SIU.GPDI[54].R;
		sw4  = SIU.GPDI[55].R;
		btn1 = SIU.GPDI[60].R;
	    btn2 = SIU.GPDI[61].R;

		/* TO-DO: your task implementations **********************************/

		// check switch 1 is on

		 if  (sw1 == 1 && sw2 == 0 && sw3 == 0 && sw4 == 0 )
		{
			int pot_value = ADC0.CDR[5].R & 0x00000fff;
		    task_pot(pot_value);

		}// check switch 2 is on
		else if (sw1 == 0 && sw2 == 1 && sw3 == 0 && sw4 == 0)
		{
	        int ldr_value = ADC1.CDR[3].R & 0x00000fff;
		    task_ldr(ldr_value);
		}

		else if(sw1 == 0 && sw2 == 0 && sw3 == 1 && sw4 == 1) /* SW1, SW2, SW3 */
		{
			
			PIT_StartTimer(1);
		}
		else
	    {   
			PIT_StopTimer(1);
			//PIT.CHANNEL[1].TFLG.R = 1;
		            
		}
		 
		/*********************************************************************/

		/* 10 ms OS delay */
		osalThreadDelayMilliseconds(10UL);
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

		task_counter();
		
	/*************************************************************************/
}


/*
 * @brief	PIT timer channel 2 IRQ callback
 *
 * @param	void
 * @retval	void
 */
void PIT_Channel_2(void){

	/* TO-DO: your task implementations **************************************/




	/*************************************************************************/
}


/*
 * @brief	PIT timer channel 3 IRQ callback
 *
 * @param	void
 * @retval	void
 */
void PIT_Channel_3(void){

	/* TO-DO: your task implementations **************************************/

	/*************************************************************************/
}


/*
PIT timer is configured to fire every 1000 ms (1 second).

PIT interrupt handler (i.e., PIT_Channel_1) is called automatically every 1 second.

Inside this handler:

	Check if the correct switches are active (SW1=0, SW2=0, SW3=1 → display counter).

	If SW4 is ON, call task_counter() to update the counter.

	Clear the interrupt flag.
*/