/*
 * RGB LED color changer button.c
 *
 * Created: 8/31/2013 12:31:45 PM
 *  Author: Shannon Strutz
 *	Website: www.shannonstrutz.com
 *	E-mail: strutz.shannon@gmail.com
 *
 *	So to setup this code you are to attach a common cathode RGB LED
 *  to the pins PB0, PB1, and PB2.  Since we aren't doing anything special
 *	with the colors, it doesn't matter which goes to where.
 *
 *	Make sure you connect the longest pin of the C.C. RGB LED to Ground
 *	Make sure you have a resistor in series with the rest of the pins.
 *
 *	Usage: Press the button to change the color
 *
 *	Note this does not have any debounce so you won't get a nice sequential
 *	output.  Just keep trying
 *
 *	This code is under the Creative Commons Attribution-ShareAlike 3.0 Unported License
 *	A human-readable of this license is here: http://creativecommons.org/licenses/by-sa/3.0/
 *	A full legal text of this license is here: http://creativecommons.org/licenses/by-sa/3.0/legalcode
 */ 


#define F_CPU 1000000UL

#include <util/delay.h>
#include <avr/io.h>
#include <stdio.h>

#define GREEN PB0
#define BLUE PB1
#define RED PB2
#define Button PA5
uint8_t LED = 0;


int main(void)
{
	//Again we define the data direction register
	//Now we include 3 leds, because then we have a treasure chest
	DDRB &= ~(1<<Button);
	DDRB|= (1<<GREEN);
	DDRB|= (1<<BLUE);
	DDRB|= (1<<RED);
	PORTA|=(1<<Button);

	while(1) {
		if (PINA & (1<<Button)){
			if (LED == 6)
				LED = 0;
			else
				LED = LED + 1;
		}
		else{
		switch (LED)
		{
			case 0:
			PORTB |= (1<<GREEN);
			PORTB &= ~(1<<BLUE) & ~(1<<RED);
			break;
			
			case 1:
			PORTB &= ~(1<<GREEN) & ~(1<<RED);
			PORTB |= (1<<BLUE);			
			break;
			
			case 2:
			PORTB &= ~(1<<GREEN) & ~(1<<BLUE);
			PORTB |= (1<<RED);
			break;
			
			case 3:
			PORTB &= ~(1<<RED);
			PORTB |= (1<<GREEN) | (1<<BLUE);
			
			case 4:
			PORTB &= ~(1<<GREEN);
			PORTB |= (1<<RED) | (1<<BLUE);
			
			case 5:
			PORTB &= ~(1<<BLUE);
			PORTB |= (1<<GREEN) | (1<<RED);
			
			default:
			PORTB |= (1<<GREEN) & (1<<BLUE) & (1<<RED);
			break;
		}
	}
	}
	
}