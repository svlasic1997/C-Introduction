/*	Scott Vlasic
	svlasic@iastate.edu
	CprE 185 Section C
	Programming Practice 4

		<Reflection 1 What was I trying to learn/achieve?>
		For this programming practice I was trying to become more familiar with passing parameters to 
		function using reference.  To do this I created a funciton that would calculate the number of 
		yards and feet in a measurement given in feet.  Since 3 feet is equal to 1 yard, I divided the total
		distance in feet by 3 to get yards and then used the % operator to find the leftover feet.
		
		<Reflection 2 Was I successful? Why or Why not?>
		I was successful in my attempt.  I tested many different numbers to see if they would output the correct
		values for feet and yards.  In the current value I have stored, which is 149 feet, the program prints 
		49 yards and 2 feet which is correct.
		
		<Reflection 3 Would I do anything differently if starting this over?>
		If I was starting over I would watch more videos on passing by pointer and try to gain a better understanding
		for pointers themselves.  I would probably go to the TA's for more help as well but I was unable to as my 
		week was packed with exams.
		
		<Reflection 4 What was the most important thing I learned while writing this code?>
		The most important thing I learned while writing this code was when to use a pass by pointer as opposed to 
		two separate functions.  For example when I was first coming up with ideas for this program I was computing 
		the number of quarters returned based on the change given.  I realized though, since I only had one varibale 
		I was looking for, that pass by pointer wouldn't be useful.  I guess then the most important thing is to use pass 
		by pointer only when the values of the output are closely related.

*/

#include <stdio.h>
#include <stdlib.h>


void ConvertYardsFeet(int* distanceYards, int* distanceFeet, int totalDist){
	*distanceYards = totalDist/3;
	*distanceFeet = totalDist % 3;
	return;
}

int main (void){
	int distanceMeasure = 149; // Total distance measured in feet
	int totalYards = 0; // Number of yards to be calculated
	int totalFeet = 0; // Number of feet to be calculated 
	
	ConvertYardsFeet(&totalYards, &totalFeet, distanceMeasure);
	
	printf("There are %d yards and %d feet\n", totalYards, totalFeet);
	
	return 0;
}