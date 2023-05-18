
#ifndef DIO_H_
#define DIO_H_
/*
	Function Description : Set the direction of the given pin in the given port (direction 0 = input : 1 = output)
*/
void DIO_setPIN(unsigned char portname,unsigned char pinnumber,unsigned char direction);

/*
	Function Description : Set the value of the given pin in the given port (outputvalue 0 = low : 1 = high) 
*/
void DIO_write(unsigned char portname,unsigned char pinnumber,unsigned char outputvalue);

/*
	Function Description : Returns 1 if the value of the given pin is high and zero if the value is low
*/
unsigned char DIO_u8read(unsigned char portname,unsigned char pinnumber);

/*
	Function Description : Reverse the value of the given pin in the given port.
*/
void DIO_toggle(unsigned char portname,unsigned char pinnumber);

/*
	Function Description : set the direction of whole port .
*/

void DIO_set_port_direction(unsigned char portname,unsigned char direction);
/*
	Function Description : Write the value to all port pins.
*/

void DIO_write_port(unsigned char portname,unsigned char portvalue);

/*
	Function Description : read the value of the port .
*/
unsigned char DIO_read_port(unsigned char portname);
/*
	Function Description : Connect and disconnect pull up resistor to the given pin at the given port 
*/
void DIO_connectpullup(char portname ,char pinnumber, char connect_pullup);
/*
	Function Description : write a value to the low nibble of the port 
*/
void write_low_nibble(unsigned char portname,unsigned char value);
/*
	Function Description : write a value to the high nibble of the port 
*/
void write_high_nibble(unsigned char portname,unsigned char value);
#endif

