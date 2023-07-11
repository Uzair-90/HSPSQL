#include <stdio.h>
#include<ctype.h>
#define max 100

int main() {
    char message[max];
    char *p = &message[0];
    char ch;
    
    
    printf("Enter a message: ");
    while ((ch = toupper(getchar())) != '\n') {
        if (isalpha(ch))
            *p++ = ch;
    }
    p--;
    
    char *q;
    
    
    for(q = message; q < p; q++,p--){
        
        if(*q!=*p){
            printf("Not a palondrome!");
            return 0;
        }
    }
    
    printf("\npalondrome.\n");
    
    return 0;
}
