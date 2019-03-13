/*#include <iostream>

#include "Sort_output.h"

using namespace std;

void sort_scholar_list(vector <Scholar> & list) {
	float prev = list[0].average_mark;

	for (int i = 1, count = list.size(); i < count; i++) {
		for (int a = 0; a < i; a++) {
			prev = list[a].average_mark;

			if (list[i].average_mark > prev) {
				Scholar temp = list[i];
				list.erase(list.begin() + i);
				list.insert(list.begin() + a, temp);

				break;
			}
		}
	}
}

/*
3 7 8 2 4

1) ...
2) 7 > 3, swap , 7 3 8 2 4
3) 8 > 7, insert 8 before 7... 8 7 3 2 4
4) 
*/
