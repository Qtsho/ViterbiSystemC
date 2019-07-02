#include <systemc.h>
#include "encoder.h"
void Convolution_Encoder::Convolution(void)
 {
 		sc_bit output1, output2;
		op1.write(output1);
		op2.write(output2);

		output1 = reg[0]^reg[1]^reg[2]^reg[3];
		output2 = reg[0]^reg[1]^reg[3];
 }

 void Convolution_Encoder::ShiftRegister(void)
 {
 		reg[3] = reg[2];
		reg[2] = reg[1];
		reg[1] = reg[0];
		reg[0] = in;
 }

void Convolution_Encoder::encode(void) {
	
	sc_bit s0, s1, s2, s3;
	while (true) {
		wait();
	
		s0 = reg[0];
		s1 = reg[1];
		s2 = reg[2];
		s3 = reg[3];

		wait(2, SC_NS);
	}
}