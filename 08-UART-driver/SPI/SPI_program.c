/*
 * SPI_program.c
 *
 *  Created on: Oct 8, 2022
 *      Author: mazen
 */


#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "../DIO/DIO_interface.h"


#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"

void SPI_vInit(void)
{
	SPCR = 0b01011100 ;
	DIO_vWritePinDirection(DIO_PORTB, DIO_PIN5  ,DIO_OUTPUT ); // MOSI
	DIO_vWritePinDirection(DIO_PORTB, DIO_PIN7 , DIO_OUTPUT); // SCK
	DIO_vWritePinDirection(DIO_PORTB, DIO_PIN6  , DIO_INPUT);  // MISO

	/* 1- SPI Enable */
	/* 2- SPI Interrupt enable */
	/* 3- Data order   */
	/* 4- SPI Master/slave */
	/* 5- SPI Mode */
		/* 5-a CPOL   */
		/* 5-b CPHA   */
	/* 6- Baud Rate  */
}

u8   SPI_u8Transceive(u8 A_u8Byte)
{
	/* Start transmission */
	SPDR = A_u8Byte;
	/* Wait for transmission complete */
	while(!(SPSR & (1<<SPIF)))
	;


	return SPDR ;
}


