/*
 * Shift_DDRB_atmega16.cpp
 *
 * Created: 9/5/2013 12:05:49 PM
 *  Author: Shannon Strutz
 *
 *	DOES NOT BUILD!
 *	STILL A WORK IN PROGRESS!!!
 *
 */ 
#define F_CPU 8000000UL

#include <util/delay.h>
#include <avr/io.h>


void InitSPI(void) {
	DDRB |= ((1<<PB4) | (1<<PB5) | (1<<PB7));					//Sets SS, MOSI, and SCK as output
	PORTB &= ~((1<<PB4) | (1<<PB5) | (1<<PB7));			//Sets the control pins
	
	//SPI Configuration DDRB  SPE = SPI Enable  MSTR = Master
	SPCR = ( (1<<SPE) | (1<<MSTR) | (1<<SPR1) | (1<<SPR0));		//Enable SPI, Master, set (1<<PB7) rate fck/128
}

void WriteByteSPI(unsigned char byte) {
	SPDR = byte;												//Loads byte into (1<<PB4) DDRB
	while(!(SPSR & (1<<SPIF)));									//Wait for transmission to complete
}

void ToggleLatch(void){
	  PORTB |= (1<<PB5);
	  PORTB &= ~(1<<PB5);
}

char ReadByteSPI(char addr) {
	SPDR = addr;												//Load byte into (1<<PB4) regsiter
	while(!(SPSR & (1<<SPIF)));									//Wait for transmission to complete
	addr=SPDR;
	return addr;
}


int main(void)
{
	InitSPI();
    while(1)
    {
        //TODO:: Please write your application code 
		WriteByteSPI(0b01010101);
		ToggleLatch();
		_delay_ms(1000);
		
		WriteByteSPI(0b10101010);
		ToggleLatch();
		_delay_ms(1000);
    }
}