/*
 * IncFile2.h
 *
 * Created: 1/13/2014 5:32:52 PM
 *  Author: ShannonS
 */ 


#ifndef AS3935_config_H_
#define AS3935_config_H_


//defines communication mode.  0= SPI, 1 = I2C (default)
bool DATA_TRANSFER_MODE = 1;
//defines where the sensor is located false = Outdoor, true = Indoor (default)
bool SETTING = true;

//defines addresses for I2C communication.  Bit 1 and 2 are defined by pins 5 and 6
//to change, alter the solder jumpers on the board.
#define AS3935_ADDRESS_WRITE	0x06	//00000110
#define AS3935_ADDRESS_READ		0x07	//00000111




#endif /* AS3935_config_H_ */