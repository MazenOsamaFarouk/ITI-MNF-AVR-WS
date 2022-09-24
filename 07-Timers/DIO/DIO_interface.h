/*
 * DIO_inerface.h
 *
 *  Created on: Sep 16, 2022
 *      Author: mazen
 */

#ifndef DIO_DIO_INTERFACE_H_
#define DIO_DIO_INTERFACE_H_

#define DIO_PORTA   0
#define DIO_PORTB   1
#define DIO_PORTC   2
#define DIO_PORTD   3

#define DIO_PIN0    0
#define DIO_PIN1    1
#define DIO_PIN2    2
#define DIO_PIN3    3
#define DIO_PIN4    4
#define DIO_PIN5    5
#define DIO_PIN6    6
#define DIO_PIN7    7

#define DIO_OUTPUT	1
#define DIO_INPUT	0


#define DIO_HIGH    1
#define DIO_LOW		0




void DIO_vWritePinDirection(u8 A_u8PortId,u8 A_u8PinNo,u8 A_u8Direction );
void DIO_vWritePinValue(u8 A_u8PortId,u8 A_u8PinNo,u8 A_u8Value);
u8   DIO_u8ReadPinValue(u8 A_u8PortId,u8 A_u8PinNo);
void DIO_vTogglePin(u8 A_u8PortId,u8 A_u8PinNo);

void DIO_vWritePortDirection(u8 A_u8PortId,u8 A_u8Direction);
void DIO_vWritePortValue(u8 A_u8PortId,u8 A_u8Value);
u8   DIO_u8ReadPortValue(u8 A_u8PortId);


#endif /* DIO_DIO_INTERFACE_H_ */
