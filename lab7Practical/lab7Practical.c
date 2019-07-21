//Prototpyes

void scanISBN(int arr[10]);
int isValidISBN(int isbn[10]);

#include <stdio.h>
#include <math.h>

int main(void){
	int numberISBN = 0;
	printf("How many ISBN's are there?");
	scanf("%d", &numberISBN);

	int isbn[10];
	int i = 0;
	int j = 0;
	for(i=0; i<numberISBN; i++){
		scanISBN(isbn);
		if(isValidISBN(isbn)){
			printf("Valid ISBN\n");
		}
		
		else{
			for(j=0; j<10; j++){
				printf("%1d", isbn[j]);
			}
			
		}
		printf("\n");
	}	
}

void scanISBN(int arr[10]){
	int i = 0;
	for(i=0; i<10; i++){
		scanf("%1d", &(arr[i]));
	}
	
}

int isValidISBN(int isbn[10]){
	int temp;
	temp = (10*isbn[0])+(9*isbn[1])+(8*isbn[2])+(7*isbn[3])+(6*isbn[4])+(5*isbn[5])+(4*isbn[6])+(3*isbn[7])+(2*isbn[8])+(1*isbn[9]);
	
	if((temp%11) == 0){
		return 1; 
	}
	else{
		return 0;
	}
}