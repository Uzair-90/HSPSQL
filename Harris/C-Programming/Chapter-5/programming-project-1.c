#include <stdio.h>

int main(void) 
{
    int hour, minutes;

    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &hour, &minutes);
    if (hour > 12)
        hour -= 12;

    printf("Equivalent 12-hour time: %d:%d", hour, minutes);
    
    return 0;
}