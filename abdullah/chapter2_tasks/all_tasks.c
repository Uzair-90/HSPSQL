//this is programme number #1

#include <stdio.h>

int main()
{
    printf("        *\n");
    printf("       *\n");
    printf("  *   *\n");
    printf("   * *\n");
    printf("    *\n");
    
    return 0;
}

//this is program number #2

#include <stdio.h>

#define r 10
#define pi 3.14

int main()
{
    float v = (3.0f/4.0f)*pi*r*r*r;
    printf("The volume is: %f\n",v);
    
}


//this is programme number #3


#include <stdio.h>


#define pi 3.14

int main()
{
    float r = 0;
    
    printf("Enter the valuer of r: ");
    scanf("%f",&r);
    
    float v = (3.0f/4.0f)*pi*r*r*r;
    printf("The volume is: %f\n",v);
    
}

//this is program number #4

#include <stdio.h>


#define tax 0.05

int main()
{
    float amount = 0;
    printf("Enter the amount in dollars and cents: ");
    scanf("%f",&amount);
    float amount_with_tax = amount + (amount*tax);
    printf("The amount with tax is: %f\n", amount_with_tax);
    return 0;
    
}

//this is programme number #5

#include <stdio.h>

int main()
{
    float x = 0;
    printf("Enter the value of x: ");
    scanf("%f",&x);
    float result = 3*(x*x*x*x*x)+2*(x*x*x*x)-5*(x*x*x)-(x*x)+7*x-6;
    printf("The result is: %f\n",result);
    return 0;
    
}


//thsis is programme number #8

#include <stdio.h>

int main()
{
    float total_amount = 0;
    float interest_rate = 0;
    float updated_amount = 0;
    float monthly_payment = 0;
    
    printf("Enter the total amount: ");
    scanf("%f",&total_amount);
    
    printf("Enter the interest rate: ");
    scanf("%f",&interest_rate);
    
    printf("Enter the monthly payment: ");
    scanf("%f",&monthly_payment);
    
    updated_amount = total_amount + (total_amount*(interest_rate/100));
    
    printf("Remaining amount after 1st payment: %f\n",updated_amount-monthly_payment);
    updated_amount-=monthly_payment;
    
    printf("Remaining amount after 2nd payment: %f\n",updated_amount-monthly_payment);
    updated_amount-=monthly_payment;
    
    printf("Remaining amount after 3rd payment: %f\n",updated_amount-monthly_payment);
    updated_amount-=monthly_payment;
    
    return 0;
    
}

