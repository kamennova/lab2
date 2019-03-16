#include <iostream>
#include <iomanip>
#include <fstream>
#include <clocale>
#include <string>
#include <vector>

#include "Data_process.h"

using namespace std;

const string PATH_TO_FILE = "students.csv";
const float SCHOLARS_LIMIT_PERCENT = 0.4;

ifstream inFile(PATH_TO_FILE, ios::in);

int main() {
	unsigned int quantity;
	int budget_students_num = 0,
	 scholars_num = 0;

	setlocale(LC_CTYPE, "");

	if ( !inFile ) {
		std::cout << "File not found" << endl;

		return 0;
	} 

	quantity = get_students_quantity(inFile); // getting students number

	unsigned int subj_num = get_max_subj_num(inFile, quantity); // getting number of subjects
	cout << "Number of exams to pass: " << subj_num << endl;

	vector <Student> students_list = write_students_list(inFile, quantity, subj_num, budget_students_num); // writing students list

	vector <Scholar> scholars_list = write_scholars_list(students_list, subj_num); // list of non-contract & non-dopka students
	sort_scholars_list(scholars_list);

	// Testing scholars list
	int scholars_limit = budget_students_num * SCHOLARS_LIMIT_PERCENT;
	int scholars_quantity;
	if (scholars_list.size() < scholars_limit) {
		scholars_quantity = scholars_list.size();
	}
	else {
		scholars_quantity = scholars_limit;
	}

	cout << "Scholars quantity: " << scholars_limit << endl;
	limit_scholars_list(scholars_list, scholars_quantity);
	scholars_list_output(scholars_list);

	scholars_list_to_file(scholars_list);
	
	system("pause");

	return 1;
}