

#include <stdio.h>

int main()
{
    int number=0;
    
    printf("enter a number n: ");
    scanf("%d",&number);
    
    number /=10 ;
     for(int i=1 ; i<=number; i++){
         if(i%2==0){
             printf("%d \n",i*i);
         }
     }

    return 0;
}
