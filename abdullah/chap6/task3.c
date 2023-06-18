

#include <stdio.h>

int main()
{
    int d1=0;
    int d2=0;
    int gcd=0;
    
    printf("Enter the fraction: ");
    scanf("%d/%d",&d1,&d2);
    
    int t1=d1;
    int t2=d2;
    
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
    
    t1 /= gcd;
    t2 /=gcd;
    printf("the lowest term: %d/%d\n",t1,t2);
    

    return 0;
}
