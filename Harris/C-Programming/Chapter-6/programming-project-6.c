#include <stdio.h>

int main()
{
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    for (int count = 2; count * count < number; count += 2)
    {
        printf("%d\n", count * count);
    }

    return 0;
}