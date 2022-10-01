/*
 * WDT_interface.h
 *
 *  Created on: Oct 1, 2022
 *      Author: mazen
 */

#ifndef WDT_WDT_INTERFACE_H_
#define WDT_WDT_INTERFACE_H_



#define WDT_PS_16ms		0b000

#define WDT_PS_1s		0b110


void WDT_vEnable(u8 A_u8Timeout);
void WDT_vDisable(void);



#endif /* WDT_WDT_INTERFACE_H_ */
