/*
 * WDT_program.c
 *
 *  Created on: Oct 1, 2022
 *      Author: mazen
 */


#include "../LIB/STD_TYPES.h"

#include "WDT_interface.h"
#include "WDT_private.h"
#include "WDT_config.h"

void WDT_vEnable(u8 A_u8Timeout)
{
	WDTCR = (WDTCR & ~(0b111)) | A_u8Timeout ;
	SET_BIT(WDTCR, 3); // WDE
}

void WDT_vDisable(void)
{
	WDTCR = 0b00011000 ;
	WDTCR = 0 ;
}












