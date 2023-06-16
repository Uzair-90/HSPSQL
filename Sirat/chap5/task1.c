#include <stdio.h>

int main(){
	
	int n=0;
	
	printf("Enter a number (4 digits max): ");
	scanf("%d",&n);
	
	if (n>=0 && n<=9)	
		printf("the number %d has one digits", n);
		
	else if (n>=10 && n<=99)	
		printf("the number %d has two digits", n);
	
	else if (n>=100 && n<=999)	
		printf("the number %d has three digits", n);
	
	else if (n>=1000 && n<=9999)	
		printf("the number %d has four digits", n);
	
	else
		printf("digits more than four");
	return 0;
}
