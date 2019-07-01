#define VITERBIDECODER_H_

#include<systemc.h>


SC_MODULE(Viterbi_Decoder) {

	sc_in<bool> clk;
	sc_in<sc_bit> in;
	sc_out<sc_bit> out;
	//HERE WRITE THE CODE
	//HERE WRITE THE CODE
	//HERE WRITE THE CODE
	

	void decode();

	SC_CTOR(Viterbi_Decoder) {
		SC_THREAD(decode);
		sensitive << clk;
	}

};
