/* Lab 6 Wrapper Program */

#include <stdio.h>
#include <math.h>


/* Function Prototypes */

double mag(double ax, double ay, double az);
int close_to(double tolerance, double point, double value);


int main (void){
	double ax,ay,az;
	int x;
	int t=0;
	int s=0;
	double z = 1.0;
	int initialtime;
	int endtime;
	int percent;
	double totaltime;
	double distancefell;
	double beginningX = 0.0, currentX = 0;
	double pastY = 0.0, currentY = 0;
	double pastX = 0.0;
	
	
	printf("Ok, I'm now receiving data.\n");
	printf("I'm Waiting");
	
	while(close_to(0.5,1.0,z)){
		scanf("%d,%lf,%lf,%lf", &t, &ax, &ay, &az); 
		z = mag(ax, ay, az);{
			t++;
			fflush(stdout);
			if((t % 200)==0){
				printf(".");
			}
		}
	}
	
	initialtime = x;
	printf("\n\tHelp me! I'm falling");
	pastX = x;
	while(close_to(0.5,0.0,z)){
		scanf("%d,%lf,%lf,%lf", &t, &ax, &ay, &az); 
		z = mag(ax, ay, az);
			s++;
			fflush(stdout);
			if((s%20)==0){
				printf("!");
			}
		if(mag(ax,ay,az)>1){
			break;
		}
		endtime = t;
		currentY = pastY + ((9.8-mag(ax,ay,az)*9.8)* ((endtime-pastX)/1000.0));
		pastX = x;
		pastY = currentY;
		beginningX = currentX;
	}
	
	totaltime = ((endtime-initialtime)/1000.0);
	distancefell = ((1.0/2.0)*9.8*(totaltime*totaltime));
	printf("\n\t\tOuch! I fell %lf meters in %lf seconds\n", distancefell, totaltime);
	
	printf("Compensating for air resistance, the fall was %lf meters\n", currentX);
	percent = (distancefell-currentX)*100/(currentX);
	printf("This is %d%% less than computed before", percent);
	
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