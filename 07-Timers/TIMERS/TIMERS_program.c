/*
 * TIERMS_program.c
 *
 *  Created on: Sep 24, 2022
 *      Author: mazen
 */

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"


#include "TIMERS_interface.h"
#include "TIMERS_private.h"
#include "TIMERS_config.h"

static void (*TIMER0_OVF_Callback)(void) ;
static void (*TIMER0_CTC_Callback)(void) ;


void TIMERS_vInit(void)
{
	/* 1- Select wave generation mode */
	/* PWM: select Fast WPM mode */
	CLR_BIT(TCCR0, WGM00);
	SET_BIT(TCCR0, WGM01);
	/* 2- Output compare mode  */
	/* PWM: Non-Inverting Mode  */

	CLR_BIT(TCCR0, COM00);
	CLR_BIT(TCCR0, COM01);
	/* 3- Preload  */
	TCNT0 = TIMER0_PRELOAD ;
	/* 4- Interrupt EN/DIS   */
//	SET_BIT(TIMSK, TOV0);
//	SET_BIT(TIMSK, OCIE0);
	/* PWM: Disable Interrupts */
}

void TIMERS_vSetBusyWait_synch(/* TimerId  ,*/ u32 A_u32Ticks)
{

}


void TIMERS_vStartTimer(/* TimerId  ,*/ void)
{
	TCCR0 = (TCCR0 & ~(0b111)) | (TIMER0_PRESCALER) ;
}

void TIMERS_vStopTimer(/* TimerId  ,*/ void)
{
	TCCR0 = (TCCR0 & ~(0b111)) | (PS_NOCLK) ;
}

void TIMERS_vSetCallback(/* TimerId  ,*/ void (*fptr)(void))
{
//	TIMER0_OVF_Callback = fptr ;
	TIMER0_CTC_Callback = fptr ;
}

void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
	if(TIMER0_OVF_Callback != NULL)
	{
		TIMER0_OVF_Callback();
	}
}

void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
	if(TIMER0_CTC_Callback != NULL)
	{
		TIMER0_CTC_Callback();
	}
}



void TIMERS_vSetPreloadValue(/* TimerId  ,*/ u16 A_u16Preload)
{
	TCNT0 = A_u16Preload;
}

void TIMERS_vSetCompareMatchValue(/* TimerId  ,*/ u16 A_u16OcrVal    )
{
	OCR0 = A_u16OcrVal ;
}








