/*
 * TIMERS_interface.h
 *
 *  Created on: Sep 24, 2022
 *      Author: mazen
 */

#ifndef TIMERS_TIMERS_INTERFACE_H_
#define TIMERS_TIMERS_INTERFACE_H_

#define TIMER0      0
#define TIMER1		1


#define ICU_RISING   1
#define ICU_FALLING	 2

void TIMERS_vInit(void);
void TIMERS_vSetBusyWait_synch(/* TimerId  ,*/ u32 A_u32Ticks);

void TIMERS_vStartTimer(/* TimerId  ,*/ void);
void TIMERS_vStopTimer(/* TimerId  ,*/ void);
void TIMERS_vSetCallback(/* TimerId  ,*/ void (*fptr)(void));

void TIMERS_vSetPreloadValue(/* TimerId  ,*/ u16 A_u16Preload);
void TIMERS_vSetCompareMatchValue(/* TimerId  ,*/ u16 A_u16OcrVal    );
void TIMERS_vSetICR1(u16 A_16IcrValue);
u16  TIMERS_u16GetICR1(void);
u16  TIMERS_u16GetElapsedTime(u8 A_u8TimerId  );

void TIMERS_vSetICUSenseCtrl(u8 A_u8SenseCtrl);
void TIMERS_vDisableInturrupt(u8 A_u8TimerId, u8 A_u8InterruptSource);
void TIMERS_vEnableInturrupt(u8 A_u8TimerId, u8 A_u8InterruptSource);









#endif /* TIMERS_TIMERS_INTERFACE_H_ */
