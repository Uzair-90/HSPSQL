#include <stdio.h>

int main(){
	int n1=0;
	int n2=0;
	int d1=0;
	int d2=0;
	char c;
	
	printf("Enter two fractions separated by a sign : ");
	scanf("%d/%d%1c%d/%d",&n1,&d1,&c,&n2,&d2);
	
	switch (c){
		case '+':
			printf("sum is : %d/%d",n1*d2+n2*d1,d1*d2);
			break;
			
		case '-':
			printf("subtraction is : %d/%d",n1*d2-n2*d1,d1*d2);
			break;
			
		case '*':
			printf("multi is : %d/%d",n1*n2,d1*d2);
			break;	
			
		case '/':
			printf("sum is : %d/%d",n1*d2,d1*n2);
			break;	
				
	}
		

	return 0;
}
