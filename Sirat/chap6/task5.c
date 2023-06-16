#include <stdio.h>

int main(){
	
	int n;
	int c;
	
	printf("enter digits:");
	scanf("%d",&n);
	
	
	printf("reversal: ");
	while(n!=0){
		c=n%10;
		n=n/10;
		
		printf("%.1d",c);
	}
	
	
	
}
