/*
 * Blink.c
 *
 * Created: 8/31/2013 12:31:45 PM
 *  Author: Shannon Strutz
 */ 
#define F_CPU 8000000UL

#include <util/delay.h>
#include <avr/io.h>
#include <inttypes.h>

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
			_delay_ms(5);
			if (PINA & (1<<Button)){
				if (LED == 2)
					LED = 0;
				else
					LED = LED + 1;
			}
			else{}
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
			
			default:
			PORTB |= (1<<GREEN) & (1<<BLUE) & (1<<RED);
			break;
		}
	}
	}
	
}