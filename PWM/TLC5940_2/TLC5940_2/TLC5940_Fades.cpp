
#include "TLC5940_full.h"
#include "avr/interrupt.h"
#include "avr/delay.h"

// tlc object
TLC5940 tlc;
// loop counter
uint16_t count;
int8_t dir;

int main(void){
	
	count = 200;
	dir = 1;
	// set DC to full
	for (uint8_t i=0; i<TLC5940_LED_N; i++) {
		tlc.setDC(i, 63);
	}
	// initialize the led driver
	tlc.init();



	while(1){
		// give it some new data
		for (uint8_t i=0; i<TLC5940_LED_N; i++) {
			tlc.setGS(i, count);
		}
		// tell the driver to update
		tlc.update();

		// set loop direction
		if (dir==1 && count>=4000) {
			dir = -1;
		}
		else if (dir==-1 && count<=300) {
			dir = 1;
		}
		// increment counter
		count += dir*100;

		// delay
		_delay_ms(50);
	}
}

// ISR for serial data input into TLC5940
ISR(TIMER0_COMP_vect) {
	tlc.refreshGS();
}