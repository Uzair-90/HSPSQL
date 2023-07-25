#include <stdio.h>

int main()
{
    float loan, interest_rate, monthly_payment, balance;

    printf("Enter amount of loan: ");
    scanf("%f", &loan);
    printf("Enter interest rate: ");
    scanf("%f", &interest_rate);
    printf("Enter monthly payment: ");
    scanf("%f", &monthly_payment);
    
    interest_rate = (interest_rate / 100.0) / 12.0;

    balance = (loan - monthly_payment) * (1 + interest_rate);
    printf("Balance remaining after first payment: %.3f\n", balance);

    balance = (balance - monthly_payment) * (1 + interest_rate);
    printf("Balance remaining after second payment: %.3f\n", balance);

    balance = (balance - monthly_payment) * (1 + interest_rate);
    printf("Balance remaining after third payment: %.3f\n", balance);
        
    return 0;
}