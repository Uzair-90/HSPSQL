#include <stdio.h>

int sum(int (*f)(int), int start, int end)
{
    int sum = 0;
    while (start <= end) 
    {
        sum += (*f)(start);
        start++;
    }
    return sum;
}

int square(int i)
{
    return i * i;
}

int cube(int i)
{
    return i * i * i;
}

int main()
{
    printf("sum: %d\n", sum(square, 1, 10));
    printf("sum: %d\n", sum(cube, 7, 11));
    
    return 0;
}
