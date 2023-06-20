#include <stdio.h>

int main(void) 
{
    int number, first_digit, second_digit, third_digit, fourth_digit, fifth_digit;

    printf("Enter a number between 0 and 32767: ");
    scanf("%d", &number);
    first_digit = number % 8;
    number /= 8;
    second_digit = number % 8;
    number /= 8;
    third_digit = number % 8;
    number /= 8;
    fourth_digit = number % 8;
    fifth_digit = number / 8;
    
    printf("In octal your number is: 0%d%d%d%d", fourth_digit, third_digit, second_digit, first_digit);
    
    return 0;
}