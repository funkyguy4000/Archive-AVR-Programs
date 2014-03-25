/*
 * USART.h
 *
 * Created: 3/22/2014 10:55:31 AM
 *  Author: student
 */ 


#ifndef USART_H_
#define USART_H_

#include <avr/io.h>
#include "USART_config.h"

int USART_Init(void){
	UCSRB = (1 << RXEN) | (1<<TXEN);
	UCSRC = (1 << URSEL) | (1 << UCSZ0) | (1 << UCSZ1);
	
	UBRRH = (BAUD_PRESCALE >> 8);
	UBRRL = BAUD_PRESCALE;
	
	return 1;
}

int send_UART(uint8_t data){
	while ((UCSRA & (1<< UDRE)) == 0) {};
	UDR = data;
	return 1;
}

uint8_t read_UART(){
	while ((UCSRA & (1<<RXC)) == 0) {};
	uint8_t data = UDR;
	return data;
}



#endif /* USART_H_ */