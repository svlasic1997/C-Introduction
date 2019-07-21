/* Lab 6-2 */
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
	double beginningX = 0.0, currentX=0;
	double prevV = 0.0, currentV=0;
	double prevT = 0.0;
	int percentage;


	printf("Ok, I'm now receiving data\n");
	printf("I'm Waiting");
	while(close_to(0.5,1.0, y)){
		scanf("%d,%lf,%lf,%lf", &s, &ax, &ay, &az); 
		y = mag(ax, ay, az);
		{
			d++;
			fflush(stdout);	
			if((d % 200) == 0)
				printf(".");
		}
	}
	begintime = s;
	printf("\n\tHelp me! I'm falling");
	prevT=s;
	while(close_to(0.5,0.0, y)){
		scanf("%d,%lf,%lf,%lf", &s, &ax, &ay, &az); 
		y = mag(ax, ay, az);
			e++;
			
			fflush(stdout);
			if((e % 20) == 0)
				printf("!");
		if (mag(ax, ay, az) > 1)
		{
			break;
		}
				
		endtime = s;		
		currentV = prevV + ((9.8 - mag(ax, ay, az)*9.8) * ((endtime - prevT)/1000.0));
		currentX = beginningX + (currentV * ((endtime - prevT)/1000.0));
		prevT = s;
		prevV = currentV;
		beginningX = currentX;
		
	}

		totaltime = ((endtime - begintime)/1000.0);
		distancefell = ((1.0/2.0)*9.8*(totaltime*totaltime));
		printf("\n\t\tOuch! I fell %lf meters in %lf seconds\n", distancefell, totaltime);
		
		printf("Compensating for air resistance, the fall was %lf meters\n", currentX);
		percentage = (distancefell - currentX)* 100 / (currentX);
		printf("This is %d%% less than computed before", percentage);
		
return 0;
}

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