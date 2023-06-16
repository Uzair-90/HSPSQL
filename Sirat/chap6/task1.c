#include <stdio.h>

int main (){
	float l,n;
	
	printf("Enter a number: ");
	scanf("%f",&n);
	
	l=n;
	
	while(n!=0){
		
		printf("Enter a number: ");
		scanf("%f",&n);
		if(n>l)
			l=n;
	}
	
	printf("the largest number entered was %.2f",l);
	
}
