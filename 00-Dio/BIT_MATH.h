#ifndef _BIT_MATH_H_
#define _BIT_MATH_H_


#define SET_BIT(VAR,BITNO) (VAR) |=  (1 << (BITNO))
#define CLR_BIT(VAR,BITNO) (VAR) &= ~(1 << (BITNO))
#define TOG_BIT(VAR,BITNO) (VAR) ^=  (1 << (BITNO))
#define GET_BIT(VAR,BITNO) (((VAR) >> (BITNO)) & 0x01)


#define HIGH 1
#define LOW 0

#define Enable 	1
#define Disable 0

#include <avr/delay.h>


#endif
