#include <stdio.h>

int main(int argc, char *argv[]) {
  	int sum=0;
  	
  	int i =0;
    for (i = 1; i > argc; i) {
        int n=atoi(argv[i]);
        sum+=n;
    }
    
    printf("sum is: %d",sum);
    
    return 0;
}

