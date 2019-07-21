/*	Scott Vlasic
	svlasic@iastate.edu
	CprE 185 Section C
	Programming Practice 7

		<Reflection 1 What was I trying to learn/achieve?>
		I was trying to modify a string using malloc and other devies so that the printf() would 
		thank a particular family for coming to an event(in thi case a wedding) based on their last 
		names.
		
		<Reflection 2 Was I successful? Why or Why not?>
		I was successufl in doing this as when I tested the function, it thanked the last name 
		of the user with the send off greeting I had previously prepared.  For example, since my last
		name is Vlasic, when it prompted me to enter my last name, the print out was "We want to thank 
		the Vlasic family for coming to the wedding."
		
		<Reflection 3 Would I do anything differently if starting this over?>
		If I was to start this over I would see if I could write the code in a separate function if at all
		possible.  When I talked to Josh, he said it would be fine to write it in just a main function but I 
		was wondering if we write this type of code in separate functions at all. 
		
		<Reflection 4 What was the most important thing I learned while writing this code?>
		I learned the valuable properties of strcpy() and how it basically assigns on varible to another.  For 
		example, in my code when I said strcpy(lastSendoff, "We want to thank the "), it was assigning the pointer
		lastSendoff to the string I had provided.  This was something I had little knowledge about before writing this 
		and something I think will be useful in the future.  
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void){
	char lastName[100]; // Last name given by user
	char* lastSendoff = NULL; // Send off message to the user
	
	// User enters their last name
	printf("Enter your last name: ");
	fgets(lastName, 100, stdin);
	
	// Adds null value to the last element 
	lastName[strlen(lastName)-1] = '\0';
	
	lastSendoff = (char*)malloc((strlen(lastName) + 8) * sizeof(char));
	
	// Modifies the string so it thanks the user's family 
	strcpy(lastSendoff, "We want to thank the ");
	strcat(lastSendoff, lastName);
	strcat(lastSendoff, " family for coming to the wedding.");
	
	printf("%s\n", lastSendoff); // Prints out the message
	
	return 0;
}
