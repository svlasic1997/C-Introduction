// CprE 185: Lab 3
// Problem 1: Mysterious Output

#include <stdio.h>

int main(){
	int integerResult;
	double decimalResult;
	
	// The printf was returning a %lf which is only applicable for doubles while this wants an int to return 
	integerResult = 77 / 5;
	printf("The value of 77/5 is %d\n", integerResult);
	
	// This is correct since %d applies to int
	integerResult = 2 + 3;
	printf("The vlaue of 2+3 is %d\n", integerResult);
	
	// The printf was returning a %d which is only applicable for int while this wants a double to return 
	decimalResult = 1.0 / 22.0;
	printf("The value of 1.0/22.0 is %lf\n", decimalResult);
	
	return 0;
}