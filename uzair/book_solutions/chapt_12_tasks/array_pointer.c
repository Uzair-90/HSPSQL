#include <stdio.h>

int main()
{
    int m = 3;
    int n = 4;

    int a[m][n];

    int *p = &a[0][0];


    for (int i = 0; i < m * n; i++)
    {
        *(p + i) = (i / n) * n + i % n;
    }
    
    p = &a[0][0];
    
    for (int i =0; i < m*n; i++){
        printf("%d\t",*(p+i));
    }

    return 0;
}

//this programme just illustrates that how to access a two dimensional array using only one for loop with pointers
