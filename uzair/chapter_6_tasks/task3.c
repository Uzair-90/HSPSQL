#include <stdio.h>

int main()
{
    
    int num1,num2,gcd;
    
    printf("Enter the fraction: ");
    scanf("%d/%d",&num1,&num2);
    
    int temp1 = num1;
    int temp2 = num2;
    
    if(num1 < num2){
        int temp = num1;
        num1 = num2;
        num2 = temp;
    }
    
    for (int i = 1; i <= num1; ++i){
        if(num1%i==0 && num2%i == 0){
            gcd = i;
        }
    }
    
    temp1 /= gcd;
    temp2 /= gcd;
    
    printf("The reduced fraction is: %d/%d\n",temp1,temp2);
    
    return 0;
}

