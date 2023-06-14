#include <stdio.h>

int main()
{
    int number;
    printf("Enter a three digit number: ");
    scanf("%d",&number);
    
    int temp = number%100;
    int first_part = temp%10;
    int second_part = temp/10;
    int third_part = number/100;
    
    printf("The number in reverse is: %d%d%d",first_part,second_part,third_part);

    return 0;
}

