#include<stdio.h>

int main(){
    float e = 1;
    
    int n = 0;
    printf("Enter an integer: ");
    scanf("%d",&n);
    int temp = 1;
    
    for(int i = 1; i<= n ;i++){
        for(int j = i;j>0;j--){
             temp = temp *j;
        }
        e += (1/temp);
    }
    
    printf("The summation of the series is: %f\n",e);
}
