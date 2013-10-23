/*
 * GccApplication1.cpp
 *
 * Created: 9/5/2013 6:03:23 PM
 *  Author: ShannonS
 */ 
#include <util/delay.h>
#include <avr/io.h>

#define SHIFT_REGISTER DDRB
#define SHIFT_PORT PORTB
#define DATA (1<<PB5)     //MOSI (SI)
#define LATCH (1<<PB4)        //SS   (RCK)
#define CLOCK (1<<PB7)        //SCK  (SCK)

#define _I 0b11001111
#define _S 0b10010010
#define _F 0b10001110
#define _E 0b10000110
#define OFF 0b11111111




void InitSPI(void)
{
	//Setup IO
	SHIFT_REGISTER |= (DATA | LATCH | CLOCK); //Set control pins as outputs
	SHIFT_PORT &= ~(DATA | LATCH | CLOCK);        //Set control pins low
	
	SPCR = ( (1<<SPE) | (1<<MSTR) | (1<<SPR1) | (1<<SPR0));
}

void WriteByteSPI(unsigned char byte) {
	SPDR = byte;												//Loads byte into Data Register
	while(!(SPSR & (1<<SPIF)));									//Wait for transmission to complete
}

void ToggleLatch(void){
	PORTB |= LATCH;
	PORTB &= ~LATCH;
}

char ReadByteSPI(char addr) {
	SPDR = addr;												//Load byte into data regsiter
	while(!(SPSR & (1<<SPIF)));									//Wait for transmission to complete
	addr=SPDR;
	return addr;
}


int main(void)
{
	InitSPI();
	PORTB &= ~LATCH;
	while(1)
	{
		//TODO:: Please write your application code
		
		/*
		WriteByteSPI(_S);
		ToggleLatch();
		_delay_ms(500);
		
		WriteByteSPI(_F);
		ToggleLatch();
		_delay_ms(500);
		
		WriteByteSPI(_E);
		ToggleLatch();
		_delay_ms(500);
		*/
		
		WriteByteSPI(_I);
		ToggleLatch();
		_delay_ms(500);
		
		WriteByteSPI(OFF);
		ToggleLatch();
		_delay_ms(100);
		
		WriteByteSPI(_E);
		ToggleLatch();
		_delay_ms(500);
		
		WriteByteSPI(OFF);
		ToggleLatch();
		_delay_ms(100);
		
		WriteByteSPI(_E);
		ToggleLatch();
		_delay_ms(500);
		
		WriteByteSPI(OFF);
		ToggleLatch();
		_delay_ms(100);
		
		WriteByteSPI(_E);
		ToggleLatch();
		_delay_ms(500);
		
		WriteByteSPI(OFF);
		ToggleLatch();
		_delay_ms(100);
	}
}