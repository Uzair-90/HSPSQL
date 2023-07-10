#include <stdio.h>
#include <ctype.h>


int main(void) {
    char m[30], a;
    char *p;
    char *s;

    printf("Enter a message: ");
	
	int i = 0;
    while ((a= getchar()) != '\n' && i < 30) {
        m[i] = a;
        i++;
    }
    
	s=m;
	p=m+i-1;
	
	
	while (s<p){
		if(!isalpha(*p))
			p--;
			
		if(!isalpha(*s))
			s++;
			
		if (tolower(*s)!=tolower(*p)){
		
			printf("not palindrome.");
			return 0;	
	}
		s++;
		p--;			
			
	}    
	
	printf("it is palindrome");


    return 0;
}
