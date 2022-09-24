/*
 * DCM_interface.h
 *
 *  Created on: Sep 17, 2022
 *      Author: mazen
 */

#ifndef DCM_DCM_INTERFACE_H_
#define DCM_DCM_INTERFACE_H_

typedef enum
{
	CW,CCW,STOP
}DCM_Dir_t;


typedef struct
{
	u8 Port;
	u8 PinA;
	u8 PinB;
	u8 Speed;
	DCM_Dir_t Direction;
}DCM_t;





void DCM_vInit(DCM_t* me,
		      u8 Port,
			  u8 PinA,
			  u8 PinB);

void DCM_vSetSpeed(DCM_t* me, u16 Speed);
void DCM_vSetDirection(DCM_t* me ,DCM_Dir_t  dir );
void DCM_vRun(DCM_t* me);

/// method 2:

void DCM_vMove(DCM_t*me, s16 speed );








#endif /* DCM_DCM_INTERFACE_H_ */
