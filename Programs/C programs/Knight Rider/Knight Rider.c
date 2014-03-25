
/*
 * Lab2_Problem1.c
 *
 * Created: 2/12/2014 2:01:07 PM
 *  Author: Shannon Strutz
 */ 
#define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>

int main(void) 
{
	//LEDs are active high
	DDRB |= 0xFF;		//Set DDRB to OUTPUT
	PORTB |= 0x00;		//Set PORTB to HIGH
    while(1)
    {
		for(uint8_t i = 0; i<7; i++)	//Shifts a around and around
		{			
			PORTB |= (1<<i); 	//Withdraw the 1 out of location PBi
			_delay_ms(100);		//wait half a second
			PORTB &= ~(1<<i);	//Insert 1 into location PBi
			_delay_ms(100);		//wait half a second
		}	
		for(uint8_t i = 7; i>0; i--)
		{
			PORTB |= (1<<i);
			_delay_ms(100);
			PORTB &= ~(1<<i);
			_delay_ms(100);
		}
    }
}