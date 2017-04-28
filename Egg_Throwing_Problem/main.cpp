#include "SunMoon.h"
int ans;
int recurrsion_count = 0;
void throw_egg_recurrsion(int lower, int upper){
	if (recurrsion_count == 31) return;
//	if (lower == upper) return;
	int median = lower + (upper - lower) / 2;
	if (throw_egg(median)){
		//egg is not broken
		ans = median;
		recurrsion_count++;
		throw_egg_recurrsion(median + 1, upper);
	
	}
	else{
		//egg is broken
		recurrsion_count++;
		throw_egg_recurrsion(lower, median);
	}
	return;
}

int main(){
	
	initialize();
	
	throw_egg_recurrsion(1, 2147483647);
	
	answer(ans);
	
	return 0;
}