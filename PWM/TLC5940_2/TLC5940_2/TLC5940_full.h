#include "TLC5940.h"
// give the variables some default values
/*
TLC5940(void) {
	// initialize variables at all leds off for safety and dot correction to full brightness
	for (uint8_t i=0; i<(16 * TLC5940_N); i++) {
		setDC(i, 63);
	}
	for (uint8_t i=0; i<(16 * TLC5940_N); i++) {
		setGS(i, 0);
	}

	newData = false;
}
*/

// initialize the pins and set dot correction


#define SPI_DDR		DDRB
#define SPI_PORT	PORTB
#define GS_XT_DDR	DDRD
#define GS_XT_PORT	PORTD

#define BLANK		PB4
#define MOSI		PB5
#define MISO		PB6
#define SCLK		PB7
#define GSCLK		PD3
#define XLAT		PD5

#define NUM_TLC		4

void PulseLatch(void){
	GS_XT_PORT |= (1<<XLAT);
	GS_XT_PORT &= ~(1<<XLAT);
}

void PulseSCLK(void){
	SPI_PORT |= (1<<SCLK);
	SPI_PORT &= ~(1<<SCLK);
}

void init(void) {
	
	// Serial Clock, AVR signal = SCK = PB7
	// Blank, AVR signal = ~SS = PB4
	// Serial Data, AVR signal = MOSI = PB5
	SPI_DDR |= (1<<MOSI) | (1<<BLANK) | (1<<SCLK);			//Sets MOSI, ~SS, and SCK as outputs
	SPI_PORT &= ~((1<<MOSI) & ~(1<<BLANK) & ~(1<<SCLK));	//Sets MOSI, ~SS, and SCK low
	
	// Grayscale Clock, AVR signal = INT1 = PD3
	// External Latch, AVR signal = OC1A = PD5
	GS_XT_DDR |= (1<<GSCLK) | (1<<XLAT);	//Sets PD3 as output
	GS_XT_PORT &= ~(1<<GSCLK) & ~(1<<XLAT);	//Sets PD3 low
	


	// pulse the serial clock (96 * number-of-drivers) times to write in dc data
	for (uint16_t i=0; i<(96 * TLC5940_N); i++) {
		// get the bit the tlc5940 is expecting from the gs array (tlc expects msb first)
		
		//uint8_t data = (dc[((96 * TLC5940_N) - 1 - i)/6]) & (1 << ((96 * TLC5940_N) - 1 - i)%6);
		
		// set mosi if bit is high, clear if bit is low
		/*
		if (data) {
			SPI_PORT |= (1 << MOSI);
		}
		else {
			SPI_PORT &= ~(1 << MOSI);
		}
		*/
		PulseSCLK();
	}

	// pulse xlat to latch the data
	PulseLatch();

	// enable leds
	SPI_PORT &= ~(1 << BLANK);
}

/*
// refresh the led display and data
void refreshGS(void) {
	bool gsFirstCycle = false;
	static bool needLatch = false;

	// disable leds before latching in new data
	SPI_PORT |= (1 << BLANK);

	// check if vprg is still high
	if ( TLC5940_VPRG_PORT & (1 << TLC5940_VPRG_PIN) ) {
		// pull VPRG low and set the first cycle flag
		TLC5940_VPRG_PORT &= ~(1 << TLC5940_VPRG_PIN);
		gsFirstCycle = true;
	}

	// check if we need a latch
	if (needLatch) {
		needLatch = false;
		TLC5940_XLAT_PORT |= (1 << TLC5940_XLAT_PIN);
		TLC5940_XLAT_PORT &= ~(1 << TLC5940_XLAT_PIN);
	}

	// check if this was the first gs cycle after a dc cycle
	if (gsFirstCycle) {
		gsFirstCycle = false;
		// pulse serial clock once if it is (because the datasheet tells us to)
		TLC5940_SCK_PORT |= (1 << TLC5940_SCK_PIN);
		TLC5940_SCK_PORT &= ~(1 << TLC5940_SCK_PIN);
	}

	// enable leds
	TLC5940_BLANK_PORT &= ~(1 << TLC5940_BLANK_PIN);
	
	// clock in new gs data
	needLatch = serialCycle();
}


bool serialCycle(void) {
	// if there's data to clock in
	if (newData) {
		newData = false;
		for (uint16_t dataCount=0; dataCount<192*TLC5940_N; dataCount++) {
			// get the bit the tlc5940 is expecting from the gs array (tlc expects msb first)
			uint16_t data = (gs[((192 * TLC5940_N) - 1 - dataCount)/12]) & (1 << ((192 * TLC5940_N) - 1 - dataCount)%12);
			// set mosi if bit is high, clear if bit is low
			if (data) {
				TLC5940_MOSI_PORT |= (1 << TLC5940_MOSI_PIN);
			}
			else {
				TLC5940_MOSI_PORT &= ~(1 << TLC5940_MOSI_PIN);
			}
			// pulse the serial clock
			TLC5940_SCK_PORT |= (1 << TLC5940_SCK_PIN);
			TLC5940_SCK_PORT &= ~(1 << TLC5940_SCK_PIN);
		}
		return true;
	}
	return false;
}

// set the new data flag
void update(void) {
	newData = true;
}

// set the brightness of an individual led
void setDC(uint8_t led, uint8_t val) {
	// basic parameter checking
	// check if led is inbounds
	if (led < (16 * TLC5940_N)) {
		// if value is out of bounds, set to max
		if (val < 64) {
			dc[led] = val;
		}
		else {
			dc[led] = 63;
		}
	}
}

// set the brightness of an individual led
void setGS(uint8_t led, uint16_t val) {
	// basic parameter checking
	// check if led is inbounds
	if (led < (16 * TLC5940_N)) {
		// if value is out of bounds, set to max
		if (val < 4096) {
			gs[led] = val;
		}
		else {
			gs[led] = 4095;
		}
	}
}
*/