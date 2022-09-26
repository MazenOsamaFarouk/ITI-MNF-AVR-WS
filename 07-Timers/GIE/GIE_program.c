/*
 * GIE_program.c
 *
 *  Created on: Sep 23, 2022
 *      Author: mazen
 */


#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"


#include "GIE_interface.h"
#include "GIE_private.h"
#include "GIE_config.h"


void GIE_vEnable(void)
{
	SET_BIT(SREG, I_BIT);
}

void GIE_vDisable(void)
{
	CLR_BIT(SREG, I_BIT);
}
