#include <stdio.h>

int main()
{
    int number = 0;
    printf("Enter a number between 0 and 36725: ");
    scanf("%d",&number);
    
    int r1 = number%8;
    number/=8;
    
    int r2 = number%8;
    number/=8;
    
    int r3 = number%8;
    number/=8;
    
    int r4 = number%8;
    number/=8;
    
    int r5 = number%8;
    number/=8;
    
    printf("The number in octal is: %d%d%d%d%d\n",r5,r4,r3,r2,r1);

    return 0;
}

