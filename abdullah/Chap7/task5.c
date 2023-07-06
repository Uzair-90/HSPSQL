

#include <stdio.h>
#include <ctype.h> 

int main()
{
    
    
    char word;
 int number = 0;

 
 
 
 printf("Enter a word: \n");
 
 while((word=getchar()) !=  '\n') {
     switch(toupper(word)){
         
     
     
       case 'A': 
       case 'E': 
       case 'I': 
       case 'L': 
       case 'N': 
       case 'O': 
       case 'R': 
       case 'S': 
       case 'T': 
       case 'U':
       number += 1;
       break;
       
       case 'D':
       case 'G':
       number +=2;
       break;
       
       case 'B':
       case 'C':
       case 'M':
       case 'P':
       number += 3;
       break;
       
       case 'F':
       case 'H':
       case 'V': 
       case 'W': 
       case 'Y':
       number += 4;
       break;
       
       case 'K': 
       number += 5;
       break;
       
       case 'J': 
       case 'X': 
       number += 8;
       break;
            
       case 'Q': 
       case 'Z': 
       number += 10;
       break;
        }
    }

    printf("Scrabble value: %d\n\n", number);

    return 0;
}
       
       
       
       
     
 



