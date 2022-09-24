/*
 * main.c
 *
 *  Created on: Sep 17, 2022
 *      Author: mazen
 */

#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

#include "DIO/DIO_interface.h"
#include <util/delay.h>

int main(void)
{
	DIO_vWritePortDirection(DIO_PORTA, 0x0f);

u8 steps[] = {
		0b1000,
		0b0100,
		0b0010,
		0b0001
};


	while(1)
	{

		// one revolution of stepper motor (without gear ratio)
		for(int i=0; i<64; i++)
		{
			DIO_vWritePortValue(DIO_PORTA, steps[i%4]);
			_delay_ms(2);
		}



	}

}
