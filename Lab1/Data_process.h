#include <fstream>
#include <string>
#include <vector>

//#include "Structures.h"

using namespace std;

struct Student {
	string surname;

	int * subj_marks;
	float average;
	int sum;
	unsigned int subj_num;
	bool is_contract;
	bool has_passed;

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
vector <Student> write_students_list(ifstream &, unsigned const int, unsigned int, int &);

void add_to_students_list(string &, vector <Student> &, unsigned int);
void get_subj_marks(string &, int&, Student &, unsigned int );
void get_student_surname(string &, int &, Student &);
void get_study_status(string &, int &, Student &);

int get_student_subj_num(string line, int pos);
unsigned int get_max_subj_num(ifstream &inFile, unsigned const int quantity);

 // --- scholar funcs ---

vector <Scholar> write_scholars_list(vector <Student> &, unsigned int);
bool is_contract(Student &);
float get_average_mark(Student &);

// --- scholar sort ---

void sort_scholars_list(vector <Scholar> &);
void scholars_list_output(vector <Scholar> &);
void limit_scholars_list(vector <Scholar> &list,int limit);
int get_scholars_num(vector <Scholar> &list, float limit);

void scholars_list_to_file( vector <Scholar> &list);