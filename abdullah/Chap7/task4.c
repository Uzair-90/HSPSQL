

#include <stdio.h>

int main()
{
 int number = 0;
 int ch;
 
 
 
 printf("Enter the Alphabetic Numbers: \n");
 
 while((ch=getchar()) !=  '\n') {
     ch = toupper(ch);
     
     
     if(ch>='A' && ch<= 'Z'){
        if(ch>='A' && ch<= 'C')
         number=2;
        else if (ch >= 'D' && ch <= 'F')
         number = 3;
        else if(ch >= 'G' && ch <= 'I')
		number = 4;
	    else if (ch >='J' && ch <= 'L')
		number = 5;
	    else if (ch >= 'M' && ch <= 'O')
		number = 6;
	    else if (ch >='P' && ch <= 'R')
		number  = 7;
	    else if (ch >= 'S' && ch <= 'V')
		number = 8;
	    else if (ch >= 'W' && ch <= 'Z')
		number = 9;

            printf("%d ", number);
     }
 }
 
 

    return 0;
}

