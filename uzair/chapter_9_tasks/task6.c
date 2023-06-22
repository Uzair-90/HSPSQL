#include<stdio.h>

int power(int base,int exponent){
    if(exponent == 0){
        return 1;
    }
    else{
        return base*power(base,exponent-1);
    }
}

int calculate_function(int x){
    return 3*power(x,5)+2*power(x,4)-5*power(x,3)-power(x,2)+7*x-6;
}

int main(){
    int x = 0;
    printf("Enter the value of x: ");
    scanf("%d",&x);
    
    printf("The value of the function is: %d\n",calculate_function(x));
    return 0;
}
