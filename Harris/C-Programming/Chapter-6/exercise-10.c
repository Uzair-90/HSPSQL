#include <stdio.h>

int main()

{
    for (int i = 0; i < 10; ++i)
    {
        if (i == 5)
        {
            goto number;
        }
        printf("%d\n", i);
    }
    number:
    
    return 0;
}