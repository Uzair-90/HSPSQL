
#include <stdio.h>

int main()
{
  int hours=0;
  int minutes=0;
  
  printf("Enter a 24-hour time: ");
  scanf("%d:%d",&hours,&minutes);
  
  if(hours>12){
      hours-=12;
      
  }
  
  printf("Equilent 24-hour time: %d:%d ",hours,minutes);
  
  

  
   return 0;
}
