/*
 * IncFile1.h
 *
 * Created: 1/13/2014 5:32:45 PM
 *  Author: ShannonS
 */ 


#ifndef AS3935_H_
#define AS3935_H_



//Register table
#define Gain_Power	0x00	//Default 0100100	Bit[7:6] - Reserved, 	Bit[5:1] - AFE Gain Boost,	Bit[0] - Power-down
#define Noise_WD	0x01	//Default 0100001	Bit[6:4] - Noise Floor Level, Bit[3:0] - Watchdog threshold
#define CLS			0x02	//Default 11000010	Bit[7]   - Reserved,	Bit[6] - CL_STAT, Bit[5:4] - MIN_NUM_LIGH, Bit[3:0] - Spike Rejection
#define INT			0x03	//Default 0000000	Bit[7:6] - Frequency division ration for antenna tuning, Bit[5] - Mask Disturber, Bit[4] - Reserved, Bit[3:0] - Interrupt
#define ENERGY_L	0x04	//Default 00000000	Bit[7:0] - Energy of the Single Lightning LSBYTE
#define ENERGY_M	0x05	//Default 00000000	Bit[7:0] - Energy of the Single Lightning MSBYTE
#define ENERGY_MM	0x06	//Default 00000000	Bit[7:5] - Reserved, Bit[4:0] - Energy of the Single Lightning MMSBYTE
#define DISTANCE	0x07	//Default 00000000	Bit[7:6] - Reserved, Bit[5:0] - Distance Estimation
#define DIS_TUN		0x08	//Default 0000000	Bit[7] - Display LCO on IRQ pin, Bit[6] - Display SRCO on IRQ pin, Bit[5] - Display TRCO on IRQ pin, Bit[3:0] - TUN_CAP
#define LDLUT1		0x09	//Bit[7:0] - Lightning Detection Look-up
#define LDLUT2		0x0A	//Bit[7:0] - Lightning Detection Look-up
#define LDLUT3		0x0B	//Bit[7:0] - Lightning Detection Look-up
#define LDLUT4		0x0C	//Bit[7:0] - Lightning Detection Look-up
#define LDLUT5		0x0D	//Bit[7:0] - Lightning Detection Look-up
#define LDLUT6		0x0E	//Bit[7:0] - Lightning Detection Look-up
#define LDLUT7		0x0F	//Bit[7:0] - Lightning Detection Look-up
#define LDLUT8		0x10	//Bit[7:0] - Lightning Detection Look-up
#define LDLUT9		0x11	//Bit[7:0] - Lightning Detection Look-up
#define LDLUT10		0x12	//Bit[7:0] - Lightning Detection Look-up
#define LDLUT11		0x13	//Bit[7:0] - Lightning Detection Look-up
#define LDLUT12		0x14	//Bit[7:0] - Lightning Detection Look-up
#define LDLUT13		0x15	//Bit[7:0] - Lightning Detection Look-up
#define LDLUT14		0x16	//Bit[7:0] - Lightning Detection Look-up
#define LDLUT15		0x17	//Bit[7:0] - Lightning Detection Look-up
#define LDLUT16		0x18	//Bit[7:0] - Lightning Detection Look-up
#define LDLUT17		0x19	//Bit[7:0] - Lightning Detection Look-up
#define LDLUT18		0x1A	//Bit[7:0] - Lightning Detection Look-up
#define LDLUT19		0x1B	//Bit[7:0] - Lightning Detection Look-up
#define LDLUT20		0x1C	//Bit[7:0] - Lightning Detection Look-up
#define LDLUT21		0x1D	//Bit[7:0] - Lightning Detection Look-up
#define LDLUT22		0x1E	//Bit[7:0] - Lightning Detection Look-up
#define LDLUT23		0x1F	//Bit[7:0] - Lightning Detection Look-up
#define LDLUT24		0x20	//Bit[7:0] - Lightning Detection Look-up
#define LDLUT25		0x21	//Bit[7:0] - Lightning Detection Look-up
#define LDLUT26		0x22	//Bit[7:0] - Lightning Detection Look-up
#define LDLUT27		0x23	//Bit[7:0] - Lightning Detection Look-up
#define LDLUT28		0x24	//Bit[7:0] - Lightning Detection Look-up
#define LDLUT29		0x25	//Bit[7:0] - Lightning Detection Look-up
#define LDLUT30		0x26	//Bit[7:0] - Lightning Detection Look-up
#define LDLUT31		0x27	//Bit[7:0] - Lightning Detection Look-up
#define LDLUT32		0x28	//Bit[7:0] - Lightning Detection Look-up
#define LDLUT33		0x29	//Bit[7:0] - Lightning Detection Look-up
#define LDLUT34		0x2A	//Bit[7:0] - Lightning Detection Look-up
#define LDLUT35		0x2B	//Bit[7:0] - Lightning Detection Look-up
#define LDLUT36		0x2C	//Bit[7:0] - Lightning Detection Look-up
#define LDLUT37		0x2D	//Bit[7:0] - Lightning Detection Look-up
#define LDLUT38		0x2E	//Bit[7:0] - Lightning Detection Look-up
#define LDLUT39		0x2F	//Bit[7:0] - Lightning Detection Look-up
#define LDLUT40		0x30	//Bit[7:0] - Lightning Detection Look-up
#define LDLUT41		0x31	//Bit[7:0] - Lightning Detection Look-up
#define LDLUT42		0x32	//Bit[7:0] - Lightning Detection Look-up

void TWIInit(void){
	//set sCL to 400kHz by default
	TWSR = 0x00;
	TWBR = 0x0C;
	//enable TWI
	TWCR = (1<<TWEN);
}
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

uint8_t registerRead(uint8_t address){
	TWIStart();
	TWIWrite(AS3935_ADDRESS_WRITE);
	TWIReadACK();
	TWIWrite(address);	//
	TWIReadACK();
	TWIStart();
	TWIWrite(AS3935_ADDRESS_READ);
	TWIReadACK();
	uint8_t data = TWIReadNACK();
	TWIStop();
	return data;
	cli();
}
void registerWrite(uint8_t address, uint8_t data){
	TWIStart();
	TWIWrite(AS3935_ADDRESS_WRITE);
	TWIReadACK();
	TWIWrite(address);
	TWIReadACK();
	TWIWrite(data);
	TWIReadACK();
	TWIStop();
}


class AS3935
{
	public:
		void init();	//initializes AS3935 registers
		int exportData(uint8_t type, uint8_t dist, uint8_t EL, uint8_t EM, uint8_t EMM);
};

#endif /* AS3935_H_ */