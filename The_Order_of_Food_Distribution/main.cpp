// ConsoleApplication4.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <cstdio>
#include <tuple>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
using namespace std;
using custom_vector = vector<tuple<string, string, int> >;
using custom_tuple = tuple<string, string, int>;
//enum position_order { elder = 0, nursy, kit, warrior, appentice, medicent, deputy, leader};

bool cmp(const custom_tuple &a, const custom_tuple &b) {
	if (get<1>(a) == "appentice")
}


int main()
{	
	
	custom_vector vt_buffer;
	int cat_data, food_num;
	scanf_s("%d %d", &cat_data, &food_num);
	//input data
	while (cat_data--) {
		string name, position;
		int edge;
		cin >> name >> position >> edge;
		

		custom_tuple tmp = make_tuple(name, position, edge);
		vt_buffer.push_back(tmp);
	}



	//output data
	for (auto i = 0; i != food_num; ++i) {
		cout << get<0>(vt_buffer[i]) << '\n';
	}
	system("PAUSE");
	return 0;
}
