/*
 * tlc_config.h
 *
 * Created: 11/18/2013 12:01:00 AM
 *  Author: ShannonS
 */ 


#ifndef TLC_CONFIG_H_
#define TLC_CONFIG_H_

#include <stdint.h>

#define VPRG		SPI

#define SPI_DDR		DDRB
#define SPI_PORT	PORTB
#define GS_XT_DDR	DDRD
#define GS_XT_PORT	PORTD

#define BLANK		PB4 //~SS to Blank
#define MOSI		PB5 //Mosi To Serial In
#define MISO		PB6 //Miso To Nothing
#define SCLK		PB7 //SCK To SCLK
#define GSCLK		PD3 //(PCINT0/CLK0/ICP1) to GSCLK
#define XLAT		PD5 //OC1A to XLAT

#define NUM_TLC		4


//change to uint16_t if you are using more than 16 
#define TLC_CHANNEL_TYPE uint8_t



#endif /* TLC_CONFIG_H_ */