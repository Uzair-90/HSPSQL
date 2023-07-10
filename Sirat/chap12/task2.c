#include <stdio.h>
#include <ctype.h>


int main(void) {
    char m[30], a;
    char *p = m;
    char *s;

    printf("Enter a message: ");

    while ((a = getchar()) != '\n' && p < m + 30)
        *p++ = a;
    
	p--;
	s=m;
	
	while (s<p){
		if(!isalpha(*p))
			p--;
			
		if(!isalpha(*s))
			s++;
			
		if (tolower(*s)!=tolower(*p))
			printf("not palindrome.");
			
		s++;
		p--;			
			
	}    
	
	printf("it is palindrome");


    return 0;
}

