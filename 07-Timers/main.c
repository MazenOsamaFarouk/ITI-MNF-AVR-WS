/*
 * main.c
 *
 *  Created on: Sep 24, 2022
 *      Author: mazen
 */


#include "LIB/STD_TYPES.h"
#include "DIO/DIO_interface.h"
#include "TIMERS/TIMERS_interface.h"
#include "GIE/GIE_interface.h"

#if 0
void LedToggle(void)
{
	static u32 counter = 0;
	counter++;

	if(counter == 1954*2)
	{
		counter=0;
		TIMERS_vSetPreloadValue(224);
		DIO_vTogglePin(DIO_PORTA, DIO_PIN0);
	}
}
#endif


void LedToggle(void)
{
	static u32 counter =0 ;
	counter++;
	if(counter == 4000)
	{
		DIO_vTogglePin(DIO_PORTA, DIO_PIN0);
	}
}
int main(void)
{
	DIO_vWritePinDirection(DIO_PORTA, DIO_PIN0, DIO_OUTPUT);

	TIMERS_vInit();
	TIMERS_vSetCallback(LedToggle);

	GIE_vEnable();


	TIMERS_vSetCompareMatchValue(250);
	TIMERS_vStartTimer();


	while(1)
	{

	}

}
