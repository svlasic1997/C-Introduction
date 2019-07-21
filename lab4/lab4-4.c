/* Lab 4 Wrapper Program */


#include <stdio.h>

#include <math.h>



/* Put your function prototypes here */
int button(int a, int b, int c, int d, int e);

int main(void) {
	
	int t;
	
	int a,b,c,d,e,f;
	
	while (1) {
		scanf("%d,%d,%d,%d,%d,%d", &a, &b, &c, &d, &e, &f);
		printf("%d\n",button(a,b,c,d,e));
		fflush(stdout);
	}
	
	return 0;
}

int button(int a, int b, int c, int d, int e){
	return (a+b+c+d+e);
}