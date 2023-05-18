#include "KEYPAD.h"
 void KEYPAD_Init()
 {
	 DIO_setPIN('D',0,1);
	 DIO_setPIN('D',1,1);
	 DIO_setPIN('D',2,1);
	 DIO_setPIN('D',3,1);
	 DIO_setPIN('D',4,0);
	 DIO_setPIN('D',5,0);
	 DIO_setPIN('D',6,0);
	 DIO_setPIN('D',7,0);
	 DIO_connectpullup('D',4,1);
	 DIO_connectpullup('D',5,1);
	 DIO_connectpullup('D',6,1);
	 DIO_connectpullup('D',7,1);
	  
 }
unsigned char KEYPAD_u8GetButton(void)
 {
	 char arr[4][4]={{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'A','0','=','+'}};
	 char row,coloumn,x;
	 char returnval=NOTPRESSED;
	 for(row=0;row<4;row++)
	 {
	 DIO_write('D',0,1);
	 DIO_write('D',1,1);
	 DIO_write('D',2,1);
	 DIO_write('D',3,1);
	 DIO_write('D',row,0);
	
		for(coloumn=0;coloumn<4;coloumn++)
		{
		 x=DIO_u8read('D',(coloumn+4));
		 if(x==0)
			 {
			 returnval=arr[row][coloumn];
			 break;
			 }  
		}	
	 if(x==0)
		{
		 break;
		}
	 }	 
	 return returnval ;	 
 }
