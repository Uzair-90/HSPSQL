#include <stdio.h>

int main()
{
    int date1, month1, year1, date2, month2, year2;

    printf("Enter first date (mm/dd/yy): ");
    scanf("%d/%d/%d", &month1, &date1, &year1);
    printf("Enter second date (mm/dd/yy): ");
    scanf("%d/%d/%d", &month2, &date2, &year2);

    if (year1 < year2)
    {
        printf("%d/%d/%d is earlier than %d/%d/%d", month1, date1, year1, month2, date2, year2);
        return 0;
    }
    else if (year1 == year2)
    {
        if (month1 < month2) 
        {
            printf("%d/%d/%d is earlier than %d/%d/%d", month1, date1, year1, month2, date2, year2);
            return 0;
        }
        else if (month1 == month2)
        {
            if (date1 < date2)
            {
                printf("%d/%d/%d is earlier than %d/%d/%d", month1, date1, year1, month2, date2, year2);
                return 0;
            }
            else if (date1 == date2)
            {
                printf("Dates are the same");
                return 0;
            }
        } 
    }

    printf("%d/%d/%d is earlier than %d/%d/%d", month2, date2, year2, month1, date1, year1);

    return 0;
}