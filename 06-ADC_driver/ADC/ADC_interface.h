/*
 * ADC_interface.h
 *
 *  Created on: Sep 23, 2022
 *      Author: mazen
 */

#ifndef ADC_ADC_INTERFACE_H_
#define ADC_ADC_INTERFACE_H_


void ADC_vInit(void);
u16  ADC_vReadDigitalValue_synch(u8 A_u8Channel); // Synchronous function

void ADC_vSetCallback(void (*fptr)(void));
void ADC_vEnableInterrupt(void);
void ADC_vDisableInterrupt(void);
void ADC_vSelectChannel(u8 A_u8Channel);
void ADC_vStartConversion(u8 A_u8Channel);
u16  ADC_vReadDigitalValue_asynch(void);









#endif /* ADC_ADC_INTERFACE_H_ */
