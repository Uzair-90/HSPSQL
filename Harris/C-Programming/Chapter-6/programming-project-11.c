#include <stdio.h>

int main()
{
    int n, factorial;
    float sum = 1;

    printf("Enter n: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        factorial = 1;
        for (int j = 1; j <= i; j++)
        {
            factorial *= j;
        }

        sum += 1.0f / factorial;
    }

    printf("Approximate value of e till %d is %f", n, sum);
    return 0;
}