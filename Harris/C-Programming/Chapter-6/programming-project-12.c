#include <stdio.h>

int main()
{
    int factorial, i = 1;
    float sum = 1, e;

    printf("Enter e: ");
    scanf("%d", &e);
    printf("1 ");

    do
    {   
        factorial = 1;
        for (int j = 1; j <= i; j++)
        {
            factorial *= j;
        }

        printf("+ 1/%d! ", i);
        sum += 1.0f / factorial;
        
        i++;
    } while (sum > e);

    printf("\nThe sum is %f", sum);

    return 0;
}