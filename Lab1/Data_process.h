#include <iostream>
#include <ctime>
#include <fstream>
#include <clocale>
#include <string>
#include <vector>

using namespace std;

struct Student {
	string surname;

	int * subj_marks;
	unsigned int subj_num;
	bool is_contract;

	Student(const unsigned int SUBJ_NUM = 5) {
		subj_num = SUBJ_NUM;
		subj_marks = new int[subj_num];
	}
};

int get_data_cell(string line, int pos, string &data_cell);