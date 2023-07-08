#include<stdio.h>
#include<ctype.h>


int main()
{
    char ch,words[100]={0};
    int i=0;
    int len=0;
    
    printf("Enter Message : \n");
  // while(ch!='\n'){
       // scanf("%c",&words[i]);
       // words[i] = ch;
      //  i++;
      //  break;
   // }
   
    for (len = 0; (words[len] = toupper(getchar())) != '\n'; len++)
    printf("IN B1ff speak: \n");
    for ( int i=0;i<len;i++){
 
        switch(words[i]){
            case 'A': putchar('4');
            break;
            case 'B': putchar('8');
            break;
            case 'E':putchar('3');
            break;
            case 'I':putchar('1');
            break;
            case 'O':putchar('0');
            break;
            case 'S':putchar('5');
            break;
            default: putchar(words[i]);
            break;
        }
        
    }
    printf("!!!!!!!!!!");
    return 0;
}
