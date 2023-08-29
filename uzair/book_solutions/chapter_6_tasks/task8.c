#include <stdio.h>

int main()
{

  int starting_day = 1;
  int n_days;
  printf("Enter the number of day in month: ");
  scanf("%d",&n_days);
  printf("Enter starting day of the week (Sun =1, Sat = 7): ");
  scanf("%d",&starting_day);
  
  for (int j =1; j < starting_day; j++)
      printf("  ");

  for(int i = 1; i <= n_days; i++){
      
      if(i%7 == 0){
          printf("\n");
      }
      printf("%5d",i);
  }
  
}

