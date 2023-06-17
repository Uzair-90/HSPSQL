

#include <stdio.h>

int main()
{
    int grade =0;
    
    printf("Enter numerical grade: ");
    scanf("%d",&grade);
    
    if(grade>100 || grade<0){
        printf("ERROR. \n");
    }
    
    int num=0;
    
    if(grade<=100 || grade>0){
        
    }
    
    num=grade/10;
    
    switch(num){
    
    case 0:
    printf("F \n");
    break;
    
    case 1:
    printf("F \n");
    break;
    
    case 2:
    printf("F \n");
    break;
    
    case 3:
    printf("F \n");
    break;
    
    case 4:
    printf("F \n");
    break;
    
    case 5:
    printf("F \n");
    break;
    
    
    case 6:
    printf("D \n");
    break;
    
    
    case 7:
    printf("C \n");
    break;
    
    case 8:
    printf("B \n");
    break;
    
    case 9:
    printf("B+ \n");
    break;
    
    case 10:
    printf("A \n");
    break;
    
}
    return 0;
}
