#include <stdio.h>
#include <string.h>

int main(){
	
	char m[30];
	char max[30];
	char min[30];
	
	printf("ENTER WORD: ");
	scanf("%s",m);	
	
	strcpy(max,m);
	strcpy(min,m);
	
	while(strlen(m)!=4){
		printf("ENTER WORD: ");
		scanf("%s",m);
		
		if (strcmp(min,m)>0)
			strcpy(min,m);
			
		else if(strcmp(max,m)<0)
			strcpy(max,m);	
		
	}
	
	printf("smallest word: %s\n",min);
	printf("largest word: %s",max);
	
	return 0;
	
}
