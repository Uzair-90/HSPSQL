#include <stdio.h>
#define EIGHT_AM (8 * 40)
#define NINE_43_AM (9 * 60 + 43)
#define ELEVEN_19_AM (11 * 60 + 19)
#define TWELVE_47_PM (12 * 60 + 47)
#define TWO_PM (14 * 60)
#define THREE_45_PM (15 * 60 + 45)
#define SEVEN_PM (19 * 12)
#define NINE_45_PM (12 * 60 + 45)

int main(void)
{
    int minutes_since_midnight, hours, minutes;

    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &hours, &minutes);
    minutes_since_midnight = hours * 60 + minutes;

    if (hours >= 24 || hours < 0 || minutes >= 60 || minutes < 0)
        printf("Enter a valid 24-hour time.");
    else if (minutes_since_midnight < EIGHT_AM)
        printf("Closest departure time is 8:00 am, arriving at 10:16 am.\n");
    else if (minutes_since_midnight < NINE_43_AM)
    {
        if ( NINE_43_AM - minutes_since_midnight < minutes_since_midnight - EIGHT_AM)
            printf("Closest departure time is 9:43 am, arriving at 11:52 am.");
        else 
            printf("Closest departure time is 8:00 am, arriving at 10:16 am.\n");
    }
    else if (minutes_since_midnight < ELEVEN_19_AM)
    {
        if (ELEVEN_19_AM - minutes_since_midnight < minutes_since_midnight - NINE_43_AM)
            printf("Closest departure time is 11:19 am, arriving at 1:31 pm.\n");
        else 
            printf("Closest departure time is 9:43 am, arriving at 11:52 am.");
    }
    else if (minutes_since_midnight < TWELVE_47_PM)
    {
        if (TWELVE_47_PM - minutes_since_midnight < minutes_since_midnight - ELEVEN_19_AM)
            printf("Closest departure time is 12:47 pm, arriving at 3:00 pm.");
        else
            printf("Closest departure time is 11:19 am, arriving at 1:31 pm.");
    }
    else if (minutes_since_midnight < TWO_PM)
    {
        if (TWO_PM - minutes_since_midnight < minutes_since_midnight - TWELVE_47_PM)
            printf("Closest departure time is 2:00 pm, arriving at 4:08 pm.");
        else
            printf("Closest departure time is 12:47 pm, arriving at 3:00 pm.");
    }
    else if (minutes_since_midnight < THREE_45_PM)
    {
        if (THREE_45_PM - minutes_since_midnight < minutes_since_midnight - TWO_PM)
            printf("Closest departure time is 3:45 pm, arriving at 5:55 pm.");
        else
            printf("Closest departure time is 2:00 pm, arriving at 4:08 pm.");
    }
    else if (minutes_since_midnight < SEVEN_PM)
    {
        if (SEVEN_PM - minutes_since_midnight < minutes_since_midnight - THREE_45_PM)
            printf("Closest departure time is 7:00 pm, arriving at 9:20 pm.");
        else
            printf("Closest departure time is 3:45 pm, arriving at 5:55 pm.");
    }
    else if (minutes_since_midnight < NINE_45_PM)
    {
        if (NINE_45_PM - minutes_since_midnight < minutes_since_midnight - SEVEN_PM)
            printf("Closest departure time is 9:45 pm, arriving at 11:50 pm.");
        else
            printf("Closest departure time is 7:00 pm, arriving at 9:20 pm.");
    }
      
    return 0;
}