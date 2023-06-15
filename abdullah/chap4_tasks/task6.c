#include <stdio.h>

int main()
{
  int s1,s2,s3,s4,s5,s6,s7,s8,s9,s10,s11,s12;
  printf("Enter a twelve digit-number: ");
  scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d",&s1,&s2,&s3,&s4,&s5,&s6,&s7,&s8,&s9,&s10,&s11,&s12);
  
  
  int first_sum=s1+s3+s5+s7+s9+s11;
  int sec_sum = s2+s4+s6+s8+s10+s12;
   
  int total= first_sum+ sec_sum;
  
  int check_digit= 9 - (total-1)%10;
  
  printf("Your check digit is: %d\n",check_digit);
   return 0;
}
 
 
 
