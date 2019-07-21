/*	Scott Vlasic
	svlasic@iastate.edu
	CprE 185 Section C 
	Programming Practice 3
		
		<Reflection 1 What was I trying to learn/achieve?>
		 I was trying to learn more about loops and more specifically the while loop.  I wanted to start with a count 
		 of 15 and return a statement counting down until the value reached 4.  Then I wanted the function to break 
		 and thus stop outputting values.
		
		<Reflection 2 Was I successful? Why or Why not?>
		 I was successful in my task as when I ran the code, the main function had the output of "Good Morning Number: " 
		 with the proper number counting down from 15.  However, this only lasted until number 4 and after that the 
		 program stopped.
		
		<Reflection 3 Would I do anything differently if starting this over?>
		 If I could do anything different I would try to write the following code as a for loop to see if I would get the
		 same output that I wanted.  I would also try to add more complex boolean functions and see if the output would 
		 satisfy my needs.  It would be interesting to see how added if statements would affect the code. 
		
		<Reflection 4 What was the most important thing I learned while writing this code?>
		 I'd say the most important thing I leanred about writing this code was an enhanced understanding of while loops.
		 Before this excercise I was confused as to how the while loop worked and when it would stop exactly.  I also 
		 learned I could stop the program early myself by adding a break for a certain value.  This is useful for 
		 specifying certain values that I would want and how I could manipulate the program to output what I wanted.  
	
*/

#include <stdio.h>

int main(void){
	int i = 15;
	
	while(i > 0){
		printf("Good Morning Number %d\n", i);
		i--;
		if(i<=4){
			break;
		}
	}
	return 0;
}
