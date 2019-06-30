/*
 * LCD_int.h
 *
 *  Created on: Sep 6, 2018
 *      Author: Yomna
 */

#ifndef LCD_INT_H_
#define LCD_INT_H_
#include "../LIB/types.h"
#include "../LIB/locations.h"
#define A 0
#define B 1
#define C 2
#define D 3
#define PORTDATA PORTD
#define PORTCONTROL PORTA
#define DDRDATA DDRD
#define DDRCONTROL DDRA
//void LCD_Data_Control_Port(u8 DPORTNO,u8 CPORTNO);//DDRCONTROL,DDRDATA,PORTCONTROL,PORTDATA
void LCD_VidCLR(void); //Clear th LCD
void LCD_VidWriteCommand (u8 u8Cmd); //to send specific command
void LCD_VidWriteData (u8 u8Data); //write a character
void LCD_VidInit(void); //initialization fn.
void LCD_VidWriteNumber(u8 u8bits, u16 u16String); // it takes 2 arguments (Digit numbers,The No. itself)
void LCD_VidWriteString(u8*); // it takes the word to print
void LCD_GottoXY(u8 x,u8 y); // manage the cursor position on the screen.

#endif /* LCD_INT_H_ */
