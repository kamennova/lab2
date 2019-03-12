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

string get_data_cell(string line, int &pos);

unsigned int get_students_quantity(ifstream &);
void write_students_list(ifstream &, unsigned const int, vector <Student> &);

void add_to_students_list(string &, vector <Student> &);
void get_subj_marks(string &, int&, Student &);
void get_student_surname(string &, int &, Student &);
void get_study_status(string &, int &, Student &);