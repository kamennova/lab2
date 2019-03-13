#include <fstream>
#include <string>
#include <vector>

//#include "Structures.h"

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

struct Scholar {
	string surname;

	float average_mark;
};

string get_data_cell(string line, int &pos);

// --- student funcs ---

unsigned int get_students_quantity(ifstream &);
void write_students_list(ifstream &, unsigned const int, vector <Student> &);

void add_to_students_list(string &, vector <Student> &);
void get_subj_marks(string &, int&, Student &);
void get_student_surname(string &, int &, Student &);
void get_study_status(string &, int &, Student &);

 // --- scholar funcs ---

void write_scholars_list(vector <Student> &, vector <Scholar> &);
bool is_contract(Student &);
float get_average_mark(Student &);

// --- scholar sort ---

void sort_scholars_list(vector <Scholar> &);
void scholars_list_output(vector <Scholar> &);
void limit_scholars_list(vector <Scholar> &list, float limit);
int get_scholars_num(vector <Scholar> &list, float limit);

void scholars_list_to_file(vector <Scholar> &list);