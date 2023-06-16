#include <stdio.h>

int main()
{
    int i,n,o,s;
    
    printf("This program prints a table of squares.\n");
    printf("Enter number of entries in table: ");
    scanf("%d", &n);
    
    i=1;
    o=3;
    s=1;
    
    for(i=1;i<=n;i++){
        printf("%10d%10d\n",i,s);
        s+=o;
        o+=2;
    }
    
    return 0;
}


