#include<stdio.h>

int main(){
    int input= 1;
    int max=1;
    
    
    
    
    while(input>0){
        printf("Enter a number: ");
        scanf("%d",&input);
    }
    
    if(input>max){
        max=input;
    }
    printf("The largest number entered by user is : %d \n",max);   
    return 0;
}
