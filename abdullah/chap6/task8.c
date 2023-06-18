

#include <stdio.h>

int main()
{
    int days=0;
    int months=0;
    
    printf("Enter number of days in month :");
    scanf("%d",&days);
    
    printf("Enter starting days of month :");
    scanf("%d",&months);
    
    for (int k=1; k<=months; k++)
        printf(" ");
        
    for(int i=1; i<=days; i++){
        if(i%7==0){
            printf("\n");
        }
        
        printf("%5d",i);
        
    }
    return 0;
}
