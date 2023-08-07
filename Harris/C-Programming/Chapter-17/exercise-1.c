#include <stdio.h>
#include <stdlib.h>

void *malloc_(int b)
{
    void *pointer;

    if ((pointer = malloc(b)) == NULL) 
    {
        printf("Error, malloc failed.\n");
        exit(EXIT_FAILURE);
    }

    return pointer;
}

int main()
{
    char *pointer = malloc_(10);
    
    return 0;
}