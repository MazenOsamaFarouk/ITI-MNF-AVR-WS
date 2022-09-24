/*
 * main.c
 *
 *  Created on: Sep 2, 2022
 *      Author: mazen
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include <avr/io.h>
#include <util/delay.h>

#define SNAKE       0
#define PINGPONG    0
#define DIPSW		0
#define SSD			1

int main(void)
{
	u8 SSD_numbers[]={
			0b11111100,
			0b01100000,
			0b11011010,
			0b11110010,
			0b01100110
	};




	DDRA = 0xff ; // 0b11111111
	CLR_BIT(DDRD, 0); // input
	SET_BIT(PORTD, 0); // activate pull up resistor
	while(1)
	{
#if 0
		SET_BIT(PORTA, 0);
		_delay_ms(1000) ;
		CLR_BIT(PORTA, 0) ;
		_delay_ms(1000) ;
#endif

#if SNAKE
		for(int i=0; i<8; i++)
		{
			set_bit(PORTA, i);
			_delay_ms(200);
		}

		for(int i=0; i<8; i++)
		{
			clr_bit(PORTA, i);
			_delay_ms(200);
		}
#endif

#if PINGPONG
		// ping
		for(int i=0; i<8; i++)
		{
			set_bit(PORTA,i);
			_delay_ms(200);
			clr_bit(PORTA,i);
		}

		// pong
		for(int i=0; i<8; i++)
		{
			set_bit(PORTA,7-i);
			_delay_ms(200);
			clr_bit(PORTA,7-i);
		}




#endif

#if DIPSW

		if(GET_BIT(PIND, 0) == 0) // switch is closed
		{
			SET_BIT(PORTA, PIN0);
		}
		else
		{
			CLR_BIT(PORTA, PIN0);
		}

#endif


#if SSD



#endif

		for(int i=0; i<6; i++)
		{
			PORTA = ~SSD_numbers[i];
		}





	}




}

