#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int N = 55500;//sqrt(2*10e9) = 44721
bool sieve[N];
vector<int> prime_list;
//linear time construct prime list
void linear_sieve()
{
	for (int i = 2; i<N; i++)
	{
		if (!sieve[i]) prime_list.push_back(i);
		for (int j = 0; i*prime_list[j]<N; j++)
		{
			sieve[i*prime_list[j]] = true;
			if (i % prime_list[j] == 0) break;
		}
	}
	return;
}

int main(){
	//create prime list
	linear_sieve();
	int a;
	while (scanf("%d\n", &a) != EOF) {
		//a is 2
		if(a == 2) printf("1\n");	
		//a is even
		else if(a%2 == 0) printf("2\n");	
		// a is odd
		else{
			if(a < 55500){
				for(vector<int>::iterator i = prime_list.end() - 1; i != prime_list.begin(); --i){
					if(a == (*i)){
						printf("1\n");	
						break;
					}
					else if(a > (*i)){
						if((a - (*i)) == 2) {
							printf("2\n");	
							break;
						}
						else{
							printf("3\n");	
							break;
						}
					}
				}	
			}
			//a is odd && a > 55500
			else{
				bool first_signal = false, second_signal = false;
				for(size_t i = 0; i < prime_list.size() && prime_list[i] * prime_list[i] <= a; ++i){
					if(a%prime_list[i] == 0){
						first_signal = true;
					}
					if((a-2)%prime_list[i] == 0){
						second_signal = true;
					}
				}
				//a and (a-2) are both not primes
				if(first_signal == true && second_signal == true) printf("3\n");
				//(a-2) is a prime
				else if(first_signal == true) printf("2\n");	
				// a is a prime
				else printf("1\n");				
			}		
		}
	}
		
	return 0;
}