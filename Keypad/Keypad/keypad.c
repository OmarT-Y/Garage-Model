#include "keypad.h"
#include "DIO.h"
#include <avr/io.h>
#indlude <avr/delay.h>

void keypad_start(void)
{
	DIO_setPinDir(keypadPort,0,1);
	DIO_setPinDir(keypadPort,1,1);
	DIO_setPinDir(keypadPort,2,1);
	DIO_setPinDir(keypadPort,3,1);
	DIO_setPinDir(keypadPort,4,0);
	DIO_setPinDir(keypadPort,5,0);
	DIO_setPinDir(keypadPort,6,0);
}
char keypad_getChar(void)
{
	DIO_writePin(keypadPort,0,1);//R1
	_delay_ms(1);
	if(DIO_readPin(keypadPort,4)==1) return '1';
	else if(DIO_readPin(keypadPort,5)==1) return '2';
	else if(DIO_readPin(keypadPort,6)==1) return '3';
	DIO_writePin(keypadPort,0,0);
	
	DIO_writePin(keypadPort,1,1);
	_delay_ms(1);
	if(DIO_readPin(keypadPort,4)==1) return '4';
	else if(DIO_readPin(keypadPort,5)==1) return '5';
	else if(DIO_readPin(keypadPort,6)==1) return '6';
	DIO_writePin(keypadPort,1,0);
	
	DIO_writePin(keypadPort,2,1);
	_delay_ms(1);
	if(DIO_readPin(keypadPort,4)==1) return '7';
	else if(DIO_readPin(keypadPort,5)==1) return '8';
	else if(DIO_readPin(keypadPort,6)==1) return '9';
	DIO_writePin(keypadPort,2,0);
	
	DIO_writePin(keypadPort,3,1);
	_delay_ms(1);
	if(DIO_readPin(keypadPort,4)==1) return '*';
	else if(DIO_readPin(keypadPort,5)==1) return '0';
	else if(DIO_readPin(keypadPort,6)==1) return '#';
	DIO_writePin(keypadPort,3,0);
	
	return 'F';
}