/*
 * LCD_interface.h
 *
 *  Created on: Sep 16, 2022
 *      Author: mazen
 */

#ifndef LCD_LCD_INTERFACE_H_
#define LCD_LCD_INTERFACE_H_

void LCD_vSendChar(u8 A_u8character);
void LCD_vSendCommand(u8 A_u8cmd);
void LCD_vInit(void);
void LCD_vDisplayCustomChar(u8 A_u8CharId);
void LCD_vSaveCustomChar(u8 A_pu8CharArr[], u8 A_u8CharId);

#endif /* LCD_LCD_INTERFACE_H_ */
