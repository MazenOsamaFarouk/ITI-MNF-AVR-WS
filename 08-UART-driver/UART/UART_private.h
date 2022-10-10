/*
 * UART_private.h
 *
 *  Created on: Oct 7, 2022
 *      Author: mazen
 */

#ifndef UART_UART_PRIVATE_H_
#define UART_UART_PRIVATE_H_


#define UDRE	5
#define RXC     7


#define UDR        	 *((volatile u8*)(0x2C))
#define UCSRA        *((volatile u8*)(0x2B))
#define UCSRB        *((volatile u8*)(0x2A))
#define UCSRC        *((volatile u8*)(0x40))
#define UBRRL        *((volatile u8*)(0x29))
#define UBRRH        *((volatile u8*)(0x40))




#endif /* UART_UART_PRIVATE_H_ */
