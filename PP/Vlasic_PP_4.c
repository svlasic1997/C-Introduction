/*	Scott Vlasic
	svlasic@iastate.edu
	CprE 185 Section C
	Programming Practice 4

		<Reflection 1 What was I trying to learn/achieve?>
		With this program I was trying to learn how to better use 1D arrays and more 
		specifically with this one I wanted to create a program that would calculate 
		the average of a certain number of values stored in an array.
		
		<Reflection 2 Was I successful? Why or Why not?>
		I was successful in my attempt at creating a program for the average.  The 
		function I created ran without a hitch and properly calculated the average of
		the 15 values I input.  
		
		<Reflection 3 Would I do anything differently if starting this over?>
		If I was to start this over again I would start by reading more about arrays and 
		some of the specifics that come with it.  For example, one of my errors in this code 
		early on was in the scanf() as I wrote &i instead of &num[i].  
		
		<Reflection 4 What was the most important thing I learned while writing this code?>
		I'd say the most important thing I learned while writing this code was how to write 
		for loops with arrays in them.  Before this I didn't properly understand how arrays 
		worked in the scanf() but now I am more comfortable.  Also in the for loop declaration 
		I had to have i<= to the proper number of values since 15 is actually 14 as arrays begin 
		with 0.

*/




#include <stdio.h>

int average(){
	int i = 0;
	int average = 0;
	int sum = 0;
	
	//Length of array is 15
	int num[15];
	
	//Scans for numbers 
	for(i=0; i<=14; i++){
		printf("Enter number: %d\n", i);
		scanf("%d", &num[i]);
	}
	
	//Gives the sum of the array based on the numbers
	for(i=0; i<=14; i++){
		sum = sum+num[i];
	}
	
	//Average of the 15 numbers given the sum
	average = sum/15;
	
	printf("The average is: %d", average);
	return 0;
	
}

int main(void){
	average();
}