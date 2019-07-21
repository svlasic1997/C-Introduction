#include <stdio.h>

#define MAXPOINTS 10000

// compute the average of the first num_items of buffer
double avg(double buffer[], int num_items);

//update the max and min of the first num_items of array
void maxmin(double array[], int num_items, double* max, double* min);

//shift length-1 elements of the buffer to the left and put the 
//new_item on the right.
void updatebuffer(double buffer[], int length, double new_item);



int main(int argc, char* argv[]) {

	double x[MAXPOINTS], y[MAXPOINTS], z[MAXPOINTS];
	int lengthofavg = 0;
	if (argc>1) {
		sscanf(argv[1], "%d", &lengthofavg );
		printf("You entered a buffer length of %d\n", lengthofavg);
	}
	else {
		printf("Enter a length on the command line\n");
		return -1;
	}
	if (lengthofavg <1 || lengthofavg >MAXPOINTS) {
		printf("Invalid length\n");
		return -1;
	}
	
	/* Put your code here */
	double accX, accY, accZ; // Variables for the acceleration values
	int b1, b2, b3, b4, b5, b6; // Variables for the buttons, slider, and joystick
	double max, min; // Variables for the maximum and minimum values
	double avgX, avgY, avgZ; // Averages of the acceleration values 
	int i = 0;
	
	
	for(i = 0; i < lengthofavg; i++){                                                                        
		scanf("%lf, %lf, %lf, %d, %d, %d, %d, %d, %d", &accX, &accY, &accZ, &b1, &b2, &b3, &b4, &b5, &b6);
		updatebuffer(x, lengthofavg, accX);
		updatebuffer(y, lengthofavg, accY);
		updatebuffer(z, lengthofavg, accZ);	
	}
	
	do{
		scanf("%lf, %lf, %lf, %d, %d, %d, %d, %d, %d", &accX, &accY, &accZ, &b1, &b2, &b3, &b4, &b5, &b6);
		updatebuffer(x, lengthofavg, accX);
		updatebuffer(y, lengthofavg, accY);
		updatebuffer(z, lengthofavg, accZ);
		
		
		avgX = avg(x, lengthofavg);
		avgY = avg(y, lengthofavg);
		avgZ = avg(z, lengthofavg);
		
		// Prints the averages of avgX, avgY, and avgZ
		printf("%lf, ", avgX);
		printf("%lf, ", avgY);
		printf("%lf, ", avgZ);
		
		// Prints the accelerations of x, y, and z
		printf("%lf, ", accX);
		printf("%lf, ", accY);
		printf("%lf, ", accZ);
		
		maxmin(x, lengthofavg, &max, &min);
		printf("%lf, %lf, ", max, min);
		
		maxmin(y, lengthofavg, &max, &min);
		printf("%lf, %lf, ", max, min);
		
		maxmin(z, lengthofavg, &max, &min);
		printf("%lf, %lf", max, min);
		
		printf("\n");
		fflush(stdout);
		
		
	}
	while(!b4); // Ends the program when the left button is pressed
	
	



}


double avg(double buffer[], int num_items){
	int i = 0;
	double average = 0;
	double sum = 0;
	for(i=0; i<= num_items; i++){
		sum = sum + buffer[i]; // Only looks for the first num_items
	}
	average = sum/num_items;
	return average;
}

void maxmin(double array[], int num_items, double* max, double* min){
	int i = 0;
	*max = array[0];
	*min = array[0];
	for(i=0; i<num_items; i++){
		if(array[i] > *max){
			*max = array[i]; // Updates the max of the first num_items
		}
		else{
			*min = array[i]; // Updates the min of the first num_items
		} 
		
	}
}

void updatebuffer(double buffer[], int length, double new_item){
	int i = 0;
	for(i=0; i<length; i++){
		buffer[i] = buffer[i+1]; // Shifts the elements to the left
	}
	buffer[length-1] = new_item; // Puts new_item on the right
}


