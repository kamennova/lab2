#include <iostream>
#include <fstream>
#include <clocale>
#include <string>
#include <vector>

#include "Data_process.h"
#include "Sort_output.h"

using namespace std;

const string PATH_TO_FILE = "C:\\students.csv";

ifstream inFile(PATH_TO_FILE, ios::in);

int main() {
	unsigned int quantity;

	setlocale(LC_ALL, "Ukrainian");

	if ( !inFile ) {
		std::cout << "File not found" << endl;

		return 0;
	} 

	// getting students number
	quantity = get_students_quantity(inFile);

	// writing students list
	vector <Student> students;
	write_student_list(inFile, quantity, students);

	system("pause");

	return 1;
}