// CprE 185: Lab 3 
// Problem 2

#include <stdio.h>

int main(){
	
	int integerResult;
	double decimalResult;
	double areaResult;
	double metersResult;
	double centigradeResult;
	
	integerResult = 6427 + 1725;
	printf("The value of 6427+1725 is %d\n", integerResult);
	
	integerResult = (6971 * 3925) - 25;
	printf("The value of (6971*3925)-25 is %d\n", integerResult);
	
	decimalResult = 79.0 + 12.0/5.0;
	printf("The value of 79.0 + 12.0/5.0 is %.2lf\n", decimalResult);
	
	decimalResult = 3640.0/107.9;
	printf("The value of 3640.0/107.9 is %.2lf\n", decimalResult);
	
	integerResult = (22/3)*3;
	printf("The value of (22/3)*3 is %d\n", integerResult);
	
	integerResult = 22/(3*3);
	printf("The value of 22/(3*3) is %d\n", integerResult);
	
	decimalResult = 22.0/(3.0*3.0);
	printf("The value of 22.0/(3.0*3.0) is %.2lf\n", decimalResult);
	
	decimalResult = 22.0/3.0 * 3.0;
	printf("The value of 22.0/3.0 * 3.0 is %.2lf\n", decimalResult);
	
	decimalResult = (22.0/3.0) * 3.0;
	printf("The value of (22.0/3.0) * 3.0 is %.2lf\n", decimalResult);
	
	integerResult = 22/(3*3);
	printf("The value of 22/(3*3) is %d\n", integerResult);
	
	decimalResult = 22.0/3.0 * 3.0;
	printf("The value of 22.0/3.0 * 3.0 is %.2lf\n", decimalResult);
	
	areaResult = 3.14 * 23.567;
	printf("The area of a circle with a circumference of 23.567 is %.2lf\n", areaResult);
	
	metersResult = 14.0 * 0.3048;
	printf("14 feet is %.2lf meters\n", metersResult);
	
	centigradeResult = (76.0-32.0)/1.8;
	printf("76 degrees Fahrenheit is %.2lf degrees Centigrade\n", centigradeResult);
	
	return 0;
}