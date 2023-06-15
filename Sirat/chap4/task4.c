#include <stdio.h>

int main(){
	int n;
	
	printf("Enter a number between 0 and 32767: ");
	scanf("%d",&n);
	
	int n1=n%8;
	n=n/8;
	int n2=n%8;
	n=n/8;
	int n3=n%8;
	n=n/8;
	int n4=n%8;
	n=n/8;
	int n5=n%8;
	
	printf("in octal, your number is: %d%d%d%d%d",n5,n4,n3,n2,n1);
	
	
	return 0;
}
