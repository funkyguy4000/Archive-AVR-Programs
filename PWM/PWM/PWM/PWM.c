/*
	Hardware PWM example on ATmega16
	
	This code was mostly not written by Shannon Strutz
	Most credit goes to clawson on AVRfreaks.com
		
	Added global PWM speed output
	
	Although if you need help I can explain it
	
	----Connections----
	Since our output is going to be on the Output Compare pin 1
	we are going to connect our LED to the OCR1A pin, which is located at PD5
	Shoot a resistor after that to ground and we'll be golden
	
 *  Author: Shannon Strutz
 *	Website: www.shannonstrutz.com
 *	E-mail: strutz.shannon@gmail.com

 *	This code is under the Creative Commons Attribution-ShareAlike 3.0 Unported License
 *	A human-readable of this license is here: http://creativecommons.org/licenses/by-sa/3.0/
 *	A full legal text of this license is here: http://creativecommons.org/licenses/by-sa/3.0/legalcode
 

*/
#define F_CPU 1000000UL

#include <avr/io.h> 
#include <util/delay.h> 
#include <avr/pgmspace.h> 
#include <avr/interrupt.h> 
#include <avr/sleep.h> 

enum { UP, DOWN }; 

volatile uint16_t pwm;      //pwm counter var 

#define speed 1

int main(void) 
{ 
    /* Timer 1 is 10-bit PWM (8-bit PWM on some ATtinys). 
      Setting WGM10 & WGM11 only will give phase correct PWM 
      Setting WGM12 also will give fast PWM, but that's on TCCR1B 
      COM1A1 = Clear OC1A on match when upcounting-Set OC1A 
               when downcounting on match 
   */ 
    TCCR1A |= ((1<<WGM10)|(1<<WGM11)|(1<<COM1A1)); 
   /* Clock Selects are for prescallers 
      Current CS10 is for clock without prescalling 
      Prescaler    8 = (1<<CS11) 
      Prescaler   64 = ((1<<CS11)|(1<<CS10)) 
      Prescaler  256 = (1<<CS12) 
      Prescaler 1024 = ((1<<CS12)|(1<<CS10)) 
   */ 
    TCCR1B |= ((1<<WGM12)|(1<<CS10)); 

    // Set Timer1/PWM register value to 0. 
    OCR1A = 0; 

    /* Enable OC1A ie PD5 as output. 
         */ 
    DDRD = (1<<5); 

    // Enable timer1 overflow interrupt. 
    TIMSK = (1<<TOIE1); 

    sei (); 

    // loop forever, the interrupts are doing the rest 
    for (;;) {                    
        sleep_mode(); 
   } 
} 


ISR (TIMER1_OVF_vect) 
{ 
    static uint8_t direction;   //enum var 
   static uint8_t slow_down; 

   slow_down++; 
   if (slow_down == 10) { 
      switch (direction)          
      { 
         case UP:   //increment counter and check against Max-1 
            pwm = pwm + speed; 
            if (pwm >= 1023) 
            //start the counting other direction 
               direction = DOWN; 
            break; 

         case DOWN:   //decrement counter and check against min 
            pwm = pwm - speed; 
            if (pwm == 0) 
            //start counting in other direction 
               direction = UP; 
            break; 
      } 
      //set the calc'd value to Timer1 output register 
      OCR1A = pwm; 
      slow_down = 0; 
   } 
} 