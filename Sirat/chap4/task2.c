#include <stdio.h>

int main(){
	int n=0;
	
	printf("Enter a three-digit number: ");
	scanf("%d",&n);
	
	int l=n%10;			
	int f=n/10;			
	int m=f%10;
	int s=f/10;
	
	printf("the reversal is: %d%d%d",l,m,s);
	
	return 0;


return 0;
}
