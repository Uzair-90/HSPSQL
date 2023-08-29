#include <stdio.h>
#define max 100

int main() {
    char message[max];
    char *p = &message[0];
    char ch;
    printf("Enter a message: ");
    while (ch != '\n') {
        ch = getchar();
        *p = ch;
        p++;
    }
    
    p--;
    
    for (; p >= message; p--) {
        printf("%c", *p);
    }
    
    return 0;
}

