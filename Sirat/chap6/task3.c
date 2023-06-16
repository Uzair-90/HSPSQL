#include <stdio.h>

int main(){
	
	int n,d,i;
	
	printf("Enter a fraction: ");
	scanf("%d/%d",&n,&d);
	
	if(n<d)
		i=n;
	else 
		i=d;
		
		
	while(i>1){
		if(n%i==0 && d%i==0)
			break;
		i--;	
	}	
			
	
	printf("in lowest term: %d/%d",n/i,d/i);
	
}
