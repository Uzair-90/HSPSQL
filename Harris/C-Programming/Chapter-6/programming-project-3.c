#include <stdio.h>

int main()
{
    int numer, denom, m;
    
    printf("Enter a fraction: ");
    scanf("%d/%d", &numer, &denom);
    m = numer;
    for (int r , n = denom; n > 0;)
    {
        r = m % n;
        m = n;
        n = r;
    }
    
    printf("The fraction in simplest form is: %d/%d", numer / m, denom / m);

    return 0;
}