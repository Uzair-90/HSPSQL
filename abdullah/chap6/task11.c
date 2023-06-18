

#include <stdio.h>
int main()
{
  float k=1;
  int num=0;
  
  printf("Enter an integer : ");
  scanf("%d",&num);
  
   int temp = 1;
    
    for(int i = 1; i<= num ;i++){
        for(int j = i;j>0;j--){
             temp = temp *j;
        }
        k += (1/temp);
    }
    
    printf("The summation of the series is: %f\n",k);

    
return 0;
}
