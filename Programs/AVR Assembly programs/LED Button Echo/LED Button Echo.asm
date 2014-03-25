/*
 * LED_Button_Echno.asm
 *
 *  Created: 2/24/2014 1:37:51 PM
 *   Author: Shannon Strutz
 */ 

 .include "m8515def.inc"
 .def temp = r16

 start:

	ldi temp, 0xff	;sets temp to 1
	out DDRB, temp ;sets out to temp

	ldi temp, 0x00	;sets temp to 0
	out DDRD, temp	;inupts 

 check:
	ldi temp, 0x00
	in temp, PIND
	out PORTB, temp	;port inputs 
	rjmp check

	
	