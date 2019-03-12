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

	setlocale(LC_CTYPE, "");

	if ( !inFile ) {
		std::cout << "File not found" << endl;

		return 0;
	} 

	// getting students number
	quantity = get_students_quantity(inFile);

	// writing students list
	vector <Student> students_list;
	write_students_list(inFile, quantity, students_list);

	system("pause");

	return 1;
}