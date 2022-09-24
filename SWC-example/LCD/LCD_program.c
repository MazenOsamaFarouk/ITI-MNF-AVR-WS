/*
 * LCD_program.c
 *
 *  Created on: Sep 16, 2022
 *      Author: mazen
 */


#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "../DIO/DIO_interface.h"

#include "LCD_interface.h"
#include "LCD_private.h"
#include "LCD_config.h"


void LCD_vSendChar(u8 A_u8character)
{
	/* select RS -> 1 */
//		SET_BIT(LCD_DATA_PORT, PIN0);
	DIO_vWritePinValue(LCD_CTRL_PORT,LCD_RS_PIN, DIO_HIGH);
		/* select RW -> 0 */
		CLR_BIT(LCD_DATA_PORT, PIN1);
		/* Put data on LCD pins */
//		LCD_DATA_PORT = character;
	DIO_vWritePortValue(LCD_DATA_PORT, A_u8character);
		/* pulse on Enable */
		SET_BIT(LCD_DATA_PORT, PIN2);
		_delay_ms(1);
		CLR_BIT(LCD_DATA_PORT, PIN2);
		_delay_ms(1);
}

void LCD_vSendCommand(u8 A_u8cmd)
{
	/* select RS -> 0 */
		CLR_BIT(LCD_DATA_PORT, PIN0);
		/* select RW -> 0 */
		CLR_BIT(LCD_DATA_PORT, PIN1);
		/* Put data on LCD pins */
		LCD_CTRL_PORT = cmd;
		/* pulse on Enable */
		SET_BIT(LCD_DATA_PORT, PIN2);
		_delay_ms(1);
		CLR_BIT(LCD_DATA_PORT, PIN2);
		_delay_ms(1);
}

void LCD_vInit(void)
{
//	LCD_DATA_DDR = 0xff ;
	DIO_vWritePortDirection(LCD_DATA_PORT, 0xff);
	SET_BIT(LCD_CTRL_DDR, PIN0);
	SET_BIT(LCD_CTRL_DDR, PIN1);
	SET_BIT(LCD_CTRL_DDR, PIN2);

	_delay_ms(50);

	LCD_sendCommand(0b00111000);
	_delay_ms(1) ;
	LCD_sendCommand(0b00001100);
	_delay_ms(1) ;
	LCD_sendCommand(0b00000001);
	_delay_ms(2) ;
	LCD_sendCommand(0b00000110);
	_delay_ms(1) ;
}

void LCD_vDisplayCustomChar(u8 A_u8CharId)
{
	if(CharId < 8)
	{
		LCD_sendChar(CharId);
	}
}

void LCD_vSaveCustomChar(u8 A_pu8CharArr[], u8 A_u8CharId)
{
	if(A_u8CharId < 8)
	{
		LCD_sendCommand(0b01000000 + (8*CharId) );
		for(int i=0; i<8; i++)
		{
			LCD_sendChar(A_pu8CharArr[i]);
		}
		LCD_sendCommand(0b10000000);
	}
}



