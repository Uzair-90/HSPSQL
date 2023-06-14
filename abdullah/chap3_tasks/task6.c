#include <stdio.h>

int main()
{
    int num1,denom1,num2,denum2,result_num,result_denom;

    printf("Enter the fraction numbers both at once with a plus sign: ");
    scanf("%d/%d+%d/%d",&num1,&denom1,&num2,&denum2);

    result_num = num1*denum2+num2*denom1;
    result_denom = denom1*denum2;

    printf("The result of the fraction is: %d/%d",result_num,result_denom);

    return 0;
}

