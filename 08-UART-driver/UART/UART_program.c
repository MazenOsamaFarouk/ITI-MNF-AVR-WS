/*
 * UART_program.c
 *
 *  Created on: Oct 7, 2022
 *      Author: mazen
 */
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"


#include "UART_interface.h"
#include "UART_private.h"
#include "UART_config.h"

static void (*GS_UART_RXC_Callback)(void);
static volatile u8 isAvaiableFlag = 0 ;

void UART_vInit(void)
{
	UCSRB = 0b10011000 ;
	u8 ucsrc_setting = 0;
//	SET_BIT(ucsrc_setting, 7);
//	UCSRC = ucsrc_setting ;
	UCSRC = 0b10000110 ;
	UBRRL = 51 ; //9600
	/* 1- Transmiter Enable / Reciever Enable */
	/* 2- Interrupt Enables  */
	/* 2-a RX interrupt enable */
	/* 2-b TX interrupt enable  */
	/* 2-c UDRE interrupt enable */
	/* 3- Charachter size     */
	/* 4- UART Mode (Synch/Asynch)*/
	/* 5- Parity mode (even/odd) */
	/* 6- Stop bits ( 1 or 2) */
}

void UART_vTransmitByte_synch(u8 A_u8Byte)
{
	/* Wait for empty transmit buffer */
	while ( !( UCSRA & (1<<UDRE)) )
	;
	/* Put data into buffer, sends the data */
	UDR = A_u8Byte;
}

u8   UART_u8RecieveByte_synch (void)
{
	/* Wait for data to be received */
	while ( !(UCSRA & (1<<RXC)) )
	;
	/* Get and return received data from buffer */
	return UDR;
}

void UART_vPrintString(char str[])
{
	while(*str != '\0')
	{
		UART_vTransmitByte_synch(*str);
		str++ ;
	}
}

void UART_vReadString(char str[] ,  u32 size)
{
	for(u32 i=0; i<size-1; i++)
	{
		str[i] = UART_u8RecieveByte_synch();
		if(str[i] == '\n' || str[i] == '\r' )
		{
			str[i] = '\0' ;
			break;
		}
	}
	str[size-1] = '\0';
}

void UART_vSetCallback (u8 A_u8SourceId, void (*fptr)(u8))
{
	GS_UART_RXC_Callback = fptr;
}

u8   UART_vIsAvaialable(void)
{
	return isAvaiableFlag ;
}


u8   UART_u8GetUDRValue(void)
{
	return UDR;
}

void __vector_13(void) __attribute__((signal));
void __vector_13(void)
{
	if(GS_UART_RXC_Callback != NULL)
	{
		GS_UART_RXC_Callback(UDR);
	}
	isAvaiableFlag = 1 ;
}








