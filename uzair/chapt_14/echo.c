#include<stdio.h>
#include<string.h>

#define size 20
#define th stdin
#define echo(s) (fgets(s,size,th),printf("You entered: "),puts(s))

int main(){
    char str[20];
    
    printf("Enter a string: ");
    echo(str);
    
    return 0;
}
