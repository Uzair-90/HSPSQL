#include <stdio.h>

int main()
{
    int month=0;
    int day=0;
    int year=0;
    printf("Enter the date like (mm/dd/yyyy): ");
    scanf("%d/%d/%d",&month,&day,&year);
    printf("you entered the date %d/%d/%d\n",year,month,day);

    return 0;
}
