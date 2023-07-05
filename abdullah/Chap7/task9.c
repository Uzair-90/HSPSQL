

#include <stdio.h>


int main()
{
    
    
    int min = 0;
    int hours=0;
    char ampm;
    
    printf("Enter a twelve-Hour time: \n");
    
    scanf("%d:%d %c",&hours,&min,&ampm);
      
    if (ampm == 'P' || ampm == 'p') {
        if (hours != 12)
            hours += 12;
    } else if (ampm == 'A' || ampm == 'a') {
        if (hours == 12)
            hours = 0;
    } else {
        printf("The input ampm is invalid ,please provide AM or PM.\n");
        return 1;
    }

    printf("The time in 24-hour format is: %02d:%02d\n", hours, min);


    return 0;
}
       
       
       
       
     
 



