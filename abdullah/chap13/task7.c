#include<stdio.h>




int main(void)
{
    int number, tens, ones;
    char *ones_tostr[] = {"one.", "two.", "three", "four.", "five.",
                          "six.", "seven.", "eight.", "nine."};

    char *teens_tostr[] = {"ten.", "eleven.", "twelve.", "thirteen.",
                           "fourteen.", "fifteen.", "sixteen.", "seventeen.",
                           "eighteen.", "nineteen."};

    char *tens_tostr[] = {"twenty-", "thirty-", "forty-", "fifty-",
                          "sixty-", "seventy-", "eighty-", "ninety-"};
                          
                          
    tens = number / 10;
    ones = number % 10;                      
    printf("Enter a two-digit number: ");
    scanf("%d", &number);

    if (number < 1 || number > 99) {
        printf("Error, please enter a number between 1 and 99.");
        return 0; tens = number / 10;
    
    }
     if (number / 10 == 1)
        printf("%s\n", teens_tostr[number%10]);
    else
        printf("%s %s\n", tens_tostr[ones / 10 - 2], ones_tostr[number % 10]);
}
