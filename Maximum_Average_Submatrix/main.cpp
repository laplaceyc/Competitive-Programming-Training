#include <cstdio>
int max_entry;
int main(){
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	int count = n*m;
	while(count--){
		int entry;
		scanf("%d", &entry);
		if(max_entry < entry) max_entry = entry;
	}
	printf("%d.", max_entry);
	for(int i = 0; i != k; ++i) printf("0");
	printf("\n");
}