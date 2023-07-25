#include <stdio.h>

int main()
{
    int i, square, odd, number;

    printf("A program to show a table of squares\nEnter number of entries to print: ");
    scanf("%d", &number);

    odd = 3;
    for (i = 1, square = 1; i <= number; odd += 2, i++)
    {
        printf("%10d %10d\n", i, square);
        square += odd;
    } 

    return 0;
}