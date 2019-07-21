// lab7.c
//
// This is the outline for your program
// Please implement the functions given by the prototypes below and
// complete the main function to make the program complete.
// You must implement the functions which are prototyped below exactly
//  as they are requested.

#include <stdio.h>
#include <math.h>
#define PI 3.141592653589

//NO GLOBAL VARIABLES ALLOWED


//  PRE: Arguments must point to double variables or int variables as appropriate
//  This function scans a line of explore data, and returns
//  True when left button is pressed
//  False Otherwise
//POST: it modifies its arguments to return values read from the input line.
int read_acc(double* a_x, double* a_y, double* a_z, int* time, int* Button_UP, int* Button_DOWN, int* Button_LEFT, int* Button_RIGHT);

// PRE: -1.0 <= x_mag <= 1.0
// This function computes the roll of the esplora in radians
// if x_mag outside of -1 to 1, treat it as if it were 1 or -1
// POST: -PI/2 <= return value <= PI/2
double roll(double x_mag);

// PRE: -1.0 <= y_mag <= 1.0
// This function computes the pitch of the esplora in radians
// if y_mag outside of -1 to 1, treat it as if it were 1 or -1
// POST: -PI/2 <= return value <= PI/2
double pitch(double y_mag);


// PRE: -PI/2 <= rad <= PI/2
// This function scales the roll value to fit on the screen
// POST: -39 <= return value <= 39
int scaleRadsForScreen(double rad);

// PRE: num >= 0
// This function prints the character use to the screen num times
// This function is the ONLY place printf is allowed to be used
// POST: nothing is returned, but use has been printed num times
void print_chars(int num, char use);

//PRE: -39 <= number <=39
// Uses print_chars to graph a number from -39 to 39 on the screen.
// You may assume that the screen is 80 characters wide.
void graph_line(int number);

int main()
{
	double x, y, z;			// magnitude values of x, y, and z
	int b_Up, b_Down, b_Left, b_Right;	// variables to hold the button statuses
	double roll_rad, pitch_rad;		// value of the roll measured in radians
	int scaled_value; 	// value of the roll adjusted to fit screen display
	int position = 1, t=0;
	//insert any beginning needed code here

	do
	{
		read_acc(&x, &y, &z, &t, &b_Up, &b_Down, &b_Left, &b_Right);// Get line of input
		
		roll_rad = roll(x);
		pitch_rad = pitch(y);// Calculate roll and pitch.
		
		if(b_Up == 1){
			position = 1;
		}
		if(b_Down == 1){
			position=2;
		}
			
			
	if (position == 1){
		scaled_value = scaleRadsForScreen(-roll_rad);
	}
	else if (position == 2){
		scaled_value = scaleRadsForScreen(-pitch_rad); // Scale your output value
	}
	graph_line(scaled_value); // Output your graph line
		
		fflush(stdout);
	} 
	while (!b_Left); // Modify to stop when left button is pressed
	return 0;
}

int read_acc(double* a_x, double* a_y, double* a_z, int* time, int* Button_UP, int* Button_DOWN, int* Button_LEFT, int* Button_RIGHT){
	int k, j;
	scanf("%d, %lf, %lf, %lf, %d, %d, %d, %d, %d, %d", time, a_x, a_y, a_z, Button_UP, Button_DOWN, Button_LEFT, Button_RIGHT, &k, &j);
	if(Button_LEFT != 0){
			return 1;
	}
return 0;
}

double roll(double x_mag){
	double getValue;
	if(x_mag >= 1.0){
		getValue =  asin(1.0);
	}
	else if(x_mag <= -1.0){
		getValue =  asin(-1.0);
	}
	else{
		getValue =  asin(x_mag);
	}
	
	return getValue;
}

double pitch(double y_mag){
	double getValue2;
	if(y_mag >= 1.0){
		getValue2 = asin(1.0);
	}
	else if(y_mag <= -1.0){
		getValue2 = asin(-1.0);
	}
	else{
		getValue2 = asin(y_mag);
	}
	
	return getValue2;
}

int scaleRadsForScreen(double rad){
	double getValue3;
	getValue3 = rad * (78.0/PI);
	return getValue3;
}

void print_chars(int num, char use){
	int i;
	for(i=0; i < num; i++){
		printf("%c", use); 
		}
}

void graph_line(int number){
	if(number < 0 ){
		print_chars(39-(number * -1), ' ');
		print_chars(number * -1, 'l');
	
	}
	else if(number > 0){
	
		print_chars(39, ' ');
		print_chars(number, 'r');
	}
	else if(number == 0){
		print_chars(39, ' ');
		print_chars(1, '0');
	}
	print_chars(1, '\n');
}	
