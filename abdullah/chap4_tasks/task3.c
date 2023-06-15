#include <stdio.h>

int main()
{
   int number = 0;
   printf("Enter a three digit number: ");
   scanf("%3d",&number);
   
   int first_part = number/100;
   int temp = number%100;
   int second_part=temp/10;
   int third_part=temp%10;
   
   printf("The reverse of the number is: %d%d%d\n",third_part,second_part,first_part);
   
   return 0;
}
 
 
 

