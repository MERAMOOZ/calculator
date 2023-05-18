#ifndef LCD_H_
#define LCD_H_
#include "DIO.h"


#define CLR_SCREEN 0x01
#define CURSOR_OFF_DISPLAN_ON 	0x0C
#define RETURN_HOME 0x02
#define ENTRY_MODE 0x06

#define EN 0
#define RW 1
#define RS 2
#define EIGHT_BITS 0x38


void LCD_Init(void);
static void Send_Falling_Edge(void);
void LCD_SendData(unsigned char Data );
void LCD_SendCom(unsigned char Command);
void LCD_Send_String(unsigned char *Data);
void LCD_ClearScreen (void);
void LCD_Movecursor(char row,char coloumn);

#endif /* LCD_H_ */
