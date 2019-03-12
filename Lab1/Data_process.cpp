#include <iostream>
#include <cstring>
#include "Data_process.h"

using namespace std;

int get_data_cell(string line, int pos, string &data_cell) {
	int a = pos;

	for (; line[a] != ',' && line[a] != '\0'; a++) {
		data_cell += line[a];
	}

	return ++a;
}