//#ifndef VITERBIENCODER_H_
#define VITERBIENCODER_H_

#include<systemc.h>

SC_MODULE(Viterbi_Encoder) {

	sc_in<bool> clk;
	sc_in<sc_bit> in;
	sc_out<sc_bit> op1, op2;
	sc_bv<4> r;
	sc_bit s0, s1, s2, s3;

	void encode();

	SC_CTOR(Viterbi_Encoder) {
		r = "0000";
		SC_THREAD(encode);
		sensitive << clk;
	}

};
