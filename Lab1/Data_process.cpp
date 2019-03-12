#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>

#include "Data_process.h"

using namespace std;

string get_data_cell(string line, int &pos) {
	string data_cell;

	for (; line[pos] != ',' && line[pos] != '\0'; pos++) {
		data_cell += line[pos];
	}

	pos++;
	return data_cell;
}

unsigned int get_students_quantity(ifstream &inFile) {
	unsigned int quantity;
	string line;

	if (getline(inFile, line)) {
		quantity = stoi(line);
	}

	return quantity;
}

void write_students_list(ifstream &inFile, unsigned const int quantity, vector <Student> &students_list) {
	string line;

	for (int i = 0; i < quantity; i++) {
		getline(inFile, line);
		add_to_students_list(line, students_list);
	}
}

void add_to_students_list(string &line, vector <Student> &students_list) {
	struct Student temp;
	int pos = 0;

	get_student_surname(line, pos, temp);
	get_subj_marks(line, pos, temp);
	get_study_status(line, pos, temp);

	students_list.push_back(temp);
}

void get_student_surname(string &line, int &pos, Student &temp) {
	temp.surname = get_data_cell(line, pos);
}

void get_subj_marks(string &line, int &pos, Student &temp) {
	string mark_str;

	for (int s = 0; s < temp.subj_num; s++) {
		mark_str = get_data_cell(line, pos);
		temp.subj_marks[s] = stoi(mark_str);
	}
}

void get_study_status(string &line, int &pos, Student &temp) {
	string is_contract_str;

	is_contract_str = get_data_cell(line, pos);
	temp.is_contract = (is_contract_str == "TRUE" ? true : false);
}