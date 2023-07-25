#include <stdio.h>

int main() 
{
    for (int i = 9348; i > 0; i /= 10)
        printf("%d\n", i);

    return 0;
}