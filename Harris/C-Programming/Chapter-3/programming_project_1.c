#include <stdio.h>

int main(void)
{
    int date, month, year;

    printf("Enter a date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &month, &date, &year);

    printf("%.4d%.2d%.2d\n", year, month, date);

    return 0;
}