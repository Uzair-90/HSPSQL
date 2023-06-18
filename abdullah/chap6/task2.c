

#include <stdio.h>

int main()
{
    int d1=0;
    int d2=0;
    int gcd=0;
    
    printf("Enter two integrs: ");
    scanf("%d%d",&d1,&d2);
    
    if(d1 < d2){
        int t = d1;
        d1 = d2;
        d2 = t;
    }
    
    for (int i = 1; i <= d1; ++i){
        if(d1%i==0 && d2%i == 0){
            gcd = i;
        }
    }
    
    printf("GREATEST COMMON DIVISOR: %d\n",gcd);
    

    return 0;
}
