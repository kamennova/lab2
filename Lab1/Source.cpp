#include <iostream>
#include <ctime>
#include <fstream>
#include <clocale>
#include <string>
#include <vector>

#include "Data_process.h"
#include "Sort_output.h"

using namespace std;

ifstream inFile("C:\\students.csv", ios::in);

int main() {
	unsigned int quantity;
	string name;
	string line;
	unsigned int subj1,
		 subj2,
		subj3,
		subj4,
		subj5;
	bool isContract;

	setlocale(LC_ALL, "Ukrainian");

	if ( !inFile ) {
		std::cout << "File not found" << endl;

		return 0;
	} 

	// getting students number
	if (getline(inFile, line)) {
		quantity = stoi(line);
	}

	// reading students data
	vector <Student> students;

	for (int i = 0; i < quantity; i++){
		getline(inFile, line);
		struct Student temp;
		string data_cell;

		// getting name
		int pos = get_data_cell(line, 0, data_cell);
		temp.surname = data_cell;
		data_cell = "";

		// getting subject marks
		for (int s = 0; s < temp.subj_num; s++) {
			pos = get_data_cell(line, pos, data_cell);
			temp.subj_marks[s] = stoi(data_cell);
			data_cell = "";
		}

		// getting study status
		pos = get_data_cell(line, pos, data_cell);
		temp.is_contract = (data_cell == "TRUE" ? true : false);

		students.push_back(temp);
	}

	system("pause");

	return 1;
}