#include <stdio.h>

int main(void)
{
    int num1, denom1, num2, denom2, result_num, result_denom;

    printf("Enter first fraction (X/Y format): ");
    scanf("%d/%d", &num1, &denom1);
    printf("Enter second fraction (X/Y format): ");
    scanf("%d/%d", &num2, &denom2);
    result_num = num1 * denom2 + num2 * denom1;
    result_denom = denom1 * denom2;

    printf("The resultant fraction: %d/%d\n", result_num, result_denom);
    printf("(Simplification of fractions is yet to performed)");

    return 0;
}