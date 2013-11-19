/*
 * Blink.c
 *
 * Created: 8/31/2013 12:31:45 PM
 *  Author: Shannon Strutz
 *	Website: www.shannonstrutz.com
 *	E-mail: strutz.shannon@gmail.com
 *  
 *	Usage: Connect the anode side of an LED to pins PB0 and another LED to PB1
 *		   Connect a resistor to each of the cathodes of the LEDs
 *		   Connect the other side of the resistor to ground
 *
 *		   For a faster blink, change the Delay variable
 *
 *
 *	This code is under the Creative Commons Attribution-ShareAlike 3.0 Unported License
 *	A human-readable of this license is here: http://creativecommons.org/licenses/by-sa/3.0/
 *	A full legal text of this license is here: http://creativecommons.org/licenses/by-sa/3.0/legalcode
 */ 
#define F_CPU 8000000UL

#include <util/delay.h>
#include <avr/io.h>
#include <inttypes.h>

#define LED1 PB0
#define LED2 PB1
#define Delay 10


int main(void)
{
	
	DDRB |= (1<<PB0) | (1<<PB1);
		
	while(1){
		PORTB |= (1<<PB0);
		PORTB &= ~(1<<PB1);
		_delay_ms(Delay);
		
		PORTB |= (1<<PB1);
		PORTB &= ~(1<<PB0);
		_delay_ms(Delay);
	}	
}