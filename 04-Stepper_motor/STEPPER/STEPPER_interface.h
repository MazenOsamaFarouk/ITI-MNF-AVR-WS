/*
 * STEPPER_interface.h
 *
 *  Created on: Sep 17, 2022
 *      Author: mazen
 */

#ifndef STEPPER_STEPPER_INTERFACE_H_
#define STEPPER_STEPPER_INTERFACE_H_

typedef struct
{
	u8 Port;
	u8 pin[4] ;
	s16 Angle;
}Stepper_t;



void STEPPER_vInit(Stepper_t* me);
void STEPPER_vMoveSteps(Stepper_t* me, u32 A_u32Steps, u8 A_u8Direction);
void STEPPER_vMoveAngle(Stepper_t* me,s16 A_u16Angle);


#endif /* STEPPER_STEPPER_INTERFACE_H_ */
