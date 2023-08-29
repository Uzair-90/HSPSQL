#include <stdio.h>

int fact(int n){
    
    if (n == 1){
        return 1;
    }
    else{
        return n*fact(n-1);
    }
}

int power(int base, int exponent){
    if(exponent == 0){
        return 1;
    }
    else{
        return base*power(base,exponent-1);
    }
}

int sum_array(int a[], int n){
    int temp_sum = 1;
    
    for(int i = 0; i < n; i++){
        temp_sum+=a[i];
    }
    
    return temp_sum;
}



int main()
{
    int sum = sum_array((int []) {1, 2, 3, 4, 5, 6, 7, 8, 9}, 9);

    printf("The sum of the array is: %d\n",sum);
    
    //recursion for factorial
    
    int factorial = fact(9);
    printf("The factorial of 9 is: %d\n",factorial);
    
    //recursion for calculating power
    
    int get_power = power(5,5);
    
    printf("The power of 5 to 5 is: %d\n",get_power);

    return 0;
}

