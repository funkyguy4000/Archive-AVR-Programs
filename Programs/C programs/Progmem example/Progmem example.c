/*
 * Progmem example.c
 *
 * Created: 2/12/2014 2:33:10 PM
 *  Author: Shannon Strutz
 */ 
#define F_CPU 8000000UL
#define delay 100

#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>

const char tab[] PROGMEM = { 0x0C,  0x14,  0x04,  0x21, 0x22,   0x20};
char led;

int main(void)
{
	DDRB |= 0xff;
	PORTB = led;
	
    while(1)
    {
        led = pgm_read_byte(&tab[0]);
		PORTB = led;
		_delay_ms(delay);
		
		for(char i = 0; i<5; i++){
			led = pgm_read_byte(&tab[1]);
			PORTB = led;
			_delay_ms(delay);
			led = pgm_read_byte(&tab[2]);
			PORTB = led;
			_delay_ms(delay);
		}
		
		led = pgm_read_byte(&tab[3]);
		PORTB = led;
		_delay_ms(delay);
		
		for(char i = 0; i<5; i++){
			led = pgm_read_byte(&tab[4]);
			PORTB = led;
			_delay_ms(delay);
			
			led = pgm_read_byte(&tab[5]);
			PORTB = led;
			_delay_ms(delay);
		}
    }
}