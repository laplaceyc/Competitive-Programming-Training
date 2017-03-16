#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct node{
	string name;
	int edge;
	int pos_num;
};

vector<node> vt_buffer;

bool cmp(const node &a, const node &b) {
	if (a.pos_num != b.pos_num) return a.pos_num < b.pos_num;
	else if (a.edge != b.edge){
		if(a.pos_num == 4) return a.edge < b.edge;
		else return a.edge > b.edge;
	}
	else return  a.name < b.name;
}


int main()
{	
	int cat_data;
	//input data
	while (cin >> cat_data) {
		int food_num;
		cin >> food_num;
		if(food_num > cat_data) food_num = cat_data;
		while(cat_data--){
			node tmp;
			string name_tmp, position;
			int edge_tmp;
			cin >> name_tmp >> position >> edge_tmp;
			int pos_num_tmp;
			if (position == "elder") pos_num_tmp = 0;  
			else if (position == "nursy") pos_num_tmp = 1;
			else if (position == "kit") pos_num_tmp = 2;
			else if (position == "warrior") pos_num_tmp = 3;
			else if (position == "appentice") pos_num_tmp = 4;
			else if (position == "medicent") pos_num_tmp = 5;
			else if (position == "deputy") pos_num_tmp = 6;
			else if (position == "leader") pos_num_tmp = 7;
			tmp.name = name_tmp;
			tmp.edge = edge_tmp;
			tmp.pos_num = pos_num_tmp;
			vt_buffer.push_back(tmp);
		}
		sort(vt_buffer.begin(), vt_buffer.end(), cmp);

		//output data
		for (auto i = 0; i < food_num; ++i) {
			cout << vt_buffer[i].name << '\n';
		}
		vt_buffer.clear();
	}
	
	
	return 0;
}
