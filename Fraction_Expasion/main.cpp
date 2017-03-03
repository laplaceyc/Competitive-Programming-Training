#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>

//#define debug
using std::abs;
using std::fill;
using std::vector;

int remainder_buf[1000005];
int remainder_cnt;
bool infinite_flag;
bool found;

//Judge the sign of fraction
void SignJudge(int *a, int *b) {
	long long c = (long long)(*a)*(*b);
	if(c < 0) printf("-");
	*a = abs(*a); *b = abs(*b);
	return;
}

//Judge the quotient of each iteration whether appears or not
bool QuotientJudge(int a) {
	if (remainder_buf[a] != 0) {
		remainder_cnt = remainder_buf[a];
		infinite_flag = 1;
		return true;
	}
	else {
		remainder_buf[a] = ++remainder_cnt;
		return false;
	}
}

int main() {
	int a, b;
	while ((scanf("%d/%d = ?", &a, &b)) != EOF) {
#ifdef debug
		printf("[Initial insert]a = %d, b = %d\n", a, b);
#endif
		SignJudge(&a, &b);
#ifdef debug
		printf("[After Sing Judge]a = %d, b = %d\n", a, b);
#endif
		vector<int> quotient_vec;
		vector<int> delete_vec;
		//Fraction Expansion
		if (a%b == 0) {
			//integer phase
			printf("%d", a / b);
		}
		else {
			//integer phase
			printf("%d.", a / b);
			a = a % b;
			found = QuotientJudge(a);
			delete_vec.push_back(a);
			//decimal phase
			while (1) {
				a = a * 10;
				quotient_vec.push_back(a / b);
				a = a % b;
				if (a%b == 0) {
					break;
				}
				found = QuotientJudge(a);
				delete_vec.push_back(a);
				if (found == true) break;
			}
		}
#ifdef debug
		printf("\nremainder_cnt = %d\n", remainder_cnt);
#endif
		//print phase
		for (vector<int>::size_type i = 0; i != quotient_vec.size(); ++i) {
			if ((i + 1) == remainder_cnt && infinite_flag == 1) {
				printf("(");
			}
			printf("%d", quotient_vec[i]);
		}
		if (infinite_flag == 1) printf(")");
		printf("\n");
		//re-initialize parameter
		//clear array
		for (vector<int>::size_type i = 0; i != delete_vec.size(); ++i) {
			remainder_buf[delete_vec[i]] = 0;
		}	
		remainder_cnt = 0;
 		infinite_flag = 0;
		found = false;
	}
	system("PAUSE");
	return 0;
}
