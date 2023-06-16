#include <stdio.h>

int main(){
	
	int n,i,j;
	
	printf("Enter the value of n for e constant: ");
	scanf("%d",&n);
	
	float e=1;
	float x=1;
	for(i=1;i<=n;i++){
		for(j=1;j<=i;j++){
			x*=j;
		}
		float y=1/x;
		e+=y;
	}
	
	printf("e:%.2f",e);
	
	return 0;
}
