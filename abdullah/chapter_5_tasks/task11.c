

#include <stdio.h>

int main()
{
    int number=0;
    
    printf("Enter a two digit number: ");
    scanf("%2d", &number);
    
    int first_part=number/10;
    int second_part=number%10;
    
    switch(number){
        case 11:
        printf("Eleven \n");
        break;
        
        case 12:
        printf("Twelve \n");
        break;
        
           case 13:
        printf("Thirteen \n");
        break;
        
           case 14:
        printf("fourteen \n");
        break;
        
           case 15:
        printf("fifteen \n");
        break;
        
           case 16:
        printf("Twelve \n");
        break;
        
           case 17:
        printf("seventeen \n");
        break;
        
           case 18:
        printf("eighteen \n");
        break;
        
           case 19:
        printf("ninteen \n");
        break;
    }
    
     if(number<=10 || number>=20){
    switch(first_part){
        case 0:
        printf("Zero-");
        break;
        case 2:
        printf("Twenty-");
        break;
        case 3:
        printf("Thirty-");
        break;
        case 4:
        printf("Fourty-");
        break;
        case 5:
        printf("Fifty-");
        break;
        case 6:
        printf("Sixty-");
        break;
        case 7:
        printf("Seventy-");
        break;
        case 8:
        printf("Eighty-");
        break;
        case 9:
        printf("Ninety-");
        break;
    }
    
    switch(second_part){
        case 0:
        printf("Zero");
        break;
        case 1:
        printf("one");
        break;
        case 2:
        printf("two");
        break;
        case 3:
        printf("three");
        break;
        case 4:
        printf("Four");
        break;
        case 5:
        printf("Five");
        break;
        case 6:
        printf("Six");
        break;
        case 7:
        printf("Seven");
        break;
        case 8:
        printf("Eight");
        break;
        case 9:
        printf("Nine");
        break;
    }
    }
    
   

    return 0;
}

