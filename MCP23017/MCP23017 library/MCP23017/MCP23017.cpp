/*
 * MCP23017.cpp
 *
 * Created: 10/31/2013 2:14:20 PM
 *  Author: sstrutz
 */ 

#include <avr/io.h>
#include <stdio.h>
#include "MCP23017.hpp"

void mcp23017_init(MCP23017 obj, uint8_t address) {
	obj->address = MCP23017_BASE_ADDRESS + address;
}

void mcp23017_write(MCP23017 *object) {
	
}




//////////////////////////////////////////
// Two-Wire Interface (TWI) Methods
// Inter-Integrated Circuit (I²C) Methods
// Pro-tip, they are the same thing
//////////////////////////////////////////

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

uint8_t TWIReadACK(void)
{
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	while ((TWCR & (1<<TWINT)) == 0);
	return TWDR;
}
//read byte with NACK
uint8_t TWIReadNACK(void)
{
	TWCR = (1<<TWINT)|(1<<TWEN);
	while ((TWCR & (1<<TWINT)) == 0);
	return TWDR;
}

uint8_t TWIGetStatus(void)
{
	uint8_t status;
	//mask status
	status = TWSR & 0xF8;
	return status;
}

int main(){
	
	while(1){
		
	}
}