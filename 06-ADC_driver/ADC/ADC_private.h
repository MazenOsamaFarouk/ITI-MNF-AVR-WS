/*
 * ADC_private.h
 *
 *  Created on: Sep 23, 2022
 *      Author: mazen
 */

#ifndef ADC_ADC_PRIVATE_H_
#define ADC_ADC_PRIVATE_H_


#define VREF_AVCC   0b01


#define  ADMUX     *((volatile u8*)(0x27))
#define  ADCSRA    *((volatile u8*)(0x26))
#define  ADCL      *((volatile u8*)(0x24))
#define  ADCH      *((volatile u8*)(0x25))
#define  SFIOR     *((volatile u8*)(0x50))

#define ADC_DATA   *((volatile u16*)(0x24))





#endif /* ADC_ADC_PRIVATE_H_ */
