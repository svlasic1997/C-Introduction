/* Lab 6 */
#include <stdio.h>
#include <math.h>


/* Put your function prototypes here */
double mag (double x, double y, double z);
int close_to(double tolerance, double point, double value);

int main(void) {
	int s;
	double  ax, ay, az; 	
	int d = 0, e = 0;
	double y = 1.0;
	int begintime;
	int endtime;
	double totaltime;
	double distancefell;
	


	printf("Ok, I'm now receiving data\n");
	printf("I'm Waiting");
	while(close_to(0.5,1.0, y)){
		scanf("%d,%lf,%lf,%lf", &s, &ax, &ay, &az); y = mag(ax, ay, az);{
			d++;
			fflush(stdout);	
			if((d % 200) == 0)
				printf(".");
		}
	}
	begintime = s;
	printf("\n\tHelp me! I'm falling");
	while(close_to(0.5,0.0, y)){
		scanf("%d,%lf,%lf,%lf", &s, &ax, &ay, &az); y = mag(ax, ay, az);{
			e++;
			fflush(stdout);
			if((e % 20) == 0)
				printf("!");
	endtime = s;		
		}
	}

		totaltime = ((endtime - begintime)/1000.0);
		distancefell = ((1.0/2.0)*9.8*(totaltime*totaltime));
		printf("\n\t\tOuch! I fell %lf meters in %lf seconds\n", distancefell, totaltime);
		
return 0;
}
/* Put your functions here */
double mag(double x, double y, double z) 
{
	return sqrt(x*x + y*y + z*z);
}
int close_to(double tolerance, double point, double value)
{
	if(value >= (point - tolerance) && value <= (point + tolerance))
	 return 1;
	else
	 return 0;
}