#include "systemc.h"

SC_MODULE(monitor)
{
	sc_in<sc_bit> in;/**< Incoming bit to the Encoder */
	sc_out<sc_bit> op1, op2;/**< Output bits from the Encoder */
	sc_in<bool> clk;/**< Clock driver */
	sc_bv<4> r;
	sc_bit s0, s1, s2, s3;

	void prc_monitor();


	SC_CTOR(monitor)
	{

		SC_METHOD(prc_monitor);
		sensitive << clk;
	}
};