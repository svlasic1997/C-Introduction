/*	Scott Vlasic
	svlasic@iastate.edu
	CprE 185 Section C 
	Programming Practice 1
		
		<Reflection 1 What was I trying to learn/achieve?>
		I was trying to use boolean statements to make certain aspects of my code execute
		while having others not.  For example I wanted my addition function to execute only
		if the value of x was either greater than 0 or less than 100.  Otherwise the console 
		would print that it was out of the range.  
		
		<Reflection 2 Was I successful? Why or Why not?>
		Yes I was successful in my goal.  In the first scenario I wanted the sum to execute only
		if x was between 0 and 100 and this was successful.  In the second scenario I wanted the 
		product to execute only if x, y, and z were not equal to 0.  Finally in the third scenario
		I wanted the difference to execute only if x was greater than 0 and both y and z were less than
		0.  
		
		<Reflection 3 Would I do anything differently if starting this over?>
		If I was starting this over I think I would change my void functions a bit so that they 
		were easier to write boolean statements for.  In my code it doesn't make sense that you 
		wouldn't want the code to execute for only certain numbers, especially for additon.  That's 
		just my personal opinion though.  I might change some of them around to where number parameters
		would be more useful and make sense.  I also need to go into the help session and see what is 
		wrong with my Notepad++ and Cywgin on my laptop since they don't seem to be working correctly.  
		Therefore I had to use the lab for most of this project.  
		
		<Reflection 4 What was the most important thing I learned while writing this code?>
		I became more comfortable with boolean operators.  I feel that if statements and the operators and 
		(&&) and or(||) can be very useful throughout the class so if I get a better grasp of them now I will
		greatly benefit from it later.  I also learned to use parentheses in my if statements so that my code is
		better organzied and executes how I want it to.
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
	
	// Returns the sum of the three variables if x is between greater than 0 or less than 100
	if(x>0 || x<100){
		printf("The sum of %d + %d + %d is: %d.\n", x, y, z, x+y+z);
	}
	else{
		printf("Out of specified range");
	}
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
	
	// Returns the product of the three variables as long as none of them are 0
	if(x != 0 && y != 0 && z != 0){
		printf("The product of %d*%d*%d is: %d.\n", x, y, z, x*y*z);
	}
	else{
		printf("The product value is 0");
	}
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
	
	// Returns the difference of three variables if x is greater than 0 and y and z are less than 0
	if(x>0 && (y<0 && z<0)){
		printf("The difference of %d-%d-%d is: %d.\n", x, y, z, x-y-z);
	}
	else{
		printf("I won't compute the difference of these numbers);
	}
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
	
	