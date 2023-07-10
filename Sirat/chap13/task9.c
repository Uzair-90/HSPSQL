#include <stdio.h>

int vowel_count(const char*c){
	int i ,t;
	
	for(i=0;c[i]!= '\0';i++){
		
		if (c[i]!=' '){
			if(c[i]=='a' || c[i]=='e' || c[i]=='i' || c[i]=='o' || c[i]=='u')
				t++;
		}
	}
	
	return t;
}

int main(){
	
	char c[30];
	int i,t;
	t=0;
	printf("enter a sentence: ");
	gets(c);
	
	t=vowel_count(c);

	
	printf("your sentence contain %d vowels",t);
	
	return 0;
	
}
