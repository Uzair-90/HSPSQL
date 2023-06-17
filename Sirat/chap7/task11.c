#include <stdio.h>

int main(){
	
	char s[20];
	char f[20];
	
	printf("Enter a first and last name: ");
	scanf("%s %s",&f,&s);
	
	char c=f[0];
	
	printf("%s, %c.",s,c);
	
}
