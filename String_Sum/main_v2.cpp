#include<iostream>
#include<string>
#include <cstdlib>
using namespace std;

int main(){
	
    string s;
    while(getline(cin, s)) {
        if(s == "") {
            cout << '0' << endl;
        }
        else {
            string buf;
            int ans = 0;
            for(char &c : s) {
                if(c >= '0' && c <='9') {
                    buf.push_back(c);
                }
                else if(c == ' ') {
                    ans = ans + atoi(buf.c_str());
                    buf.clear();
                }
            }
            if(!buf.empty()) {
                ans = ans +  atoi(buf.c_str());
            }
            cout << ans << endl;
        }
    }
    return 0;
}