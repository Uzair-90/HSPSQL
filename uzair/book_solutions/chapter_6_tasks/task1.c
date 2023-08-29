#include <stdio.h>

int main()
{
    float max =1;
    float user_input = 1;
    
    while(user_input>0){
        printf("Enter a number: ");
        scanf("%f",&user_input);
        
        if(user_input>max){
            max = user_input;
        }
    }
    
    printf("The largest number entered was: %f\n",max);
    return 0;
}

