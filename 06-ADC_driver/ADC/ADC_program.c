/*
 * ADC_program.c
 *
 *  Created on: Sep 23, 2022
 *      Author: mazen
 */

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"


#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"

void ADC_vInit(void)
{
	/* 1- select reference bits  */
	ADMUX &= ~(0b11 <<6);
	ADMUX |=  (ADC_VREF << 6 ) ;
	/* 2- select data adjustment */
	CLR_BIT(ADMUX,  5); // right adjustment
	/* 3- ADC Enable   */
	SET_BIT(ADCSRA, 7);
	/* 4- Auto trigger enable/disable */
	CLR_BIT(ADCSRA, 5);
	/* 4-a- select Auto trigger Source */

	/* 5- Interrupt enable/Disable  */
	CLR_BIT(ADCSRA, 3);
	/* 6- Conv. clock Prescaler */
	ADCSRA &= ~(0b111);
	ADCSRA |= (0b110) ;
}

u16  ADC_vReadDigitalValue_synch(u8 A_u8Channel)
{
	/* 1- select channel */
	ADMUX &= ~(0b11111) ;
	ADMUX |= (A_u8Channel & 0x07) ;
	         // A_u8Channel %8
	/* 2- start conversion */
	SET_BIT(ADCSRA, ADSC); // bit-6
	/* 3- wait for conv. complete flag*/
	while(GET_BIT(ADCSRA, ADIF) == 0){}
	/* 4- clear flag   */
	SET_BIT(ADCSRA, ADIF);
	/* 5- return ADC value */
	return ADC_DATA ;
}
