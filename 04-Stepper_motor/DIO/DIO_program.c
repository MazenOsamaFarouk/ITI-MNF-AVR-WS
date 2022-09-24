/*
 * DIO_prgram.c
 *
 *  Created on: Sep 16, 2022
 *      Author: mazen
 */


#include "../LIB/STD_TYPES.h"



#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"




void DIO_vWritePinDirection(u8 A_u8PortId,u8 A_u8PinNo,u8 A_u8Direction )
{
	if(A_u8Direction == DIO_OUTPUT)
	{
		switch(A_u8PortId)
		{
		case DIO_PORTA:
			SET_BIT(DDRA, A_u8PinNo) ;
			break;
		case DIO_PORTB:
			SET_BIT(DDRB, A_u8PinNo) ;
			break;
		case DIO_PORTC:
			SET_BIT(DDRC, A_u8PinNo) ;
			break;
		case DIO_PORTD:
			SET_BIT(DDRD, A_u8PinNo) ;
			break;
		}
	}
	else if (A_u8Direction == DIO_INPUT)
	{
		switch(A_u8PortId)
		{
		case DIO_PORTA:
			CLR_BIT(DDRA, A_u8PinNo) ;
			break;
		case DIO_PORTB:
			CLR_BIT(DDRB, A_u8PinNo) ;
			break;
		case DIO_PORTC:
			CLR_BIT(DDRC, A_u8PinNo) ;
			break;
		case DIO_PORTD:
			CLR_BIT(DDRD, A_u8PinNo) ;
			break;
		}
	}
}

void DIO_vWritePinValue(u8 A_u8PortId,u8 A_u8PinNo,u8 A_u8Value)
{
	if(A_u8Value == DIO_HIGH)
	{
		switch(A_u8PortId)
		{
		case DIO_PORTA:
			SET_BIT(PORTA, A_u8PinNo) ;
			break;
		case DIO_PORTB:
			SET_BIT(PORTB, A_u8PinNo) ;
			break;
		case DIO_PORTC:
			SET_BIT(PORTC, A_u8PinNo) ;
			break;
		case DIO_PORTD:
			SET_BIT(PORTD, A_u8PinNo) ;
			break;
		}
	}
	else if (A_u8Value == DIO_LOW)
	{
		switch(A_u8PortId)
		{
		case DIO_PORTA:
			CLR_BIT(PORTA, A_u8PinNo) ;
			break;
		case DIO_PORTB:
			CLR_BIT(PORTB, A_u8PinNo) ;
			break;
		case DIO_PORTC:
			CLR_BIT(PORTC, A_u8PinNo) ;
			break;
		case DIO_PORTD:
			CLR_BIT(PORTD, A_u8PinNo) ;
			break;
		}
	}
}

u8   DIO_u8ReadPinValue(u8 A_u8PortId,u8 A_u8PinNo)
{
	u8 L_u8PinValue = 0;

	switch(A_u8PortId)
	{
	case DIO_PORTA:
		L_u8PinValue = GET_BIT(PINA, A_u8PinNo);
		break;
	}



	return L_u8PinValue;
}

void DIO_vTogglePin(u8 A_u8PortId,u8 A_u8PinNo)
{


}


void DIO_vWritePortDirection(u8 A_u8PortId,u8 A_u8Direction)
{

}

void DIO_vWritePortValue(u8 A_u8PortId,u8 A_u8Value)
{

}

u8   DIO_u8ReadPortValue(u8 A_u8PortId)
{

}
