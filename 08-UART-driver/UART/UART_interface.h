/*
 * UART_interface.h
 *
 *  Created on: Oct 7, 2022
 *      Author: mazen
 */

#ifndef UART_UART_INTERFACE_H_
#define UART_UART_INTERFACE_H_

void UART_vInit(void);
void UART_vTransmitByte_synch(u8 A_u8Byte);
u8   UART_u8RecieveByte_synch (void);
void UART_vSetBaudRate(u32 A_u32BaudRate);
void UART_vPrintString(char str[]);
void UART_vReadString(char str[] ,  u32 size);
u8   UART_u8GetUDRValue(void);
void UART_vSetCallback (u8 A_u8SourceId, void (*fptr)(u8));
u8   UART_vIsAvaialable(void);





#endif /* UART_UART_INTERFACE_H_ */
