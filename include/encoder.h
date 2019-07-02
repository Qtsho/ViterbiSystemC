//#ifndef VITERBIENCODER_H_
#define CONVOENCODER_H_

#include<systemc.h>

SC_MODULE(Convolution_Encoder) {

	sc_in<bool> clk;
	sc_in<sc_bit> in;
	sc_bit s0, s1, s2, s3;
	sc_bv<4> reg;
	sc_out<sc_bit> op1, op2;
	
	

	void encode();

	SC_CTOR(Convolution_Encoder) {
		reg = "0000"; // init
		SC_THREAD(encode);
		sensitive << clk;
	}

};
