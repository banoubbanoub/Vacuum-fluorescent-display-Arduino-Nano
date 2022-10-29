
/*
This library implements the Sanyo CCB (Computer Control Bus).

CCB is a chip-to-chip communication protocol developed by Sanyo.
It is similar to Philips� I2C in its purpose, but  much simpler.

*/


#include <inttypes.h>
#include "ShiftRegisterBus.h"


// Base delay (us).  Also used to time the CL (clock) line.
// 100us should be enough even for slow CCB devices.
#define CCB_DELAY 1   //100
/******************************\
 *        Constructor         *
 *  just set class variables  *
\******************************/
ShiftRegisterBus::ShiftRegisterBus(uint8_t do_pin, uint8_t cl_pin,uint8_t latch,uint8_t strobe) {
	_do_pin = do_pin;
	_cl_pin = cl_pin;
	_latch_pin=latch;
	_strobe_pin = strobe;
}
/******************************************\
 *                 init()                 *
 *  Set pin functions and initial states  *
\******************************************/ 
void ShiftRegisterBus::init() {
	pinMode(_do_pin, OUTPUT);
	pinMode(_cl_pin, OUTPUT);
	pinMode(_latch_pin,OUTPUT);
	pinMode(_strobe_pin,OUTPUT);
	digitalWrite(_do_pin, LOW);
	digitalWrite(_cl_pin, LOW);  // Clock-rest-low mode	
}
/************************************\
 *           writeByte()            *
 *  Send a single byte via CCB bus  *
\************************************/ 
void ShiftRegisterBus::writeByte(byte data) {
	// Send one byte out bia CCB bus (LSB first)
	for(int8_t i = 0; i <= 7; i++) {
	    digitalWrite(_do_pin, bitRead(data, i));
		digitalWrite(_cl_pin, HIGH); //delayMicroseconds(CCB_DELAY);
		digitalWrite(_cl_pin, LOW);// delayMicroseconds(CCB_DELAY);
		}
}
/*****************************************\
 *                 ccb()                 *
 *  The universal send/receive function  *
\*****************************************/
void ShiftRegisterBus::ccb(byte *data, int8_t dataLength, uint8_t mode) {
	int8_t i; // i may reach negative values in the counters
	          // dataLength is typed "int8_t" for compatibility with this counter
	// Send the address, with the nibbles swapped (required by the CCB protocol to support 4-bit addresses)
	// Enter the data transfer mode
	digitalWrite(_cl_pin, LOW);
	switch(mode) {
		case _CCB_SEND:
		// Send data
		// Note: as CCB devices usually reads registers data from MSB to LSB, the buffer is read from left to right
		for(i = dataLength - 1; i >= 0; i--)
				writeByte(data[i]);
		digitalWrite(_do_pin, LOW);
		break; 
	}
}
/********************************************************\
 *                     write()                          *
 *  Send dataLength (up to 127) bytes via CCB bus       *
 * Note: the contents of the input buffer is send       *
 * backwards (from the rightmost to the leftmost byte), *
 * so the order of the data bytes must be the opposite  *
 * as the one shown on the device's datasheets          *
\********************************************************/ 
void ShiftRegisterBus::write( byte *data, int8_t dataLength) {
	ccb( data, dataLength, _CCB_SEND);

}
