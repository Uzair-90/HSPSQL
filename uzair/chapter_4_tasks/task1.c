#include <stdio.h>

int main()
{
    int number;
    printf("Enter a two digit number: ");
    scanf("%d",&number);
    
    int temp = number%10;
    int temp2 = number/10;
    
    printf("The number in reverse is: %d%d",temp,temp2);

    return 0;
}

