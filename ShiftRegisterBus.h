
#ifndef ShiftRegisterBus_h
#define ShiftRegisterBus_h
#include <inttypes.h>
#include <Arduino.h>
#define _CCB_SEND    0
#define _CCB_RECEIVE 1
class ShiftRegisterBus {
	public:
		ShiftRegisterBus(uint8_t, uint8_t,uint8_t,uint8_t);
		void init();
		void write(byte*, int8_t);
	private:
		void writeByte(byte);
		void ccb(byte*, int8_t,uint8_t);
		int _do_pin;
		int _cl_pin;
		int _latch_pin;
		int _strobe_pin;		
};
#endif