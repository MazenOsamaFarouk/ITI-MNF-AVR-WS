/*
 * main.c
 *
 *  Created on: Sep 16, 2022
 *      Author: mazen
 */

#include "LIB/STD_TYPES.h"

#include "DIO/DIO_interface.h"


int main(void)
{
	DIO_vWritePinDirection(DIO_PORTA,DIO_PIN5,DIO_OUTPUT);
	while(1)
	{

	}

}
