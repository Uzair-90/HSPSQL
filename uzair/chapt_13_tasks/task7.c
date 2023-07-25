#include <stdio.h>

int main() {

    int number;
    char *tens[] = {"twenty", "thirty", "forty", "fifty","sixty", "seventy", "eighty", "ninety"},
         *teens[] = {"ten", "eleven", "twelve", "thirteen", "fourteen","fifteen", "sixteen", "seventeen", "eighteen", "nineteen"},
         *ones[] = {"", "one", "two", "three", "four", "five","six", "seven", "eight", "nine"};

    printf("Enter a two-digit number: ");
    scanf("%d", &number);
    printf("You entered the number ");
    if (number / 10 == 1)
        printf("%s\n", teens[n % 10]);
    else
        printf("%s %s\n", tens[n / 10 - 2], ones[n % 10]);
    return 0;
}
