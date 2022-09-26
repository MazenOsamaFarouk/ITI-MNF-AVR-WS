/*
 * TIMERS_private.h
 *
 *  Created on: Sep 24, 2022
 *      Author: mazen
 */

#ifndef TIMERS_TIMERS_PRIVATE_H_
#define TIMERS_TIMERS_PRIVATE_H_

#define WGM00       6
#define WGM01		3
#define COM00       4
#define COM01		5
#define TOV0        0


#define PS_NOCLK	0b000
#define PS_1		0b001
#define PS_8		0b010





#define TCCR0  *((volatile u8*)(0x53))
#define TCNT0  *((volatile u8*)(0x52))
#define OCR0   *((volatile u8*)(0x5C))
#define TIMSK  *((volatile u8*)(0x59))
#define TIFR   *((volatile u8*)(0x58))




#endif /* TIMERS_TIMERS_PRIVATE_H_ */
