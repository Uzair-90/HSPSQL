#include <stdio.h>

int main() {
    int f, s;
    
    char *d[] = {
        "", "one", "two", "three", 
		"four", "five", "six", 
		"seven", "eight", "nine"
    };
    
    char *t[] = {
        "ten", "eleven", "twelve", 
		"thirteen", "fourteen", "fifteen", 
		"sixteen", "seventeen", "eighteen", "nineteen"
    };
    
    char *tens[] = {
        "", "", "twenty", "thirty", 
		"forty", "fifty", "sixty", 
		"seventy", "eighty", "ninety"
    };
    
    
    printf("Enter a two-digit number: ");
    scanf("%1d%1d", &f, &s);
    
    printf("You entered the number ");

    
    if (f == 1) {
        printf("%s\n", t[s]);
    } 
	else {
        printf("%s%s", tens[f], d[s]);
    }
    
    return 0;
}

