#include "sc_test_framework.h"
#include "serializer.h"
#include "clock_divider.h"

static const int clock_period = 14;
static const double clock_duty = 0.5;
static const int clock_start = 20;
static const int inputs = 8;

SC_TEST(serializer) {
	sc_clock sys_clock("sys_clock", clock_period, clock_duty, clock_start, false);
	sc_signal<sc_logic> ser_out;
	sc_signal<bool> ser_trig;
	sc_signal<sc_lv<inputs> > par_in;

	SC_STRACE(sys_clock);
	SC_STRACE(ser_out);
	SC_STRACE(par_in);
	SC_STRACE(ser_trig);

	clock_divider<inputs> clk_div("CLK_DIV");

	clk_div.clk_in(sys_clock);
	clk_div.clk_out(ser_trig);

	serializer<inputs> serializer("Serializer");
	serializer.ser_out(ser_out);
	serializer.clk_in(sys_clock);
	serializer.par_in(par_in);
	serializer.ser_trig(ser_trig);

	par_in = sc_lv<inputs>("00000000");
	sc_start(125, SC_NS);

	par_in = sc_lv<inputs>("10010010");
	sc_start(400, SC_NS);

}