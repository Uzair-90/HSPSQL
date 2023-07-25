#include <stdio.h>

int main()
{
    int starting_day, days_in_a_month, i;

    printf("Enter number of days in a month: ");
    scanf("%d", &days_in_a_month);
    printf("Starting day for the month (1 = Sunday, 6 = Saturday): ");
    scanf("%d", &starting_day);

    printf("  S  M  T  W  T  F  S\n");
    for (int j = 1; j < starting_day; j++) 
    {
        printf("   ");
    }
    for (i = 1; i <= days_in_a_month; i++, starting_day++) {
        if (starting_day % 7 == 0)
            printf("%3d\n", i);
        else {
            printf("%3d", i);
        }
    }

    return 0;
}