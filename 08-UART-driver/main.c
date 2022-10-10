/*
 * main.c
 *
 *  Created on: Oct 7, 2022
 *      Author: mazen
 */


#include "LIB/STD_TYPES.h"
#include "DIO/DIO_interface.h"

#include "UART/UART_interface.h"
#include "SPI/SPI_interface.h"
//#include "GIE/GIE_interface.h"

volatile char buffer[50];
volatile u8 uart_flag = 0;
void uart_cb(u8 data)
{
	static u32 buffer_idx = 0;

	buffer[buffer_idx ] = data;
	buffer_idx++ ;
	if(buffer_idx == sizeof(buffer)/sizeof(buffer[0])-1 ||
	   buffer[buffer_idx ] == '\n' ||
	   buffer[buffer_idx ] == '\r')
	{
		buffer[buffer_idx ] = '\0' ;
		buffer_idx = 0;
		uart_flag = 1 ;
	}
}


int main(void)
{

#if 0
	UART_vInit();
	UART_vSetCallback(99, uart_cb); // dummy number
//	u8  c = UART_u8RecieveByte_synch();
//	UART_vTransmitByte_synch(c);
	GIE_vEnable();

	while(1)
	{
		if(uart_flag == 1)
		{
			uart_flag = 0;
			UARTv_PrintString(buffer);
		}
	}
#endif


	SPI_vInit();
	DIO_vWritePinDirection(DIO_PORTA, DIO_PIN0, DIO_OUTPUT);

	u8 c = 0;

	c = SPI_u8Transceive('M');
	if(c == 'M')
	{
		DIO_vWritePinValue(DIO_PORTA, DIO_PIN0, DIO_HIGH);
	}
	else
	{
		DIO_vWritePinValue(DIO_PORTA, DIO_PIN0, DIO_LOW);
	}



	while(1)
	{

	}



}

