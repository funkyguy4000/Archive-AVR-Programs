/*
 * Program_1.asm
 *
 *  Created: 2/3/2014 1:37:39 PM
 *   Author: Shannon Strutz
 */ 


.include "m8515def.inc"

.def temp = r16

start:
	ldi temp, low(RAMEND)  ;load SPL (the low byte of the stack)
	out SPL, temp		   ;load low byte address to SPL pointer register
	ldi temp, high(RAMEND) ;load SPH (the hight byte of the stack)
	out SPH, temp		   ;load high byte address to SPH pointer register

	ldi temp, $ff		   ;Set up PORTB as outputs
	out DDRB, temp		   ;DDRB means "Data drection register B"
	out PORTB, temp
	nop

loadbyte:

	rol temp			   ;roll the bits
	out PORTB, temp		   ;update LEDs
	rcall one_sec_delay	   ;call the one_sec_delay
	rjmp loadbyte		   ;repeat
	nop

one_sec_delay:
	ldi r20, 20			   ;20d = 14h
	ldi r21, 25			   ;25d = 19h
	ldi r22, 25
	nop

delay:
							;delays with a nested loop
	dec r22					;255*255 total iterations
	brne delay				

	dec r21					;255 iterations
	brne delay

	dec r20					;20 iterations
	brne delay
	
	nop

	ret						;return