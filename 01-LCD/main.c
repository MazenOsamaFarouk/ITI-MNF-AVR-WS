/*
 * main.c
 *
 *  Created on: Sep 3, 2022
 *      Author: mazen
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <avr/io.h>
#include <util/delay.h>


void LCD_sendChar(u8 character)
{
	/* select RS -> 1 */
	SET_BIT(PORTA, PIN0);
	/* select RW -> 0 */
	CLR_BIT(PORTA, PIN1);
	/* Put data on LCD pins */
	PORTB = character;
	/* pulse on Enable */
	SET_BIT(PORTA, PIN2);
	_delay_ms(1);
	CLR_BIT(PORTA, PIN2);
	_delay_ms(1);

}

void LCD_sendCommand(u8 cmd)
{
	/* select RS -> 0 */
	CLR_BIT(PORTA, PIN0);
	/* select RW -> 0 */
	CLR_BIT(PORTA, PIN1);
	/* Put data on LCD pins */
	PORTB = cmd;
	/* pulse on Enable */
	SET_BIT(PORTA, PIN2);
	_delay_ms(1);
	CLR_BIT(PORTA, PIN2);
	_delay_ms(1);
}

void DisplayCustomChar(u8 CharId)
{
	if(CharId < 8)
	{
		LCD_sendChar(CharId);
	}
}

void SaveCustomChar(u8 CharArr[], u8 CharId)
{
	if(CharId < 8)
	{
		LCD_sendCommand(0b01000000 + (8*CharId) );
		for(int i=0; i<8; i++)
		{
			LCD_sendChar(CharArr[i]);
		}
		LCD_sendCommand(0b10000000);
	}
}






void LCD_Init(void)
{
	DDRB = 0xff ;
	SET_BIT(DDRA, PIN0);
	SET_BIT(DDRA, PIN1);
	SET_BIT(DDRA, PIN2);

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



int main(void)
{
	u8 meem[] = {0x00,0x00,0x07,0x05,0x0D,0x17,0x00,0x00};


	LCD_Init();

//	LCD_sendChar('M');

	SaveCustomChar(meem, 0);
	DisplayCustomChar(0);
	DisplayCustomChar(0);

	while(1)
	{

	}
}
