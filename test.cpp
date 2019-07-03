#include "viterbi_decoder.h"
#include "systemc.h"
#include <iostream>
#include <sstream>
#include <list>
#include "LinkedListT.h"
#include "utils.h"

using namespace std;


void Viterbi_Decoder::decode(void) {

	sc_bit o1, o2, o3, o4, o5, o6, o7;
	sc_bit in1, in2;
	sc_bv<2> r;

	r[0] = in1;
	r[1] = in2;

	ob1.write(o1);
	ob2.write(o2);
	ob3.write(o3);
	ob4.write(o4);
	ob5.write(o5);
	ob6.write(o6);
	ob7.write(o7);

	int input_list[2] = { 0, 1 };
	int input_state[8][3] = { {0, 0, 0}, {0, 0, 1},
							  {0, 1, 0}, {0, 1, 1},
							  {1, 0 ,0}, {1, 0, 1},
							  {1, 1, 0}, {1, 1, 1} };

	int const w = 9;
	int const h = 16;

	int table[h][w] = { 0 };

	// ==============================================================================

	//Creating input bits
	for (int i = 0; i < h - 1; i+=2) {
		table[i][0] = input_list[0];
		table[i+1][0] = input_list[1];
	}

	//Adding input states
	int i = 0;
	int j = 0;
	
	while (i < 15 and j < 8) {
		table[i][1] = input_state[j][0];
		table[i][2] = input_state[j][1];
		table[i][3] = input_state[j][2];

		table[i + 1][1] = input_state[j][0];
		table[i + 1][2] = input_state[j][1];
		table[i + 1][3] = input_state[j][2];
		i += 2;
		j += 1;
	}

	//Adding output states
	i = 0;
	while (i < 16) {
		table[i][4] = table[i][0] ^ table[i][1] ^ table[i][2] ^ table[i][3];
		table[i][5] = table[i][0] ^ table[i][1] ^ table[i][3];
		i += 1;
	}

	//Adding next states
	i = 0;
	while(i < 16){
		table[i][6] = table[i][0];
		table[i][7] = table[i][1];
		table[i][8] = table[i][2];
		i += 1;
	}

	/*for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cout << table[i][j] << " ";
		}
		cout << endl;
	}*/


	int decoseq_list = 0;
	int decoseq[] = {1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1 };
	int dsl = size(decoseq)/2;

	cout << "DSL: " << dsl << endl;

	int pathlist = 0;

	int pw = len(pathlist);
	int pl = len(pathlist);

	int ns_list = 0;

	for (int dp = 0; dp < dsl; dp++) {

		//FIND NEXT STATES OF THE LAST STATES IN CURRENT TRACE
		for (int j = 0; j < len(pathlist); j++) {
			int ns = nextState(pathlist[j][-1]);
			extend(ns_list);
		}

		//DOUBLE THE TRACES BEFORE
		int temp_path = 0;
		int count = 0;
		for (int m = 0; m < len(pathlist); m++) {
			for (int n = 0; n < 2; n++) {
				append(pathlist, temp_path);
			}
		}

		//ADD THE NEXT STATES TO THE PREVIOUS TRACES THAT HAVE BEEN DOUBLED
		for (int k = 0; k < len(ns_list); k++){
			append(temp_path, ns_list);
		}		

		pathlist = temp_path;

		//FIND THE OUTPUT BITS WHEN SWITCHING BETWEEN STATES
		int output_bits = 0;
		int table = 0;
		int ob_list = 0;

		for (int k = 0; k < len(pathlist); k++) {
			clear(output_bits);
			for (int i = 0; i < len(pathlist) - 1; i++){
				for (int j = 0; j < len(table); j++) {
					if (matchedState(pathlist, table)) {
						append(table, output_bits);
						append(output_bits, ob_list);
					}
				}
			}
		}


		//FIND HAMMING METRIC FOR EACH OUTPUT STATES
		int temp_metric = 0;
		int score_list = 0;

		for (int i = 0; i < len(ob_list); i++) {

			clear(score_list);
			for (int j = 0; j < len(ob_list); j++) {
				append(score_list, decoseq_list);
				append(temp_metric, score_list);
			}
		}

		//ROTATE HAMMING MATRIX
		int metric = 0;
		int t_metric = 0;
		for (int i = 0; i < len(ob_list); i++) {
			clear(t_metric);
			for (int j = 0; j < len(ob_list); j++) {
				append(temp_metric, t_metric);
				append(metric, temp_metric);
			}
		}

		//CALCULATE THE SUM OF EACH PATH
		int sum_list = 0;
		
		for (int i = 0; i < len(metric); i++) {
			int sum = 0;
			for (int j = 0; j < len(metric); j++) {
				sum += metric;
				append(sum_list, sum);
			}
		}

		int remove_list = 0;

		for (int m = 0; m < len(pathlist); m++) {
			int current_state = pathlist;
			int matched_list;

			for (int n; n < len(pathlist); n++) {
				if (pathlist == current_state) {
					append(matched_list, n);
				}
			}

			int sum_checklist = 0;
			for (int k = 0; k < len(matched_list); k++) {
				append(sum_list, matched_list);
			}

			int max_sum = sum_checklist;
			int temp_remove_list = 0;

			for (int p = 0; p < len(sum_checklist); p++) {
				if (sum_checklist < max_sum) {
					append(sum_checklist, temp_remove_list);
				}
			}

			extend(temp_remove_list);

			int updated_remove_list = 0;

			for (int item = 0; item < len(updated_remove_list); item++) {
				if (item == updated_remove_list) {
					append(updated_remove_list, item);
				}
			}

			int urll = len(updated_remove_list);

			for (int i = 0; i < urll; i++) {
				pop(pathlist, urll);
			}
		}
	}

}