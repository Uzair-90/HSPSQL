

#include <stdio.h>

#define N 50

int main()
{
     
    char *p;
    char message[N];
    p = &message[0];
    char ch;
    
    printf("Enter a message: ");
    
    while(ch!='\n'){
        ch = getchar();
        *p = ch;
        p++;
    }
    
    printf("message in reversed: ");
    for(;p>=message;p--){
        printf("%c",*p);
    }
    return 0;
        
    
}

