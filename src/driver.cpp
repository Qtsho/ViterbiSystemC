#include "systemc.h"
#include "driver.h"

void driver::encoder_driver() {

	int wt = 10;

//
	// out = sc_bit('1');
	// wait(wt, SC_NS);

	// out = sc_bit('0');
	// wait(wt, SC_NS);

	// out = sc_bit('1');
	// wait(wt, SC_NS);

	// out = sc_bit('1');
	// wait(wt, SC_NS);

	// out = sc_bit('0');
	// wait(wt, SC_NS);

	// out = sc_bit('0');
	// wait(wt, SC_NS);

	// out = sc_bit('0');
	// wait(wt, SC_NS);
	in = sc_bit('1');
	wait(wt, SC_NS);
	
	in = sc_bit('0');
	wait(wt, SC_NS);

	in = sc_bit('1');
	wait(wt, SC_NS);

	in = sc_bit('1');
	wait(wt, SC_NS);

	in = sc_bit('0');
	wait(wt, SC_NS);

	in = sc_bit('0');
	wait(wt, SC_NS);

	in = sc_bit('0');
	wait(wt, SC_NS);

	
	sc_stop();

}
