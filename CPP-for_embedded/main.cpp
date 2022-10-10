/*
 * main.cpp
 *
 *  Created on: Oct 8, 2022
 *      Author: mazen
 */

#include "LIB/STD_TYPES.h"
#include "cDIO/cDIO.h"


#include <util/delay.h>

int main(void)
{
	cDIO DIO ;

	DIO.setPinDir(0,0,1);
	while(1)
	{
		DIO.setPinVal(0,0,1);
		_delay_ms(500);
		DIO.setPinVal(0,0,0);
		_delay_ms(500);
	}

}
