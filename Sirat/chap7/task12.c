#include <stdio.h>

int main(){
	
	float n1,n2,n3,r;
	char c1,c2;
	
	
	printf("enter an expression with any two operators: ");
	scanf("%f%c%f%c%f",&n1,&c1,&n2,&c2,&n3);
	
	switch (c1){
		case '+':
			r=n1+n2;
			break;
			
		case '-':
			r=n1-n2;
			break;
			
		case '*':
			r=n1*n2;
			break;	
			
		case '/':
			r=n1/n2;
			break;	
				
	}
	
	switch (c2){
		case '+':
			r+=n3;
			break;
			
		case '-':
			r-=n3;
			break;
			
		case '*':
			r*=n3;
			break;	
			
		case '/':
			r/=n3;
			break;	
				
	}
	printf("value of expression: %.2f",r);
	
	
	
	
}
