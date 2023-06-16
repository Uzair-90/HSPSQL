
#include <stdio.h>

int main()
{
 int speed=0;
 
 printf("Enter the speed wind: ");
 scanf("%d",&speed);
 
 if(speed<1)
{
    printf("calm \n");
}
 else if (speed>=1 && speed<=3){
     printf("Light Air \n");
 }
 else if (speed>=4 && speed<=27){
     printf("Breeze \n");
 }
 else if (speed>=28 && speed<=47){
     printf("Gale \n");
     
 }
 else if (speed>=48 && speed<=63){
     printf("storm \n");
 }
  else{
      printf("Hurican \n");
  }
  

  
   return 0;
}
