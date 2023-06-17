#include <stdio.h>

int main(){
	int s;
	printf("Enter a wind speed (in knots): ");
	scanf("%d",&s);
	
	if (s<1)
		printf("description: Calm");
		
	else if (s>=1 &&s<=3)
		printf("description: light air");	
		
	else if (s>=4 && s<=27) 
		printf("description: breeze");
		
	else if (s>=28 && s<=47) 
		printf("description: Gale");
		
	else if (s>=48 && s<=63) 
		printf("description: storm");
		
	else if (s>63) 
		printf("description: Hurricance");			
				
	return 0;  
}
