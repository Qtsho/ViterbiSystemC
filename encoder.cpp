#include <systemc.h>
#include "encoder.h"

void Viterbi_Encoder::encode(void) {
	sc_bit out1, out2;
	sc_bit s0, s1, s2, s3;
	while (true) {
		wait();
		r[3] = r[2];
		r[2] = r[1];
		r[1] = r[0];
		r[0] = in;

		out1 = r[0]^r[1]^r[2]^r[3];
		out2 = r[0]^r[1]^r[3];


		op1.write(out1);
		op2.write(out2);

		s0 = r[0];
		s1 = r[1];
		s2 = r[2];
		s3 = r[3];

		cout << "In: " << in << " - Out:" << out1 << out2;
		cout << " - State: " << s0 << s1 << s2 << s3 << endl;

		wait(2, SC_NS);
	}
}