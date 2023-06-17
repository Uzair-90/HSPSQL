#include <stdio.h>

int main(){
	
	char c[30];
	int i,t;
	t=0;
	printf("enter a sentence: ");
	gets(c);
	
	for(i=0;c[i]!= '\0';i++){
		
		if (c[i]!=' '){
			if(c[i]=='a' || c[i]=='e' || c[i]=='i' || c[i]=='o' || c[i]=='u')
				t++;
		}
	}
	
	
	printf("your sentence contain %d vowels",t);
	
	return 0;
	
}
