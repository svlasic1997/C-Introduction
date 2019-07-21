/* Lab 5 Wrapper Program */

#include <stdio.h>
#include <math.h>

#define TRUE 1

/* Put your lab 4 functions prototypes here, as well as the prototype for lab 5 */

double mag(double ax, double ay, double az);
double close_to(double tolerance, double point, double value);

int main(void) {
	int t, b1, b2, b3, b4, b5, s;
	double ax, ay, az;
	int steady;

	while (!b2) {
		scanf("%d, %lf, %lf, %lf, %d, %d, %d, %d, %d, %d", &t, &ax, &ay, &az, &b1, &b2, &b3, &b4, &b5, &s );
		
		if(close_to(0.10, 1.00, mag(ax, ay, az))){
			
			if(close_to(0.20, 1.00, ay)){
				if(steady != 1){
					steady = 1;
					printf("TOP\n");
				}
			}
			
			else if(close_to(0.20, -1.00, ay)){
				if(steady != 2){
					steady = 2;
					printf("BOTTOM\n");
				}
			}
			
			else if(close_to(0.20,1.00,az)){
				if(steady != 3){
					steady = 3;
					printf("FRONT\n");
				}
			}
			
			else if(close_to(0.20,-1.00,az)){
				if(steady != 4){
					steady = 4;
					printf("BACK\n");
				}
			}
			
			else if(close_to(0.20,1.00,ax)){
				if(steady != 5){
					steady = 5;
					printf("RIGHT\n");
				}
			}
			
			else if(close_to(0.20,-1.00,ax)){
				if(steady != 6){
					steady = 6;
					printf("LEFT\n");
				}
			}
		}
	}
	return 0;
}
		
		
/*	CODE SECTION 2 */
		//printf("Echoing output: %d, %lf, %lf, %lf, %d, %d, %d, %d, %d, %d\n", t, ax, ay, az, b1, b2, b3, b4, b5, s);


/* 	CODE SECTION 1 */
		//printf("At %d ms, the acceleration's magnitude was: %lf\n", t, mag(ax, ay, az));  
		
		/* You would be wise (mainly save time) if you copy your code to calculate the magnitude from last week
		 (lab 4) to this section.  You will also need to copy your prototypes and functions to the appropriate sections
		 in this program. */  
	
 


/* Put your lab 4 functions here, as well as your new function close_to */

double mag(double ax, double ay, double az){
	return sqrt(ax*ax + ay*ay + az*az);
}

double close_to(double tolerance, double point, double value){
	if(value >= (point-tolerance) && value <= (point+tolerance)){
		return 1;
	}
	else{
		return 0;
	}
}
