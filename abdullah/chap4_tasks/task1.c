#include <stdio.h>

int main()
{
   int number = 0;
   printf("Enter a two digit number: ");
   scanf("%2d",&number);
   
   int first_part = number/10;
   int second_part = number%10;
   
   printf("The reverse of the number is: %d%d\n",second_part,first_part);
   
   return 0;
}

