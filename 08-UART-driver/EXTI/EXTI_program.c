/*
 * EXTI_program.c
 *
 *  Created on: Sep 21, 2022
 *      Author: mazen
 */


#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "../DIO/DIO_interface.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"





static void (*G_EXTI0_Callback)(void) ;
static void (*G_EXTI1_Callback)(void) ;
static void (*G_EXTI2_Callback)(void) ;

void EXTI_vInit(void)
{
	/* 1- make pins input */
	DIO_vWritePinDirection(DIO_PORTD, DIO_PIN2, DIO_INPUT);
	DIO_vWritePinValue(DIO_PORTD, DIO_PIN2, DIO_HIGH);
	/* 2- sense control   */
	SET_BIT(MCUCR, 1);
	CLR_BIT(MCUCR, 0);
	/* 3- enable interrupt */
	SET_BIT(GICR, 6);
}

void EXTI_vSetSenseCtrl(u8 A_u8ExtiPin, u8 A_u8SenseCtrl)
{

}

void EXTI_vEnableInterrupt(u8 A_u8ExtiPin, u8 A_u8SenseCtrl )
{

}

void EXTI_vDisableInterrupt(u8 A_u8ExtiPin )
{

}
void EXTI_vRegisterCallback(u8 A_u8ExtiPin, void (*fptr)(void))
{
	switch(A_u8ExtiPin)
	{
	case EXTI_0:
		G_EXTI0_Callback = fptr ;
		break;
	}
}




void __vector_1 (void) __attribute__((signal));
void __vector_1 (void)
{
	if(G_EXTI0_Callback != NULL)
	{
		G_EXTI0_Callback();
	}
}









