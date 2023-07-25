#include <stdio.h>

int main(void) 
{
    int bills_20 = 0, bills_10 = 0, bills_5 = 0, bills_1 = 0, amount = 0;

    printf("Enter amount: ");
    scanf("%d", &amount);
    bills_20 = amount / 20;
    amount = amount - bills_20 * 20; 
    bills_10 = amount / 10;
    amount = amount - bills_10 * 10;
    bills_5 = amount / 5;
    bills_1 = amount - bills_5 * 5;    // reamining bills (i.e less than 5) count as bills of 1
    
    printf("$20 bills: %d\n", bills_20);
    printf("$10 bills: %d\n", bills_10);
    printf("$5 bills: %d\n", bills_5);
    printf("$1 bills: %d\n", bills_1);

    return 0;
}