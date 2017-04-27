#include <cstdio> 
using namespace std;

long long count;
int case_cnt = 1;

void merge(int *array, int front, int median, int end){
	int *temp = new int[end - front + 1](); 
	int i = front, j = median + 1;
	int cur = 0;
	while(i <= median && j <= end){
		if(array[i] < array[j]){
			temp[cur++] = array[i++];
		}
		else{
			temp[cur++] = array[j++];
			//key point
			count += (median - i + 1);
		}
	}
	while(i <= median){
		temp[cur++] = array[i++];
	}
	while(j <= end){
		temp[cur++] = array[j++];
	}


	for(int m = 0; m < cur;){
		array[front++] = temp[m++];
	
}
	delete [] temp;
	return;
}

void merge_sort(int *array, int front, int end){
	if(front >= end) return;
	int median = front + (end - front) / 2;
	merge_sort(array, front, median);
	merge_sort(array, median + 1, end);
	merge(array, front, median, end);
	return;
}

int main(){
	//parse input
	int sequence_length;
	while(scanf("%d", &sequence_length) && sequence_length != -1){
		count = 0;
		int *sequence = new int[sequence_length]();
		int pos = 0;
		int n = sequence_length;
		while(n--){
			scanf("%d", &sequence[pos++]);
		}
		//algorithm body
		merge_sort(sequence, 0, sequence_length - 1);
		printf("Case #%d: %d\n", case_cnt++, count);
	}
	
	return 0;
}

