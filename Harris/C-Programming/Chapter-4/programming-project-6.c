#include <stdio.h>

int main(void)
{
    int first_total, second_total, total, first_digit, second_digit, third_digit, fourth_digit, 
        fifth_digit, sixth_digit, seventh_digit, eighth_digit, ninth_digit, tenth_digit, eleventh_digit, twelfth_digit;

    printf("Enter the first 12 digits of an EAN number: ");
    scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d", &first_digit, &second_digit, &third_digit, &fourth_digit, &fifth_digit, 
           &sixth_digit, &seventh_digit, &eighth_digit, &ninth_digit, &tenth_digit, &eleventh_digit, &twelfth_digit);
    first_total = second_digit + fourth_digit + sixth_digit + eighth_digit + tenth_digit + twelfth_digit;
    second_total = first_digit + third_digit + fifth_digit + seventh_digit + ninth_digit + eleventh_digit;
    total = first_total * 3 + second_total;

    printf("Check digit: %d", 9 - (total - 1) % 10);

    return 0;
}