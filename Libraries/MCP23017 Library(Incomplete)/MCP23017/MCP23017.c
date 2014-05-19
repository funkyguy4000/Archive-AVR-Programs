/*
 * MCP23017.c
 *
 * Created: 10/31/2013 12:04:17 PM
 *  Author: Shannon Strutz
 */ 


#include <avr/io.h>

//MCP23017 Address definitions.  A1, A2, A3 are set by either grounding or pulling up each pin. 
#define ADDR = 0100b;    //Don't change, native to MCP23017
#define A1 = 0b;			//0 = Ground, 1 = VCC
#define A2 = 0b;			//0 = Ground, 1 = VCC
#define A3 = 0b;			//0 = Ground, 1 = VCC
#define DeviceAddress = ADDR + A1 + A2 + A3;  //Testing binary address
//#define DeviceAddress = strcat(strcat(strcat(ADDR, A1), A2) ,A3);  //strcat is only a 2 param function.  this a quick and dirty way to do it though.


//IOCON - Input-Output Configuration register
#define IOCON = 01011000b; 

//MCP23017 Register Addresses   bit 7 -----> bit 0    | bit functions |
#define IODIRA = 00h;	// IO7 - IO6 - IO5 - IO4 - IO3 - IO2 - IO1 - IO0
#define IODIRB = 01h;	// IO7 - IO6 - IO5 - IO4 - IO3 - IO2 - IO1 - IO0
#define IPOLA = 02h;	// IP7 - IP6 - IP5 - IP4 - IP3 - IP2 - IP1 - IP0
#define IPOLB = 03h;	// IP7 - IP6 - IP5 - IP4 - IP3 - IP2 - IP1 - IP0
#define GPINTENA = 04h; // GPINT7 - GPINT6 - GPINT5 - GPINT4 - GPINT3 - GPINT2 - GPINT1 - GPINT0
#define GPINTENB = 05h; // GPINT7 - GPINT6 - GPINT5 - GPINT4 - GPINT3 - GPINT2 - GPINT1 - GPINT0
#define DEFVALA = 06h;	// DEF7 - DEF6 - DEF5 - DEF4 - DEF3 - DEF2 - DEF1 - DEF0 
#define DEFVALB = 07h;	// DEF7 - DEF6 - DEF5 - DEF4 - DEF3 - DEF2 - DEF1 - DEF0 
#define INTCONA = 08h;  // IOC7 - IOC6 - IOC5 - IOC4 - IOC3 - IOC2 - IOC1 - IOC0
#define INTCONB = 09h;  // IOC7 - IOC6 - IOC5 - IOC4 - IOC3 - IOC2 - IOC1 - IOC0
#define IOCON = 0A;		// BANK - MIRROR - SEQOP - DISSLW - DAEN - ODR - INTPOL - (null)
						// IOCON is a device wide register and doesn't vary between banks
#define GPPUA = 0C;		// PU7 - PU6 - PU5 - PU4 - PU3 - PU2 - PU1 - PU0
#define GPPUA = 0D;		// PU7 - PU6 - PU5 - PU4 - PU3 - PU2 - PU1 - PU0
#define INTFA = 0E;		// INT7 - INT6 - INT5 - INT4 - INT3 - INT2 - INT1 - INT0
#define INTFB = 0F;		// INT7 - INT6 - INT5 - INT4 - INT3 - INT2 - INT1 - INT0
#define INTCAPA = 10;	// ICP7 - ICP6 - ICP5 - ICP4 - ICP3 - ICP2 - ICP1 - ICP0
#define INTCAPB = 11;	// ICP7 - ICP6 - ICP5 - ICP4 - ICP3 - ICP2 - ICP1 - ICP0
#define GPIOA = 12;		// GP7 - GP6 - GP5 - GP4 - GP3 - GP2 - GP1 - GP0 
#define GPIOB = 13;		// GP7 - GP6 - GP5 - GP4 - GP3 - GP2 - GP1 - GP0
#define OLATA = 14;		// OL7 - OL6 - OL5 - OL4 - OL3 - OL2 - OL1 - OL0
#define OLATB = 15;		// OL7 - OL6 - OL5 - OL4 - OL3 - OL2 - OL1 - OL0

void TWIInit(void){
	//sets SCL to 400kHz
	TWSR = 0x00;
	TWBR = 0x0C;
	//enable TWI
	TWCR = (1<<TWEN);
}

void TWIStart(void){
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while ((TWCR & (1<<TWINT)) == 0);
}

void TWIStop(void){
	TWCR = (1<<TWINT)|(1<<TWSTO)|(1<<TWEN);
}

void TWIWrite(uint8_t u8data){
	TWDR = u8data;
	TWCR = (1<<TWINT)|(1<<TWEN);
	while ((TWCR & (1<<TWINT)) == 0);
}


int main(void)
{
    while(1)
    {
		
    }
}