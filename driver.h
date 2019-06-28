//#ifndef DRIVER_H_
#define DRIVER_H_


#include "systemc.h"

SC_MODULE(driver) {

	sc_out<sc_bit> in;

	void encoder_driver();

	SC_CTOR(driver) {
		SC_THREAD(encoder_driver);
	}

};