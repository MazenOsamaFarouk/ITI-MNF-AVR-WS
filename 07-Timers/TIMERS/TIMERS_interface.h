/*
 * TIMERS_interface.h
 *
 *  Created on: Sep 24, 2022
 *      Author: mazen
 */

#ifndef TIMERS_TIMERS_INTERFACE_H_
#define TIMERS_TIMERS_INTERFACE_H_

void TIMERS_vInit(void);
void TIMERS_vSetBusyWait_synch(/* TimerId  ,*/ u32 A_u32Ticks);

void TIMERS_vStartTimer(/* TimerId  ,*/ void);
void TIMERS_vStopTimer(/* TimerId  ,*/ void);
void TIMERS_vSetCallback(/* TimerId  ,*/ void (*fptr)(void));

void TIMERS_vSetPreloadValue(/* TimerId  ,*/ u16 A_u16Preload);
void TIMERS_vSetCompareMatchValue(/* TimerId  ,*/ u16 A_u16OcrVal    );



#endif /* TIMERS_TIMERS_INTERFACE_H_ */
