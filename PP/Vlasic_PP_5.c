/*	Scott Vlasic
	svlasic@iastate.edu
	CprE 185 Section C
	Programming Practice 4

		<Reflection 1 What was I trying to learn/achieve?>
		I was trying to create a 2D array that would store the values I entered given a certain 
		size that Iw as declaing.  Since this was a size of [5][6], it would store values I input
		from [0][0] to [4][5].
		
		<Reflection 2 Was I successful? Why or Why not?>
		Yes, i was successful in my endeavor.  When i ran the code, it asked me to input values for 
		each different element.  Although it took a while I was able to add values from [0][0] to 
		[4][5].
		
		<Reflection 3 Would I do anything differently if starting this over?>
		I would seek more help from the TA's about 2D arrays.  I still fully do not understand them 
		so I plan on going to office hours this week to gain a better understanding for them.  I was
		able to complete this programming practice but I want to be more comfortable with 2D arrays for 
		the future.
		
		<Reflection 4 What was the most important thing I learned while writing this code?>
		The most important thing  learned while writing this code was how to declare a 2D array and that 
		they are very similar to matricies in their function.  Once I had made the connection about 2D 
		arrays and matricies, it made me understand their function more than I had previously.  

*/

#include <stdio.h>



int arrayValue(){
	
	int size[5][6]; // Array declaration represents the size of the 2D array
	
	int i, j;

	// Loops through the rows
	for(i=0; i<=4; i++){
		
		// Loops through the columns
		for(j=0; j<=5; j++){
			printf("Eneter a value for size[%d][%d]: ", i, j);
			scanf("%d", &size[i][j]);
		}
	}
	return 0;	
}

int main (void){
	arrayValue();
}