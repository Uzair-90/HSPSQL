#include <stdio.h>

int main()
{
    int hour,minute;
    
    printf("Enter a 24 hour time as xx:xx ");
    scanf("%d:%d",&hour,&minute);
    
    if (hour > 12){
        hour -= 12;
        
        printf("The time in 12 hour format is: %d:%d PM\n",hour,minute);
    }
    else{
        printf("The time in 12 hour format is: %d:%d AM",hour,minute);
    }
    

    return 0;
}

