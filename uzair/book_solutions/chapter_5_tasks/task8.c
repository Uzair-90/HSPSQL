#include <stdio.h>

int main()
{
    int d1,d2,d3,d4,d5,d6,d7,d8;
    
    d1 = 8*60+0;
    d2 = 9*60+43;
    d3 = 11*60+19;
    d4 = 12*60+47;
    d5 = 2*60+0;
    d6 = 3*60+45;
    d7 = 7*60+0;
    d8 = 9*60+45;
    
    int hour,minutes;
    printf("Enter a 24-hour time (xx:xx): ");
    scanf("%d:%d",&hour,&minutes);
    
    int user_time = hour*60+minutes;
    
    int difference1 = d1-user_time;
    int difference2 = d2-user_time;
    int difference3 = d3-user_time;
    int difference4 = d4-user_time;
    int difference5 = d5-user_time;
    int difference6 = d6-user_time;
    int difference7 = d7-user_time;
    int difference8 = d8-user_time;
    
    int min_difference = difference1;
    
    if(min_difference<difference2){
        min_difference = difference2;
    } else if(min_difference < difference3){
        min_difference = difference3;
    } else if(min_difference < difference4){
        min_difference = difference4;
    } else if(min_difference < difference5){
        min_difference = difference5;
    } else if(min_difference < difference6){
        min_difference = difference6;
    } else if(min_difference < difference7){
        min_difference = difference7;
    } else if(min_difference < difference8){
        min_difference = difference8;
    }
    
    if(min_difference == difference1){
        printf("Closest departure time is 8:00 a.m., arriving at 10:16 a.m.\n ");
    } else if(min_difference == difference2){
        printf("Closest departure time is 9:43 a.m., arriving at 11:52 a.m.\n ");
    } else if(min_difference == difference3){
        printf("Closest departure time is 11:19 a.m., arriving at 1:31 p.m.\n ");
    } else if(min_difference == difference4){
        printf("Closest departure time is 12:47 p.m., arriving at 3:00 p.m.\n ");
    } else if(min_difference == difference5){
        printf("Closest departure time is 2:00 p.m., arriving at 4:08 p.m.\n ");
    } else if(min_difference == difference6){
        printf("Closest departure time is 3:45 p.m., arriving at 5:55 p.m.\n ");
    } else if(min_difference == difference7){
        printf("Closest departure time is 7:00 p.m., arriving at 9:20 p.m.\n ");
    } else if(min_difference == difference8){
        printf("Closest departure time is 9:45 p.m., arriving at 11:58 p.m.\n ");
    }

    return 0;
}

