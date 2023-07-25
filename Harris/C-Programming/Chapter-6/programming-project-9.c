#include <stdio.h>

int main()
{
    float loan, interest_rate, monthly_payment, balance;
    int number_payments;

    printf("Enter amount of loan: ");
    scanf("%f", &loan);
    printf("Enter interest rate: ");
    scanf("%f", &interest_rate);
    printf("Number of monthly payments: ");
    scanf("%d", &number_payments);
    printf("Enter monthly payment: ");
    scanf("%f", &monthly_payment);
    
    interest_rate = (interest_rate / 100.0) / 12.0;

    for (int i = 0; i < number_payments; i++)
    {
        loan = (loan - monthly_payment) * (1 + interest_rate);
        printf("Balance remaining after first payment: %.3f\n", loan);
    }
       
    return 0;
}