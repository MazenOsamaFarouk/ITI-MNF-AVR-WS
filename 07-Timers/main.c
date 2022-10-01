/*
 * main.c
 *
 *  Created on: Sep 24, 2022
 *      Author: mazen
 */


#include "LIB/STD_TYPES.h"
#include "DIO/DIO_interface.h"
#include "EXTI/EXTI_interface.h"
#include "TIMERS/TIMERS_interface.h"
#include "GIE/GIE_interface.h"
#include "LCD/LCD_interface.h"
#include "WDT/WDT_interface.h"

#if 0
void LedToggle(void)
{
	static u32 counter = 0;
	counter++;

	if(counter == 1954*2)
	{
		counter=0;
		TIMERS_vSetPreloadValue(224);
		DIO_vTogglePin(DIO_PORTA, DIO_PIN0);
	}
}

void LedToggle(void)
{
	static u32 counter =0 ;
	counter++;
	if(counter == 4000)
	{
		DIO_vTogglePin(DIO_PORTA, DIO_PIN0);
	}
}
#endif

#if 0
volatile u16 PeriodicTime = 0;
volatile u16 OnTime = 0;

volatile u8 CycleFlag = 0 ;

void ReadPWM(void)
{
	static u8 counter = 0;
	counter++;

	switch(counter)
	{
	case 1:
		TIMERS_vStartTimer(TIMER1);
		EXTI_vSetSenseCtrl(EXTI_0, EXTI_RISING);
		break;

	case 2:
		PeriodicTime = TIMERS_u16GetElapsedTime(TIMER1);
		EXTI_vSetSenseCtrl(EXTI_0, EXTI_FALLING);
		break;

	case 3:
		OnTime  = TIMERS_u16GetElapsedTime(TIMER1) - PeriodicTime ;
		EXTI_vDisableInterrupt(EXTI_0);
		TIMERS_vStopTimer();

		counter = 0;
		CycleFlag = 1 ;
		break;
	}



}


void ReadPWM_ICU(void)
{
	static u8 counter = 0;
	counter++;

	switch(counter)
	{
	case 1:
		TIMERS_vStartTimer(TIMER1);
		TIMERS_vSetICUSenseCtrl(ICU_RISING);
		break;

	case 2:
		PeriodicTime = TIMERS_u16GetICR1();
		TIMERS_vSetICUSenseCtrl(ICU_FALLING);
		break;

	case 3:
		OnTime  = TIMERS_u16GetICR1() - PeriodicTime ;
		TIMERS_vDisableInturrupt(99,99); // Dummy numbers
		TIMERS_vStopTimer();

		counter = 0;
		CycleFlag = 1 ;
		break;
	}



}

#endif
int main(void)
{

#if 0
//	DIO_vWritePinDirection(DIO_PORTA, DIO_PIN0, DIO_OUTPUT);
	DIO_vWritePinDirection(DIO_PORTB, DIO_PIN3, DIO_OUTPUT);
	DIO_vWritePinDirection(DIO_PORTD, DIO_PIN5, DIO_OUTPUT);

	LCD_vInit();
	TIMERS_vInit();
//	EXTI_vRegisterCallback(EXTI_0, ReadPWM );
//	EXTI_vInit();
//	EXTI_vSetSenseCtrl(EXTI_0, EXTI_RISING);
//	TIMERS_vSetCallback(LedToggle);

	GIE_vEnable();


//	TIMERS_vSetCompareMatchValue(250);
//	TIMERS_vSetICR1(624);
	TIMERS_vStartTimer(TIMER0);
	TIMERS_vSetCompareMatchValue(64);
#endif

	DIO_vWritePinDirection(DIO_PORTA, DIO_PIN0, DIO_OUTPUT);
	WDT_vEnable(WDT_PS_1s);
	DIO_vWritePinValue(DIO_PORTA, DIO_PIN0, DIO_HIGH);
	_delay_ms(500);
	DIO_vWritePinValue(DIO_PORTA, DIO_PIN0, DIO_LOW);
	WDT_vDisable();



	while(1)
	{

#if  FADE
		// fade in
		for(u16 i=0; i<255; i++)
		{
			TIMERS_vSetCompareMatchValue(i);
			_delay_ms(4);
		}

		// fade out
		for(u16 i=0; i<255; i++)
		{
			TIMERS_vSetCompareMatchValue(255-i);
			_delay_ms(4);
		}
#endif

#if SERVO_TEST
		for(u16 i=32; i<64; i++)
		{
			TIMERS_vSetCompareMatchValue(i);
			_delay_ms(10);
		}

		// fade out
		for(u16 i=64; i>=32; i--)
		{
			TIMERS_vSetCompareMatchValue(i);
			_delay_ms(10);
		}
#endif


/*
		if(CycleFlag)
		{
			LCD_vSetCursorPosition(0,0);
			LCD_vPrintNumber(PeriodicTime);
			LCD_vSetCursorPosition(1,0);
			LCD_vPrintNumber(OnTime);
			CycleFlag = 0 ;
			TIMERS_vEnableInturrupt(99,99); // dummy numbers
		}
*/


	}
















}
