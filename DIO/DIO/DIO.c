#include <avr/io.h>
#indlude "DIO.h"

void DIO_setPinDir(uint8_t PORT, uint8_t PIN, bool i_o)
{
	switch (PORT)
	{
	case 'A':
		if(i_o)
			setBit(DDRA,PIN);
		else 
			 clearBit(DDRA,PIN);
		break;
	case 'B':
		if(i_o)
			setBit(DDRB,PIN);
		else
			clearBit(DDRB,PIN);
		break;
	case 'C':
		if(i_o)
			setBit(DDRC,PIN);
		else
			clearBit(DDRC,PIN);
		break;
	case 'D':
		if(i_o)
			setBit(DDRD,PIN);
		else
			clearBit(DDRD,PIN);
		break;
	}
}
void DIO_setPortDir(uint8_t PORT,uint8_t Val)
{
	switch(PORT)
	{
		case 'A':
			DDRA=Val;
			break;
		case 'B':
			DDRB=Val;
			break;
		case 'C':
			DDRC=Val;
			break;
		case 'D':
			DDRD=Val;
			break;
	}
}
void DIO_writePort(uint8_t PORT,uint8_t Val)
{
	case 'A':
		PORTA=Val;
		break;
	case 'B':
		PORTB=Val;
		break;
	case 'C':
		PORTC=Val;
		break;
	case 'D':
		PORTD=Val;
		break;
}
void DIO_writePin(uint8_t PORT,uint8_t PIN,bool i_o)
{
	switch (PORT)
	{
		case 'A':
			if(i_o)
				setBit(PORTA,PIN);
			else
				clearBit(PORTA,PIN);
			break;
		case 'B':
			if(i_o)
				setBit(PORTB,PIN);
			else
				clearBit(PORTB,PIN);
			break;
		case 'C':
			if(i_o)
				setBit(PORTC,PIN);
			else
				clearBit(PORTC,PIN);
			break;
		case 'D':
			if(i_o)
				setBit(PORTD,PIN);
			else
				clearBit(PORTD,PIN);
			break;
	}
}
bool DIO_readPin(uint8_t PORT,uint8_t PIN)
{
	switch(PORT)
	{
		case 'A':
			if(PINA & (1<<PIN))
				return TRUE;
			else
				return FALSE;
			break;
		case 'B':
			if(PINB & (1<<PIN))
				return TRUE;
			else
				return FALSE;
			break;
		case 'C':
			if(PINC & (1<<PIN))
				return TRUE;
			else
				return FALSE;
			break;
		case 'D':
			if(PINA & (1<<PIN))
				return TRUE;
			else
				return FALSE;
			break;	
	}
}
uint8_t DIO_readPort(uint8_t PORT,uint8_t PIN)
{
	switch(PORT)
	{
		case 'A':
			return PINA;
			break;
		case 'B':
			return PINB;
			break;
		case 'C':
			return PINC;
			break;
		case 'D':
			return PIND;
			break;
	}
}
void DIO_WriteHighNibble(uint8_t PORT,uint8_t data)
{
	data = data << 4;
	
	switch(PORT)
	{
		case 'A':
			PORTA &= 0x0F;
			PORTA |= data;
			break;
		case 'B':
			PORTB &= 0x0F;
			PORTB |= data;
			break;
		case 'C':
			PORTC &= 0x0F;
			PORTC |= data;
			break;
		case 'D':
			PORTD &= 0x0F;
			PORTD |= data;
			break;
	}
}