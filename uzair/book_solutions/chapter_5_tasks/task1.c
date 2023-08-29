#include <stdio.h>

int main()
{
    int number = 0;
    printf("Enter a number no more than four digits: ");
    scanf("%d",&number);
    
    if(number >= 0 && number < 10 ){
        printf("The number has one digit.\n");
    }
    else if (number > 9 && number < 100){
        printf("The number has two digits.\n");
    }
    else if (number > 99 && number < 1000){
        printf("The number has three digits.\n");
    }
    else if (number > 999 && number < 10000){
        printf("The number has four digits.\n");
    }
    else{
        printf("Number has digits more than five.\n");
    }

    return 0;
}

