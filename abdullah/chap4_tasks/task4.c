#include <stdio.h>

int main()
{
  int number=0;
  printf("enter a five digit number: ");
  scanf("%5d",&number);
  
  int d1=number%8;
  number /=8;
  
   int d2=number%8;
  number /=8;
  
   int d3=number%8;
  number /=8;
  
   int d4=number%8;
  number /=8;
  
   int d5=number%8;
  number /=8;
  
  printf("In octal your number is: %d%d%d%d%d\n",d5,d4,d3,d2,d1);
  
   return 0;
}
 
 
 
