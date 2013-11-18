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

#define BLANK		PB4
#define MOSI		PB5
#define MISO		PB6
#define SCLK		PB7
#define GSCLK		PD3
#define XLAT		PD5

#define NUM_TLC		4


//change to uint16_t if you are using more than 16 
#define TLC_CHANNEL_TYPE uint8_t



#endif /* TLC_CONFIG_H_ */