#include <stdio.h>

int main()
{
    float number, largest;

    do 
    {
        printf("Enter a number (0 or negative to exit): ");
        scanf("%f", &number);
        if (number > largest)
            largest = number;      
    } while (number > 0);

    printf("Largest number is %.3f", largest);

    return 0;
}