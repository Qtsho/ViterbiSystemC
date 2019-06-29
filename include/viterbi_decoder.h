#define VITERBIDECODER_H_

#include<systemc.h>


SC_MODULE(Viterbi_Decoder) {

	void decode();

	SC_CTOR(Viterbi_Decoder) {
		SC_THREAD(decode);
		sensitive << clk;
	}

};
