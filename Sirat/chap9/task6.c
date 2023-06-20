#include <stdio.h>

int sum(int a){
	int s;
	s=(3*(a*a*a*a*a))+(2*(a*a*a*a))-(5*(a*a*a))-(a*a)+(7*a)-6;
	
	return s;
}

int main(){
	int x, s;
	
	printf("Enter the value of x: ");
	scanf("%d",&x);
	
	s=sum(x);
	
	printf("the sum of polynomial is: %d ",s);
	
	return 0;
	
}
