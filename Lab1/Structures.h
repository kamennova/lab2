#include <string>

using namespace std;

struct Student {
	string surname;

	int * subj_marks;
	float average;
	unsigned int subj_num;
	bool is_contract;

	Student(const unsigned int SUBJ_NUM = 5) {
		subj_num = SUBJ_NUM;
		subj_marks = new int[subj_num];
	}
};

struct Scholar {
	string surname;

	float average_mark;
};