#define VITERBIDECODER_H_

#include<systemc.h>


SC_MODULE(Viterbi_Decoder) {

	sc_in<bool> clk;
	sc_in<sc_bit> in;
	sc_out<sc_bit> output
	sc_bv<4> r;
	sc_bit s0, s1, s2, s3;

	void decode();

	SC_CTOR(Viterbi_Decoder) {
		r = "0000";
		SC_THREAD(decode);
		sensitive << clk;
	}

};
