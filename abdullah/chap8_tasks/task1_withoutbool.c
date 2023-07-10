
#include <stdbool.h>
#include <stdio.h>

int main()
{
    int digits[10];
    int num = 0;
    printf("Enter a number: ");
    scanf("%d",&num);
    
    
    for(int i = 0; i < 10; i++){
        digits[i] = num%10;
        num /= 10;
    }
    
    int test[10] = {0,1,2,3,4,5,6,7,8,9};
    
    int count = 0;
    
    for(int i = 0; i < 10; i++){
        count = 0;
            for(int j = 0; j < 10; j++){
                if(test[j] == digits[i]){
                    count++;
                    if(count>1){
                        printf("Repeated Digits.\n");
                    }
                }
            }
    }
    
    return 0;
}
       
       
       
       
     
 



