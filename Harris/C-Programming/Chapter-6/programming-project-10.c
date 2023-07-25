#include <stdio.h>

int main()
{
    int min_date = 32, min_month = 13, min_year = 9999, date, month, year;
    
    printf("Enter first date (mm/dd/yy): ");
    scanf("%d/%d/%d", &month, &date, &year);

    while (date > 0, month > 0, year > 0) 
    {
        if (year < min_year)
        {
            min_year = year;
            min_month = month;
            min_date = date;
        }
        else if (year == min_year)
        {
            if (month < min_month) 
            {
                min_year = year;
                min_month = month;
                min_date = date;
            }
            else if (month == min_month)
            {
                if (date < min_date)
                {
                    min_year = year;
                    min_month = month;
                    min_date = date;
                }
            } 
        }

        printf("Enter first date (mm/dd/yy): ");
        scanf("%d/%d/%d", &month, &date, &year);
    }
 
    printf("%2d/%2d/%2d is earlier.", min_month, min_date, min_year);

    return 0;
}