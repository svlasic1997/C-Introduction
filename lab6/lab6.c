/* Lab 6 Wrapper Program */

#include <stdio.h>
#include <math.h>


/* Function Prototypes */

double mag(double ax, double ay, double az);
int close_to(double tolerance, double point, double value);


int main(void){
	double ax,ay,az;
	int x;
	int t=0, s=0;
	double z = 1.0;
	int initialtime;
	int endtime;
	double totaltime;
	double distancefell;
	
	printf("Ok, I'm now receiving data.\n");
	printf("I'm Waiting");
	
	while(close_to(0.5,1.0,z)){
		scanf("%d,%lf,%lf,%lf", &t, &ax, &ay, &az); z = mag(ax, ay, az);{
			t++;
			fflush(stdout);
			if((t % 200)==0){
				printf(".");
			}
		}
	}
	
	initialtime = x;
	printf("\n\tHelp me! I'm falling");
	while(close_to(0.5,0.0,z)){
		scanf("%d,%lf,%lf,%lf", &t, &ax, &ay, &az); z = mag(ax, ay, az);{
			s++;
			fflush(stdout);
			if((s%20)==0){
				printf("!");
			}
		endtime = t;
		}
	}
	
	totaltime = (endtime-initialtime)/1000.0;
	distancefell = ((1.0/2.0)*9.8*(totaltime*totaltime));
	printf("\n\t\tOuch! I fell %lf meters in %lf seconds\n", distancefell, totaltime);
	
	return 0;
	
	
}

double mag(double ax, double ay, double az){
	return sqrt(ax*ax+ay*ay+az*az);
}


int close_to(double tolerance, double point, double value){
	if(value>=(point-tolerance) && value <= (point+tolerance)){
		return 1;
	}
	else{
		return 0;
	}
}