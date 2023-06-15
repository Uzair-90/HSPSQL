#include <stdio.h>

int main(){
	int n=0;
	
	printf("Enter a two-digit number: ");
	scanf("%d",&n);
	
	int l=n%10;
	int f=n/10;
	
	printf("the reversal is: %d%d",l,f);
	
	return 0;
}
