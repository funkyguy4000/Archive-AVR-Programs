/*
 * ADC.c
 *
 * Created: 2/28/2014 2:20:38 PM
 *  Author: Shannon Strutz
 */ 

#include <avr/io.h>
#define F_CPU 4000000UL
#include <util/delay.h>

unsigned char turndistance = 0x7f;
unsigned char distance;
unsigned char output;

void ReadSensor(void){ 
	distance  = PIND;
}

void Backward(void){ 
	PORTB = 0b00000101;
}
void Forward(void){ 
	PORTB = 0b00001010;
}
void Left(void){ 
	PORTB = 0b000001001;
}
void Right(void){ 
	PORTB = 0b00000110;
}

int main(void)
{
	DDRB = 0xff; //output
	DDRD = 0x00; //input
	PORTD = 0x00;

	while(1)
	{
		ReadSensor();
		if(distance > 189)							Backward();
		else if(distance > 126 && distance <= 189)	Right();
		else if(distance > 63 && distance <= 126)   Left();
		else										Forward();
	}
}

