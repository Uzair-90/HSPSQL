#include <stdio.h>

int main(){
	
	char c[30];
	int i;
	float t=0;
	float s=1;

	printf("enter a sentence: ");
	gets(c);
	
	for(i=0;c[i]!= '\0';i++){
		
		if (c[i]!=' ')
			t++;
				
		else if (c[i]==' ')
			s++;
	}
	
	float r=t/s;
	
	printf("average word length: %f",r);
	
	return 0;
	
}
