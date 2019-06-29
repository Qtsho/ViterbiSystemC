#include "driver.h"
#include "encoder.h"
#include "systemc.h"


int sc_main(int argc, char* argv[])
{
	sc_core::sc_report_handler::set_actions("/IEEE_Std_1666/deprecated",
		sc_core::SC_DO_NOTHING);

	sc_signal<sc_bit, SC_MANY_WRITERS> in, out1, out2;
	sc_clock clk("clock", 20, SC_NS, 0.5, 1, SC_NS, true);
	sc_trace_file* tf;

	driver d1("driver");
	d1.in(in);

	Convolution_Encoder e("ConvolutionalEncoder");
	e.in(in);
	e.clk(clk);
	e.op1(out1);
	e.op2(out2);


	tf = sc_create_vcd_trace_file("Sim");
	tf->set_time_unit(1, SC_NS);
	sc_trace(tf, clk, "Clock");
	sc_trace(tf, in, "InputBit");
	sc_trace(tf, out1, "OutputBit1");
	sc_trace(tf, out2, "OutputBit2");

	sc_start();/**< start the simulation and run indefinately */

	return 0;/**< Return Success */
}