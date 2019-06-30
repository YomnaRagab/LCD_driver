/*
 * LCD_prog.c
 *
 *  Created on: Sep 6, 2018
 *      Author: Yomna
 */
#include "../LIB/types.h"
#include "../LIB/locations.h"
#include "../LIB/math.h"
#define F_CPU 12000000
#include "avr/delay.h"
#include "LCD_int.h"
//void LCD_Data_Control_Port(u8 DPORTNO,u8 CPORTNO)
//{
//	if (DPORTNO==A)
//	{
//		#define PORTDATA PORTA
//		#define DDRDATA DDRA
//	}
//	else if (DPORTNO==B)
//		{
//			#define PORTDATA PORTB
//			#define DDRDATA DDRB
//		}
//	else if (DPORTNO==C)
//		{
//			#define PORTDATA PORTC
//			#define DDRDATA DDRC
//		}
//	else if (DPORTNO==D)
//		{
//			#define PORTDATA PORTD
//			#define DDRDATA DDRD
//		}
//	//Contol
//#if (CPORTNO==A)
//
//			#define PORTCONTROL PORTA
//			#define DDRCONTROL DDRA
//
//#elif (CPORTNO==B)
//
//				#define PORTCONTROL PORTB
//				#define DDRCONTROL DDRB
//
//#elif (CPORTNO==C)
//
//				#define PORTCONTROL PORTC
//				#define DDRCONTROL DDRC
//
//#elif (CPORTNO==D)
//
//				#define PORTCONTROL PORTD
//				#define DDRCONTROL DDRD
//#endif
////	DDRDATA=255;
////	DDRCONTROL=0b00000111;
//}
void LCD_VidWriteCommand (u8 u8Cmd)
{
  CLR(PORTA,0);
  CLR(PORTA,1);
  PORTDATA=u8Cmd;
  SET(PORTA,2);
  _delay_ms(2);
  CLR(PORTA,2);
}
void LCD_VidWriteData (u8 u8Data)
{
  SET(PORTA,0);
  CLR(PORTA,1);
  PORTDATA=u8Data;
  SET(PORTA,2);
  _delay_ms(2);
  CLR(PORTA,2);
}
void LCD_VidInit(void)
{
  _delay_ms(50);
  LCD_VidWriteCommand(0b00111100);
  _delay_ms(2);
  LCD_VidWriteCommand(0b00001110);
  _delay_ms(2);
  LCD_VidWriteCommand(0b00000001);
  _delay_ms(2);
}
void LCD_VidWriteNumber(u8 u8bits, u16 u16String)
{
	u8 i;
	u8 charachter[u8bits];
	for (i=0; i<u8bits; i++)
	{
		charachter[u8bits-1-i]=u16String%10;
		u16String=u16String/10;
	}
	for (i=0; i<u8bits; i++)
	{
		LCD_VidWriteData (charachter[i]+'0');
	}
}
void LCD_GottoXY(u8 x,u8 y)
{
	if(y==1)
	{
		 LCD_VidWriteCommand (0b10000000+x);
	}
	else if(y==2)
	{
		LCD_VidWriteCommand (0b11000000+x);
	}
}
void LCD_VidWriteString(u8 * u8PtrStrg)
{
	while (*u8PtrStrg)
		{
		LCD_VidWriteData(*u8PtrStrg);
		u8PtrStrg++;
		}
}
void LCD_VidCLR(void)
{
	LCD_VidWriteCommand(1);
}
void main (void)
{
//	DDRD=255;
//	DDRA=255;
	u8 name[]="Yomna";

	DDRDATA=255;
	DDRCONTROL=255;
	LCD_VidInit();
	while(1)
	{
		LCD_VidWriteString(&name);
		_delay_ms(500);
		LCD_GottoXY(2,1);
		LCD_VidCLR();
		_delay_ms(1000);
//		LCD_VidWriteString(&name);
	}
}
