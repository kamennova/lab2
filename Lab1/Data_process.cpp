#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>

#include "Data_process.h"

using namespace std;

int get_data_cell(string line, int pos, string &data_cell) {
	int a = pos;

	for (; line[a] != ',' && line[a] != '\0'; a++) {
		data_cell += line[a];
	}

	return ++a;
}

unsigned int get_students_quantity(ifstream &inFile) {
	unsigned int quantity;
	string line;

	if (getline(inFile, line)) {
		quantity = stoi(line);
	}

	return quantity;
}

void write_student_list(ifstream &inFile, unsigned const int quantity, vector <Student> &students) {
	string line;

	for (int i = 0; i < quantity; i++) {
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
}