#include<stdio.h>

int main(){
    char *months[] = {"January","Feb","March","April","May","Jun","July","Aug","Sept","Nov","Dec"};
    int month,day,year;
    
    printf("Enter a date (mm/dd/yyyy): ");
    scanf("%d/%d/%d",&month,&day,&year);
    
    printf("You entered the date: %s %d, %d",months[month-1],day,year);
}
