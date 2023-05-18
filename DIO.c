
#include <avr/io.h>


#define   set_bit(var,bitnum)    var = ( var | (1<<bitnum) )
#define   clear_bit(var,bitnum)    var = ( var & ~(1<<bitnum) )
#define   read_bit(var,bitnum)    (var&(1<<bitnum))>>bitnum
#define   tog_bit(var,bitnum)    var^=(1<<bitnum)

void DIO_setPIN(unsigned char portname,unsigned char pinnumber,unsigned char direction)
{
	switch(portname)
	{
		
		
		case 'A':
		if(direction==1)
		{
			set_bit(DDRA,pinnumber);//Set the direction of the given pin in port A as output
		}
		else
		{
			clear_bit(DDRA,pinnumber);//Set the direction of the given pin in port A as input
		}
		break;
		case 'B':
		if(direction==1)
		{
			set_bit(DDRB,pinnumber);//Set the direction of the given pin in port B as output
		}
		else
		{
			clear_bit(DDRB,pinnumber);//Set the direction of the given pin in port B as input
		}
		break;
		case 'C':
		if(direction==1)
		{
			set_bit(DDRC,pinnumber);//Set the direction of the given pin in port C as output
		}
		else
		{
			clear_bit(DDRC,pinnumber);//Set the direction of the given pin in port C as input
		}
		break;
		case 'D':
		if(direction==1)
		{
			set_bit(DDRD,pinnumber);//Set the direction of the given pin in port D as output
		}
		else
		{
			clear_bit(DDRD,pinnumber);//Set the direction of the given pin in port D as input
		}
		break;
		default: 
		break;
	}
}


void DIO_write(unsigned char portname,unsigned char pinnumber,unsigned char outputvalue)
{
	switch(portname)
	{
		case 'A' :
		
		if(outputvalue==1)
		{
			set_bit(PORTA,pinnumber);//Set the value of the given pin in port A as High
		}
		else
		{
			clear_bit(PORTA,pinnumber);//Set the value of the given pin in port A as Low
		}
		break ;
		case 'B':
		
		if(outputvalue==1)
		{
			set_bit(PORTB,pinnumber);//Set the value of the given pin in port B as High
		}
		else
		{
			clear_bit(PORTB,pinnumber);//Set the value of the given pin in port B as Low
		}
		break ;
		case 'C' :
		
		if(outputvalue==1)
		{
			set_bit(PORTC,pinnumber);//Set the value of the given pin in port C as High
		}
		else
		{
			clear_bit(PORTC,pinnumber);//Set the value of the given pin in port C as Low
		}
		break ;
		case 'D':
		
		if(outputvalue==1)
		{
			set_bit(PORTD,pinnumber);//Set the value of the given pin in port D as High
		}
		else
		{
			clear_bit(PORTD,pinnumber);//Set the value of the given pin in port D as Low
		}
		break ;
		default: break ;
	}
}


unsigned char DIO_u8read(unsigned char portname,unsigned char pinnumber)
{
	unsigned char return_value=0;
	switch(portname)
	{
		case 'A' :
		return_value=read_bit(PINA,pinnumber);//Read the value from the given pin in port A
		break;
		
		case 'B' :
		return_value=read_bit(PINB,pinnumber);//Read the value from the given pin in port B
		break;
		
		case 'C' :
		return_value=read_bit(PINC,pinnumber);//Read the value from the given pin in port C
		break;
		
		case 'D' :
		return_value=read_bit(PIND,pinnumber);//Read the value from the given pin in port D
		break;
		default: 
		break;
	}
	return return_value ;
}
void DIO_toggle(unsigned char portname,unsigned char pinnumber)
{
	switch(portname)
	{
		case 'A':
		tog_bit(PORTA,pinnumber);//Toggle the value of the given pin in port A
		break;
		case 'B':
		tog_bit(PORTB,pinnumber);//Toggle the value of the given pin in port B
		break;
		case 'C':
		tog_bit(PORTC,pinnumber);//Toggle the value of the given pin in port C
		break;
		case 'D':
		tog_bit(PORTD,pinnumber);//Toggle the value of the given pin in port D
		break;
		default: break;
	}
}
void DIO_set_port_direction(unsigned char portname,unsigned char direction)
{
	switch(portname)
	{
		case 'A' :
		DDRA=direction; //set the direction of port A
		break ;
		case 'B':
		DDRB=direction; //set the direction of port B
		break ;
		case 'C' :
		DDRC=direction; //set the direction of port C
		break ;
		case 'D':
		DDRD=direction; //set the direction of port D
		break ;
		default:
		break ;
	}
	
}
void DIO_write_port(unsigned char portname,unsigned char portvalue)
{
	switch(portname)
	{
		case 'A' :
		PORTA=portvalue; //Write the given value to the port A
		break ;
		case 'B':
		PORTB=portvalue; //Write the given value to the port B
		break ;
		case 'C' :
		PORTC=portvalue; //Write the given value to the port C
		break ;
		case 'D':
		PORTD=portvalue; //Write the given value to the port D
		break ;
		default:
		 break ;
	}
}

unsigned char DIO_read_port(unsigned char portname)
{
	unsigned char return_val=0;
	switch(portname)
	{
		case 'A' :
		return_val=PINA; // read the value of port A 
		break ;
		case 'B':
		return_val=PINB; // read the value of port B 
		break ;
		case 'C' :
		return_val=PINC; // read the value of port C 
		break ;
		case 'D':
		return_val=PIND; // read the value of port D 
		break ;
		default:
		break ;
	}
	return return_val;
}

void DIO_connectpullup(char portname ,char pinnumber, char connect_pullup)
{
	switch(portname)
	{
		case 'A':
		if(connect_pullup==1)
		{
			set_bit(PORTA,pinnumber);
		}
		else
		{
			clear_bit(PORTA,pinnumber);
		}
		break;
		case 'B':
		if(connect_pullup==1)
		{
			set_bit(PORTB,pinnumber);
		}
		else
		{
			clear_bit(PORTB,pinnumber);
		}
		break;
		case 'C':
		if(connect_pullup==1)
		{
			set_bit(PORTC,pinnumber);
			
		}
		else
		{
			clear_bit(PORTC,pinnumber);
		}
		break;
		case 'D':
		if(connect_pullup==1)
		{
			set_bit(PORTD,pinnumber);
			
		}
		else
		{
			clear_bit(PORTD,pinnumber);
		}
		break;
		
	}
}

void write_low_nibble(unsigned char portname,unsigned char value)
{
	value&=0x0f;
	switch(portname)
	{
		case 'A':
		PORTA&=0xf0;
		PORTA|=value;
		break;
		case 'B':
		PORTB&=0xf0;
		PORTB|=value;
		break;
		case 'C':
		PORTC&=0xf0;
		PORTC|=value;
		break;
		case 'D':
		PORTD&=0xf0;
		PORTD|=value;
		break;
	}
}

void write_high_nibble(unsigned char portname,unsigned char value)
{
	value<<=4;
	switch(portname)
	{
		case 'A':
		PORTA&=0x0f;
		PORTA|=value;
		break;
		case 'B':
		PORTB&=0x0f;
		PORTB|=value;
		break;
		case 'C':
		PORTC&=0x0f;
		PORTC|=value;
		break;
		case 'D':
		PORTD&=0x0f;
		PORTD|=value;
		break;
	}
}
