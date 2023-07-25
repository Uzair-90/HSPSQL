#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
	
	int sum;
	char **p;
	
	for(p = argv + 1; p < argv + argc; p++)
        sum += atoi(*p);
        
    printf("total: %d",sum);
        
	
	return 0;
	
}
