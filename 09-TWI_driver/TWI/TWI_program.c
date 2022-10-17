/*
 * TWI_program.c
 *
 *  Created on: Oct 14, 2022
 *      Author: mazen
 */

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"



#include "TWI_interface.h"
#include "TWI_private.h"
#include "TWI_config.h"


void TWI_vInit(void)
{
	/* 1- Bit rate (TWBR)  */
	TWBR = 10;
	TWSR |= (0<<0)|(0<<1) ; // TWPS (PRescaler bits)
	/* 2- Own slave Address */
	TWAR = TWI_OWN_SLA ;
}

u8   TWI_u8SendStartCondition(void)
{
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while (!(TWCR & (1<<TWINT)))
	;
	return (TWSR & 0xF8);
}

u8   TWI_u8SendSlaveAddress(u8 A_u8Sla, u8 A_u8Rw)
{
	TWDR = (A_u8Sla<<1) | A_u8Rw;
	CLR_BIT(TWCR, TWSTA); // clear start bit
	TWCR = (1<<TWINT) | (1<<TWEN);
	while (!(TWCR & (1<<TWINT)))
		;
	return (TWSR & 0xF8);
}

u8   TWI_u8SendByte(u8 A_u8Byte)
{
	TWDR = A_u8Byte;
	TWCR = (1<<TWINT) | (1<<TWEN);
	while (!(TWCR & (1<<TWINT)))
			;
	return (TWSR & 0xF8);
}

u8   TWI_u8SendStopCondition(void)
{
	TWCR = (1<<TWINT)|(1<<TWEN)|
	(1<<TWSTO);

	return (TWSR & 0xF8);
}

u8   TWI_u8RecvByte(u8* A_pu8Byte, u8 A_u8Ack)
{
	if(A_u8Ack)
	{
		TWCR |= (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	}
	else
	{
		TWCR |= (1<<TWINT)|(1<<TWEN);
		CLR_BIT(TWCR, TWEA);
	}
	while (!(TWCR & (1<<TWINT)))
				;

	*A_pu8Byte = TWDR ;

	return (TWSR & 0xF8);
}



u8   TWI_u8SendRepeatedStart(void)
{
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while (!(TWCR & (1<<TWINT)))
	;
	return (TWSR & 0xF8);
}

u8   TWI_u8GetStatusCode(void)
{
	return (TWSR & 0xF8);
}







