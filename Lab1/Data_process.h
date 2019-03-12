#include <fstream>
#include <string>
#include <vector>

#include "Structures.h"

using namespace std;

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