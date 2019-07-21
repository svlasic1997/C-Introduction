/*	Scott Vlasic
	svlasic@iastate.edu
	CprE 185 Section C 
	Programming Practice 1
		
		<Reflection 1 What was I trying to learn/achieve?>
		I was attempting to see if I could write three different operation functions all that 
		could be called under one main function.  I was looking at the operations of addition, 
		subtraction, and multiplication.
		
		<Reflection 2 Was I successful? Why or Why not?>
		I was successful in my attempts.  All three of the functions I created properly performed
		the desired operations and they were all correctly called in the main function.
		
		<Reflection 3 Would I do anything differently if starting this over?>
		I would use the Cywgin terminal instead of ideone.com since with the latter I was unable to 
		input any values for my variables and instead they were randomly assigned.  I also feel more 
		comfortable with Cywgin since we've been using it the most.
		
		<Reflection 4 What was the most important thing I learned while writing this code?>
		I learned how to get a better grasp on calling functions to the main function.  Before I did 
		this programming practice I was confused on how functions were called in the main but now I am 
		more comfortable with everything.
*/


#include <stdio.h>

void sum(){
	
	// Gives the sum of three numbers 
	int x, y, z;
	
	// Enter a value for x
	printf("What is your first number?\n"); 
	scanf("%d", &x); 
	
	// Enter a value for y
	printf("What is your second number?\n"); // Enter a value for y
	scanf("%d", &y);
	
	// Enter a value for z
	printf("What is your final number?\n"); // Enter a value for z
	scanf("%d", &z);
	
	// Returns the sum of the three variables
	printf("The sum of %d + %d + %d is: %d.\n", x, y, z, x+y+z);
	return;
}

void multiple(){
	
	// Gives the product of three numbers
	int x, y, z;
	
	// Enter a value for x
	printf("Enter the first number: \n");
	scanf("%d", &x);
	
	// Enter a value for y
	printf("Enter the second number: \n");
	scanf("%d", &y);
	
	// Enter a value for z
	printf("Enter the final number: \n");
	scanf("%d", &z);
	
	// Returns the product of the three variables
	printf("The product of %d*%d*%d is: %d.\n", x, y, z, x*y*z);
	return;
}

void difference(){

	// Gives the difference of three numbers 
	int x, y, z;
	
	//Enter a value for x
	printf("Enter the first value: \n");
	scanf("%d", &x);
	
	// Enter a value for y 
	printf("Enter the second value: \n");
	scanf("%d", &y);
	
	//Enter the value for z
	printf("Enter the final value: \n");
	scanf("%d", &z);
	
	// Returns the difference of three variables
	printf("The difference of %d-%d-%d is: %d.\n", x, y, z, x-y-z);
	return;
}

int main(void){
	// Calls from the sum function
	sum();
	// Calls from the multiple function
	multiple();
	// Calls from the difference function
	difference();
	return 0;
}
	
	