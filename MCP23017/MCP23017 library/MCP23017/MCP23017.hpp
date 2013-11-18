/*
 * IncFile1.hpp
 *
 * Created: 11/3/2013 10:23:59 PM
 *  Author: ShannonS
 */ 


#ifndef MCP23017_HPP_
#define MCP23017_HPP_

#define F_CPU 8000000UL

#include <inttypes.h>

#define IODIRA = 0x00;		// IO7 - IO6 - IO5 - IO4 - IO3 - IO2 - IO1 - IO0
#define IODIRB = 0x01;		// IO7 - IO6 - IO5 - IO4 - IO3 - IO2 - IO1 - IO0
#define IPOLA = 0x02;		// IP7 - IP6 - IP5 - IP4 - IP3 - IP2 - IP1 - IP0
#define IPOLB = 0x03;		// IP7 - IP6 - IP5 - IP4 - IP3 - IP2 - IP1 - IP0
#define GPINTENA = 0x04;	// GPINT7 - GPINT6 - GPINT5 - GPINT4 - GPINT3 - GPINT2 - GPINT1 - GPINT0
#define GPINTENB = 0x05;	// GPINT7 - GPINT6 - GPINT5 - GPINT4 - GPINT3 - GPINT2 - GPINT1 - GPINT0
#define DEFVALA = 0x06;		// DEF7 - DEF6 - DEF5 - DEF4 - DEF3 - DEF2 - DEF1 - DEF0
#define DEFVALB = 0x07;		// DEF7 - DEF6 - DEF5 - DEF4 - DEF3 - DEF2 - DEF1 - DEF0
#define INTCONA = 0x08;		// IOC7 - IOC6 - IOC5 - IOC4 - IOC3 - IOC2 - IOC1 - IOC0
#define INTCONB = 0x09;		// IOC7 - IOC6 - IOC5 - IOC4 - IOC3 - IOC2 - IOC1 - IOC0
#define IOCON = 0x0A;		// BANK - MIRROR - SEQOP - DISSLW - DAEN - ODR - INTPOL - (null)
							// IOCON is a device wide register and doesn't vary between banks
#define GPPUA = 0x0C;		// PU7 - PU6 - PU5 - PU4 - PU3 - PU2 - PU1 - PU0
#define GPPUB = 0x0D;		// PU7 - PU6 - PU5 - PU4 - PU3 - PU2 - PU1 - PU0
#define INTFA = 0x0E;		// INT7 - INT6 - INT5 - INT4 - INT3 - INT2 - INT1 - INT0
#define INTFB = 0x0F;		// INT7 - INT6 - INT5 - INT4 - INT3 - INT2 - INT1 - INT0
#define INTCAPA = 0x10;		// ICP7 - ICP6 - ICP5 - ICP4 - ICP3 - ICP2 - ICP1 - ICP0
#define INTCAPB = 0x11;		// ICP7 - ICP6 - ICP5 - ICP4 - ICP3 - ICP2 - ICP1 - ICP0
#define GPIOA = 0x12;		// GP7 - GP6 - GP5 - GP4 - GP3 - GP2 - GP1 - GP0
#define GPIOB = 0x13;		// GP7 - GP6 - GP5 - GP4 - GP3 - GP2 - GP1 - GP0
#define OLATA = 0x14;		// OL7 - OL6 - OL5 - OL4 - OL3 - OL2 - OL1 - OL0
#define OLATB = 0x15;		// OL7 - OL6 - OL5 - OL4 - OL3 - OL2 - OL1 - OL0

#define MCP23017_BASE_ADDRESS 0x40

typedef struct {
	uint8_t address;        //        the address of the device
	uint16_t data;                //        data to/from device
} MCP23017;


//
void mcp23017_init(MCP23017 obj, uint8_t address);

//
void mcp23017_write(MCP23017 *object);


#endif /* MCP23017_HPP_ */