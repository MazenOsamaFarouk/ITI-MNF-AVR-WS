/*
 * main.c
 *
 *  Created on: Sep 21, 2022
 *      Author: mazen
 */

#include "LIB/STD_TYPES.h"
#include "EXTI/EXTI_interface.h"
#include "DIO/DIO_interface.h"
#include "GIE/GIE_interface.h"

void toggle(void)
{
	DIO_vTogglePin(DIO_PORTA, DIO_PIN0);
}


int main(void)
{
	DIO_vWritePinDirection(DIO_PORTA, DIO_PIN0, DIO_OUTPUT);

	EXTI_vRegisterCallback(EXTI_0, toggle);
	EXTI_vInit();
	GIE_vEnable();

	while(1)
	{

	}
}

