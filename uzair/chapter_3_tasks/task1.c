#include <stdio.h>

int main()
{
    int dd,mm,yyyy;
    printf("Enter a date (dd/mm/yyyy): ");
    scanf("%d/%d/%d",&dd,&mm,&yyyy);
    printf("You entered date: %d/%d/%d\n",yyyy,mm,dd);

    return 0;
}

