/*
 * Blink.c
 *
 * Created: 8/31/2013 12:31:45 PM
 *  Author: ShannonS
 */ 

#define F_CPU 1000000UL

#include <util/delay.h>
#include <avr/io.h>

#define GREEN PB0
#define BLUE PB1
#define RED PB2

int main(void)
{
	//Again we define the data direction register
	//Now we include 3 leds, because then we have a treasure chest
	DDRB|= (1<<GREEN);
	DDRB|= (1<<BLUE);
	DDRB|= (1<<RED);
	
	while(1) {
		//Turn on the Green LED and turn off the Red LED
		PORTB |= (1<<GREEN);
		PORTB &= ~(1<<RED);
		_delay_ms(500);
		
		//Turn off the Green LED, turn on the Blue LED
		PORTB &= ~(1<<GREEN);
		PORTB |= (1<<BLUE);
		_delay_ms(500);
		
		//Turn off the Blue LED, turn on the Red LED
		PORTB &= ~(1<<BLUE);
		PORTB |= (1<<RED);
		_delay_ms(500);
	}
}