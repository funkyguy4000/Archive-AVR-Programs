/*
 * _2x2_button_matrix.c
 *
 * Created: 9/9/2013 10:36:58 PM
 *  Author: ShannonS
 */ 

#define F_CPU 8000000UL

#include <util/delay.h>
#include <avr/io.h>
#include <inttypes.h>

//Power comes in the "switch" node and goes to the ground pins
#define Button1 PC0
#define Button2 PC1
#define Button3 PC2
#define Button4 PC3

//This board uses common cathode RGB LEDs
#define ledGnd1 PC4
#define ledGnd2 PC5
#define ledGnd3 PC6
#define ledGnd4 PC7

//LED anodes
#define redLED PD4
#define greenLED PD5
#define blueLED PD6

//Color definitions

uint16_t red[3] = {255, 0, 0};
uint16_t green[3] = {0, 255, 0};
uint16_t blue[3] = {0, 0, 255};
uint16_t purple[3] = {255,0,150};
uint16_t yellow[3] = {255, 255, 0};
uint16_t dark[3] = {0, 0, 0};


void ledColor(uint16_t led1[], uint16_t led2[], uint16_t led3[], uint16_t led4[]){
	//analog write the leds to their respective led color values
	
	
}



int main(void)
{
	//Set buttons as inputs, ledGnds as outputs
	DDRC &= ~Button1 & ~Button2 & ~Button3 & ~Button4;
	DDRC |= ledGnd1 | ledGnd2 | ledGnd3 | ledGnd4;
	DDRD |= redLED | greenLED | blueLED;
	
    while(1)
    {
        //TODO:: Please write your application code 
		ledColor(yellow, red, purple, green);
    }
}

