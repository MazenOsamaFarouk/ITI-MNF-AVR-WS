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
#if TIMER0_ENABLE==ENABLE
	/* 1- Select wave generation mode */
	/* PWM: select Fast WPM mode */
	SET_BIT(TCCR0, WGM00);
	SET_BIT(TCCR0, WGM01);
	/* 2- Output compare mode  */
	/* PWM: Non-Inverting Mode  */

	CLR_BIT(TCCR0, COM00);
	SET_BIT(TCCR0, COM01);
	/* 3- Preload  */
	TCNT0 = TIMER0_PRELOAD ;
	/* 4- Interrupt EN/DIS   */
	//	SET_BIT(TIMSK, TOV0);
	//	SET_BIT(TIMSK, OCIE0);
	/* PWM: Disable Interrupts */
#endif

	SET_BIT(TCCR1B, 4); //WGM13
	SET_BIT(TCCR1B, 3); //WGM12
	SET_BIT(TCCR1A, 1); //WGM11
	CLR_BIT(TCCR1A, 0); //WGM10

	SET_BIT(TCCR1A,7); // COM1A1
	CLR_BIT(TCCR1A,6); // COM1A0




}

void TIMERS_vSetBusyWait_synch(/* TimerId  ,*/ u32 A_u32Ticks)
{

}


void TIMERS_vStartTimer(u8 A_u8TimerId)
{
	switch(A_u8TimerId)
	{
	case TIMER0:
		TCCR0 = (TCCR0 & ~(0b111)) | (TIMER0_PRESCALER) ;
		break;
	case TIMER1:
		TCCR1B = (TCCR1B & ~(0b111)) | (TIMER1_PRESCALER) ;
		break;
	}
}

void TIMERS_vStopTimer(u8 A_u8TimerId)
{
	switch(A_u8TimerId)
	{
	case TIMER0:
		TCCR0 = (TCCR0 & ~(0b111)) | (PS_NOCLK) ;
		break;
	case TIMER1:
		TCCR1B = (TCCR1B & ~(0b111)) | (PS_NOCLK) ;
		break;
	}
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



void TIMERS_vSetPreloadValue(u8 A_u8TimerId, u16 A_u16Preload)
{
	switch(A_u8TimerId)
	{
	case TIMER0:
		TCNT0 = A_u16Preload;
		break;

	case TIMER1:
		TCNT1 = A_u16Preload;
		break;
	}


}

void TIMERS_vSetCompareMatchValue(u8 A_u8TimerId, u16 A_u16OcrVal    )
{
	switch(A_u8TimerId)
	{
	case TIMER0:
		OCR0 = A_u16OcrVal ;
		break;

	case TIMER1:
		OCR1A = A_u16OcrVal ;
		break;
	}

}

void TIMERS_vSetICR1(u16 A_16IcrValue)
{
	ICR1 = A_16IcrValue;
}








