
#include <stdio.h>

int main()
{
  int number=0;
  
  printf("Enter a number less than 4 digits: ");
  scanf("%d",&number);
  
    if(number>0 && number<10) {
     printf("The Number is one digit \n");
}
    else if (number>9 && number<99){
     printf("The Number is two digit \n");

}   
    else if (number>99 && number<1000){
     printf("The Number is three digit \n");
  
}  
    else if (number>9999 && number<10000){
     printf("the number is four digit number: \n");
  
}    
   
    

  
   return 0;
}
