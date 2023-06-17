#include <stdio.h>

int main() {
    int hours = 0, minutes = 0;
    char meridiem;

    printf("Enter the time in 12-hour format:");
    scanf("%d:%d %c",&hours,&minutes,&meridiem);


    if (meridiem == 'P' || meridiem == 'p') {
        if (hours != 12)
            hours += 12;
    } else if (meridiem == 'A' || meridiem == 'a') {
        if (hours == 12)
            hours = 0;
    } else {
        printf("Invalid meridiem. Please provide AM or PM.\n");
        return 1;
    }

    printf("The time in 24-hour format is: %02d:%02d\n", hours, minutes);

    return 0;
}

