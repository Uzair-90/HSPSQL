
#include <stdio.h>

int main()
{
   int first_part,middle_part,last_part;
   
   printf("Enter Your Phone Number as (xxxx) xxxx-xxxx: ");
   scanf("(%d) %d-%d",&first_part,&middle_part,&last_part);
   printf("You entered %d.%d.%d",first_part,middle_part,last_part);   

    return 0;
}
