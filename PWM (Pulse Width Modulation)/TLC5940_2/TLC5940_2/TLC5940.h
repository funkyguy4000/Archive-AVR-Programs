#ifndef TLC5940_H
#define TLC5940_H

#include <avr/io.h>
#include <inttypes.h>
#include <stdlib.h>


//these are the necessary pin definitions
// TLC signal - AVR signal - AVR pin
// GSCLK - INT1 - PD3
// SCLK - SCK - PB7
// XLAT - OC1A - PD5
// BLANK - ~SS - PB4
// SIN - MOSI - PB5

// grayscale lock  *
#ifndef TLC5940_GS_PORT
#define TLC5940_GS_PORT PORTD
#endif
#ifndef TLC5940_GS_PIN
#define TLC5940_GS_PIN 3
#endif
// serial clock  *
#ifndef TLC5940_SCK_PORT
#define TLC5940_SCK_PORT PORTB
#endif
#ifndef TLC5940_SCK_PIN
#define TLC5940_SCK_PIN 7
#endif
// latch  *
#ifndef TLC5940_XLAT_PORT
#define TLC5940_XLAT_PORT PORTD
#endif
#ifndef TLC5940_XLAT_PIN
#define TLC5940_XLAT_PIN 5
#endif
// programming select
#ifndef TLC5940_VPRG_PORT
#define TLC5940_VPRG_PORT PORTD
#endif
#ifndef TLC5940_VPRG_PIN
#define TLC5940_VPRG_PIN  7
#endif
// blank outputs - pullup resistor
#ifndef TLC5940_BLANK_PORT
#define TLC5940_BLANK_PORT PORTB
#endif
#ifndef TLC5940_BLANK_PIN
#define TLC5940_BLANK_PIN 4
#endif
// serial data master out slave in
#ifndef TLC5940_MOSI_PORT
#define TLC5940_MOSI_PORT PORTB
#endif
#ifndef TLC5940_MOSI_PIN
#define TLC5940_MOSI_PIN 5
#endif

#ifndef TLC5940_N
#define TLC5940_N 3
#endif

#define TLC5940_LED_N 16 * TLC5940_N


typedef struct{
	
    uint8_t dc[TLC5940_LED_N];
    // gs array
    uint16_t gs[TLC5940_LED_N];
    // new gs data flag
    volatile bool newData;
} TLC5940;


void InitSPI(void) {
	DDRB |= (1<<PB5) | (1<<PB4) | (1<<PB7);					//Sets SS, MOSI, and SCK as output
	PORTB &= ~((1<<PB5) | (1<<PB4) | (1<<PB7));			//Sets the control pins
	
	//SPI Configuration Register  SPE = SPI Enable  MSTR = Master
	SPCR = ( (1<<SPE) | (1<<MSTR) | (1<<SPR1) | (1<<SPR0));		//Enable SPI, Master, set clock rate fck/128
}



// initilize the chip by filling the dc data
void init(void);
// set the dot correction array
void setDC(uint8_t led, uint8_t val);
// set the brightness of an led in the array
void setGS(uint8_t led, uint16_t val);
// tell the chip to clock in the data from the GS array
void update(void);
// gs refresh function (lives in an ISR that fires ever 4096 greyscale clocks)
void refreshGS(void);

// serial data function - returns if a latch is needed or not
bool serialCycle(void);

#endif