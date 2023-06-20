#include <stdio.h>

int powerr(int x,int n){
	if (n==0)
		return 1;
	
	if(n%2==0){
		return powerr(x,n/2)*powerr(x,n/2);
	}	
	else
		return x*powerr(x,n-1);
	
	
}

int main(){
	int x,n;
	int s;
	
	printf("To calculate the power enter the base number: ");
	scanf("%d",&x);
	
	printf("Enter the power number: ");
	scanf("%d",&n);
	
	s=powerr(x,n);
	
	printf("the answer is: %d",s);
	
	return 0;
	
}
