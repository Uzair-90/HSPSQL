#include <stdio.h>


int main()
{
    int  num =0;
    char ch;
    
    printf("Enter the Sentence: ");
    
   while((ch = getchar())!='\n'){
       if(ch=='a' || ch=='e'|| ch=='o' || ch=='i' ||ch=='u')
       num++;
       
       
   }
 printf("The number of vowels in your sentence is: %d\n",num);

    return 0;
}
       
       
