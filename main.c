/*
 * main.c
 *
 *  Created on: Sep 22, 2021
 *      Author: Amira Al Hadidy
 */


#include "LCD.h"
#include "KEYPAD.h"
#define  F_CPU 8000000UL
#include <util/delay.h>
#include <avr/io.h>


int main(void)
{
	label: LCD_Init();
	KEYPAD_Init();
	unsigned char arr[6]={NOTPRESSED,NOTPRESSED,NOTPRESSED,NOTPRESSED,NOTPRESSED,NOTPRESSED} ;
	unsigned short res ;
	unsigned char counter=0 ;
	char str[]= "Amira";
	while(1)
	{
		do
		{
			arr[counter]=KEYPAD_u8GetButton();

		}
		while(arr[counter]==NOTPRESSED);
			if(arr[counter]=='A'||arr[counter]=='='||arr[counter]=='+'||arr[counter]=='-'||arr[counter]=='*'||arr[counter]=='/')
			{
				LCD_ClearScreen ();
				for(int i=0;str[i]!='\0';i++)
						{
						   LCD_SendData(str[i]);
						   _delay_ms(300);
						}
				goto label ;
			}
			else
				{
				LCD_SendData(arr[counter]);
				}
				counter++;
				_delay_ms(300);
				do
				{
					arr[counter]=KEYPAD_u8GetButton();

				}
				while(arr[counter]==NOTPRESSED);
					if(arr[counter]=='A'||arr[counter]=='='||arr[counter]=='+'||arr[counter]=='-'||arr[counter]=='*'||arr[counter]=='/')
					{
						LCD_ClearScreen();
						goto label ;
					}
					else
					{
						LCD_SendData(arr[counter]);
					}
					counter++;
					_delay_ms(300);

					do
					{
						arr[counter]=KEYPAD_u8GetButton();

					}
					while(arr[counter]==NOTPRESSED);

					if(arr[counter]=='A'||arr[counter]=='=')
					{
						LCD_ClearScreen();
						goto label ;
					}
					else
					{
						LCD_SendData(arr[counter]);
					}
					counter++;
					_delay_ms(300);
					do
						{
							arr[counter]=KEYPAD_u8GetButton();

						}
					while(arr[counter]==NOTPRESSED);

						if(arr[counter]=='A'||arr[counter]=='='||arr[counter]=='+'||arr[counter]=='-'||arr[counter]=='*'||arr[counter]=='/')
						{
							LCD_ClearScreen();
							goto label ;
						}
						else
						{
							LCD_SendData(arr[counter]);
						}
						counter++;
						_delay_ms(300);
						do
						{
							arr[counter]=KEYPAD_u8GetButton();

						}
						while(arr[counter]==NOTPRESSED);

						if(arr[counter]=='A'||arr[counter]=='='||arr[counter]=='+'||arr[counter]=='-'||arr[counter]=='*'||arr[counter]=='/')
						{
							LCD_ClearScreen();
							goto label ;
						}
						else
						{
							LCD_SendData(arr[counter]);
						}
						counter++;
						_delay_ms(300);
						do
							{
								arr[counter]=KEYPAD_u8GetButton();

							}
						while(arr[counter]==NOTPRESSED);

							if(arr[counter]=='=')
							{
								LCD_SendData(arr[counter]);

								switch(arr[counter-3])
								{
									case '+':
									res=(arr[counter-4]-48)+((arr[counter-5]-48)*10)+((arr[counter-2]-48)*10)+(arr[counter-1]-48);
									if(res>=100&&res<1000)
									{
										LCD_SendData((res/100)+48);
										LCD_SendData(((res/10)%10)+48);
										LCD_SendData((res%10)+48);
									}
									else if (res>=10&&res<100)
									{
										LCD_SendData((res/10)+48);
										LCD_SendData((res%10)+48);
									}
									else if(res<10)
									{
										LCD_SendData(res+48);
									}
									break;
									case '-' :
									res=((arr[counter-4]-48)+((arr[counter-5]-48)*10))-(((arr[counter-2]-48)*10)+(arr[counter-1]-48));
									if(res>=100&&res<1000)
									{
										LCD_SendData((res/100)+48);
										LCD_SendData(((res/10)%10)+48);
										LCD_SendData((res%10)+48);
									}
									else if (res>=10&&res<100)
									{
										LCD_SendData((res/10)+48);
										LCD_SendData((res%10)+48);
									}
									else if(res<10)
									{
										LCD_SendData(res+48);
									}
									break;
									case '*':
									res=((arr[counter-4]-48)+((arr[counter-5]-48)*10))*(((arr[counter-2]-48)*10)+(arr[counter-1]-48));
									if(res>=1000&&res<10000)
									{
										LCD_SendData((res/1000)+48);
										LCD_SendData(((res/100)%10)+48);
										LCD_SendData(((res/10)%10)+48);
										LCD_SendData((res%10)+48);

									}
									else if(res>=100&&res<1000)
									{
										LCD_SendData((res/100)+48);
										LCD_SendData(((res/10)%10)+48);
										LCD_SendData((res%10)+48);
									}
									else if (res>=10&&res<100)
									{
										LCD_SendData((res/10)+48);
										LCD_SendData((res%10)+48);
									}
									else if(res<10)
									{
										LCD_SendData(res+48);
									}
									break;
									case '/':
									res=((arr[counter-4]-48)+((arr[counter-5]-48)*10))/(((arr[counter-2]-48)*10)+(arr[counter-1]-48));
									if(res>=100&&res<1000)
									{
										LCD_SendData((res/100)+48);
										LCD_SendData(((res/10)%10)+48);
										LCD_SendData((res%10)+48);
									}
									else if (res>=10&&res<100)
									{
										LCD_SendData((res/10)+48);
										LCD_SendData((res%10)+48);
									}
									else if(res<10)
									{
										LCD_SendData(res+48);
									}
									break;
									default : break;

								}
							}
							else
							{
								LCD_ClearScreen();
								goto label ;
							}
							_delay_ms(200);
						}
							}
