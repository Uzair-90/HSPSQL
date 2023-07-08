#include<stdio.h>
#include<stdbool.h>

int main(){
    int digits[10]={0};
    
    int num = 0;
    printf("Enter a number: ");
    scanf("%d",&num);
    int i = 0;
    int temp=0;
    
    
    while(num > 0){
        temp = num%10;
        digits[temp]++;
        num/=10;
    }
    for(int i=0 ; i<10;i++)
    printf("%d\t",i);
    
    printf("\n");
    
    for(int i=0; i<10; i++)
    printf("%d\t",digits[i]);
    
    printf("\n");
    return 0;
}
