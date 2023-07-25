#include <stdio.h>

int main() 
{
    int n = 4;
    if (n % 2 == 0) // removal of ; as it created a null statement after the if condition, making the next statement run regardless of the outcome of the expression.
        printf("n is even\n");
    
    return 0;
}