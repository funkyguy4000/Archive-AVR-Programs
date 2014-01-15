/*
 * AS3935.cpp
 *
 * Created: 1/13/2014 5:31:17 PM
 *  Author: ShannonS
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include <stdio.h>

#include "AS3935_config.h"
#include "AS3935.h"



//TWI communication discussed on page 221 in ATmega328p datasheet


//Interrupt request
//pin 2 on Arduino
//PD2 on ATmega328p

void init(){
	
	//Enable Global Interrupts
	sei();
	//Set Interrupt register to interrupt on rising edge
	EICRA |= (1<<ISC01)|(1<<ISC00);
	
	//I2C tree
	if (DATA_TRANSFER_MODE == 1)
	{
		//Initiate I2C bus
		TWIInit();
		
		//Set initial registers
		//Sets the AFE Gain/Power-down
		if (SETTING == false){
			registerWrite(0x00, 0b0011100);
		}
		else if(SETTING == true){
			registerWrite(0x00, 0b0100100);
		}
		else{
			printf("Invalid SETTING configuration.  Please fix in AS3935_conf.h");
		}	
		
		//
			
	}
	else if (DATA_TRANSFER_MODE == 0){
		
	}
	else{
		printf("Invalid transfer mode selected.  Please fix in AS3935_config.h");
	}
	
}

ISR(INT0_vect)
{
	volatile uint8_t Strike_Type = registerRead(0x03);
	volatile uint8_t Distance = registerRead(0x07);
	volatile uint8_t EnergyL = registerRead(0x04);
	volatile uint8_t EnergyM = registerRead(0x05);
	volatile uint8_t EnergyMM = registerRead(0x06);
	
	cli();
}

