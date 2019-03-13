#include <iostream>
#include <iomanip>
#include <fstream>
#include <clocale>
#include <string>
#include <vector>

#include "Data_process.h"

using namespace std;

const string PATH_TO_FILE = "C:\\students.csv";
const float SCHOLARS_LIMIT = 0.4;

ifstream inFile(PATH_TO_FILE, ios::in);

int main() {
	unsigned int quantity;

	setlocale(LC_CTYPE, "");

	if ( !inFile ) {
		std::cout << "File not found" << endl;

		return 0;
	} 

	quantity = get_students_quantity(inFile); // getting students number

	// writing students list
	vector <Student> students_list;
	write_students_list(inFile, quantity, students_list);

	vector <Scholar> scholars_list;
	write_scholars_list(students_list, scholars_list);
	sort_scholars_list(scholars_list);

	// Testing scholars list
	cout << "Scholars quantity: " << get_scholars_num(scholars_list, SCHOLARS_LIMIT) << endl;
	limit_scholars_list(scholars_list, SCHOLARS_LIMIT);
	scholars_list_output(scholars_list);

	scholars_list_to_file(scholars_list);
	
	system("pause");

	return 1;
}