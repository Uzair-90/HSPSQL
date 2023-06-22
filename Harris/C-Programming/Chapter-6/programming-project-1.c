#include <stdio.h>

int main(void)
{
    float number, largest = 0.0f;

    do {
        printf("Enter a number (enter 0 to end): ");
        scanf("%f", &number);
        if (number > largest)
            largest = number;
    } while (number > 0.0f);

    printf("\nThe largest number entered was %.2f\n\n", largest);

    return 0;
}
