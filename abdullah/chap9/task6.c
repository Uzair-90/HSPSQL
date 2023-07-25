#include<stdio.h>



long polynomial(int x){
    return 3*x*x*x*x*x+2*x*x*x*x-5*x*x*x-x*x+7*x-6;
}


int main(){
    int x = 3;
    
    printf("%ld",polynomial(x));
    
    return 0;
}
