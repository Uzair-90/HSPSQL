#include <stdio.h>

int main(void) {
    
    char m[30];
    char s; 
	char *p = m;

    printf("Enter a message: ");

    while ((s = getchar()) != '\n' && p < m + 30)
        *p++ = s;

    p--;
    printf("Reversal is: ");

    while (p >= m)
        putchar(*p--);

    return 0;
} 
