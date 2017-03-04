#include <cstdio>
#include <sstream>
#include <string>
#include <iostream>
#include <locale>
//#define debug
using namespace std;
int main() {
	string s;
	while (getline(cin, s)) {
		int sum = 0;
		stringstream ss(s);
		string tmp_buf;
		while (ss >> tmp_buf) {
			if (isdigit(tmp_buf[0])) {
				sum += stoi(tmp_buf);
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}
