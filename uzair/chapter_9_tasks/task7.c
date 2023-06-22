#include <stdio.h>

int power(int base, int exponent) {
    if (exponent == 0) {
        return 1;
    }
    else if (exponent % 2 == 0) {
        int temp = power(base, exponent/2);
        return temp * temp;
    }
    else {
        return base * power(base, exponent - 1);
    }
}

int main() {
    int base = 0;
    printf("Enter the value of base: ");
    scanf("%d", &base);
    
    int exponent = 0;
    printf("Enter the value of exponent: ");
    scanf("%d", &exponent);
    
    int result = power(base, exponent);
    
    printf("The value of the power is: %d\n", result);
    
    return 0;
}

