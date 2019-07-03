#define VITERBIDECODER_H_

#include<systemc.h>


SC_MODULE(Viterbi_Decoder) {

	sc_in<bool> clk;
	sc_in<sc_bit> inp1, inp2;
	sc_out<sc_bit> ob1, ob2, ob3, ob4, ob5, ob6, ob7;
	//HERE WRITE THE CODE
	//HERE WRITE THE CODE
	//HERE WRITE THE CODE


	void decode();

	SC_CTOR(Viterbi_Decoder) {
		SC_THREAD(decode);
		sensitive << clk;
	}

};