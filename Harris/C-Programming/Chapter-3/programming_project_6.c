#include <stdio.h>

int main(void) 
{
    int num1, denom1, num2, denom2, result_num, result_denom;

    printf("Enter expression (two fractions sperated by a plus): ");  // X1/Y1+X2/Y2 format.
    scanf("%d/%d+%d/%d", &num1, &denom1, &num2, &denom2);
    result_num = num1 * denom2 + num2 * denom1;
    result_denom = denom1 * denom2;

    printf("Output: %d/%d", result_num, result_denom);

    return 0;
}