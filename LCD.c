
#include "LCD.h"
#define  F_CPU 8000000UL 
#include <util/delay.h>

void LCD_Init(void)
{
	_delay_ms(200);
	
	DIO_setPIN('A',0,1);
	DIO_setPIN('A',1,1);
	DIO_setPIN('A',2,1);
	DIO_setPIN('A',3,1);
	DIO_setPIN('A',4,1);
	DIO_setPIN('A',5,1);
	DIO_setPIN('A',6,1);
	DIO_setPIN('A',7,1);
	DIO_setPIN('B',EN,1);
	DIO_setPIN('B',RW,1);
	DIO_setPIN('B',RS,1);
	DIO_write('B',RW,0);
	LCD_SendCom(EIGHT_BITS); //8 bit mode
		_delay_ms(1);
		LCD_SendCom(CURSOR_OFF_DISPLAN_ON);//display on cursor on
		_delay_ms(1);
		LCD_SendCom(CLR_SCREEN);//clear the screen
		_delay_ms(10);
		LCD_SendCom(ENTRY_MODE); //entry mode
		_delay_ms(1);
}
	
	static void Send_Falling_Edge(void)
{
	DIO_write('B',EN,1);
	_delay_ms(2);
	DIO_write('B',EN,0);
	_delay_ms(2);
}
	void LCD_SendCom(unsigned char Command)
{
	DIO_write_port('A',Command);
	DIO_write('B',RS,0);
	Send_Falling_Edge();
	_delay_ms(1);
}

void LCD_SendData(unsigned char Data)
{
	DIO_write_port('A',Data);
	DIO_write('B',RS,1);
	Send_Falling_Edge();

	_delay_ms(1);
}

void LCD_Send_String(unsigned char *Data)
{
	while((*Data)!='\0')
	{
		LCD_SendData(* Data);
		Data++;
	}
}
void LCD_ClearScreen()
{
	LCD_SendCom(CLR_SCREEN);
	_delay_ms(10);
}
void LCD_Movecursor(char row,char coloumn)
{
	char data ;
	if(row>2||row<1||coloumn>16||coloumn<1)
	{
		data=0x80;
	}
	else if(row==1)
	{
		data=0x80+coloumn-1 ;
	}
	else if (row==2)
	{
		data=0xc0+coloumn-1;
	}
	 LCD_SendCom(data);
	_delay_ms(1);
}
