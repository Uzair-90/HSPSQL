#include<stdio.h>



int main(){
    int days;
    int months;
    int years;
    
    char *ch[]={"January","Feb","March","April","May","Jun","July","Aug","Sept","Oct","Nov","Dec"};
    printf("Enter a date(mm/dd/yyyy) : ");
    scanf( "%d/%d/%d",&months,&days, &years);
    printf("You Entered the date: %s %d %d",ch[months-1],days,years);
}
