/*
 * main.c
 *
 *  Created on: Oct 14, 2022
 *      Author: mazen
 */


#include "LIB/STD_TYPES.h"
#include "TWI/TWI_interface.h"

#define EEPROM_SLA 0b01010000

void EEPROM_vWriteByte(u8 A_u8Byte, u16 A_u16WordAddress)
{
	TWI_u8SendStartCondition();
	TWI_u8SendSlaveAddress(EEPROM_SLA , TWI_WRITE );
	TWI_u8SendByte(A_u16WordAddress & 0x00ff);
	TWI_u8SendByte(A_u8Byte);
	TWI_u8SendStopCondition();
}

void EEPROM_vReadByte(u8* A_u8Byte, u16 A_u16WordAddress)
{
	TWI_u8SendStartCondition();
	TWI_u8SendSlaveAddress(EEPROM_SLA , TWI_WRITE );
	TWI_u8SendByte(A_u16WordAddress & 0x00ff);
	TWI_u8SendRepeatedStart();
	TWI_u8SendSlaveAddress(EEPROM_SLA , TWI_READ);
	TWI_u8RecvByte(A_u8Byte, TWI_NACK);
	TWI_u8SendStopCondition();
}

int main(void)
{
	TWI_vInit();






	while(1)
	{

	}
}
