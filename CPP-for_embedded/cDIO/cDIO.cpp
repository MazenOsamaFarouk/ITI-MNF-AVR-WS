/*
 * cDIO.cpp
 *
 *  Created on: Oct 8, 2022
 *      Author: mazen
 */

#include "../LIB/STD_TYPES.h"

#include "../DIO/DIO_interface.h"

#include "cDIO.h"



void cDIO::setPinDir(u8 port, u8 pin, u8 dir)
{
	DIO_vWritePinDirection(port, pin, dir);
}
void  cDIO::setPinVal(u8 port, u8 pin, u8 val)
{
	DIO_vWritePinValue(port, pin, val);
}
