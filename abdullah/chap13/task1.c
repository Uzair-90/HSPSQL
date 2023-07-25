
#include <string.h>
#include <stdio.h>

#define len 20

char smallest_word[len+1];
char largest_word[len+1];
char current_word[len+1];

int main()
{

printf("Enter word: ");
fgets(current_word,len,stdin);

strcpy(smallest_word,current_word);
strcpy(largest_word,current_word);


while(strlen(current_word)!=5){
    printf("Enter word: ");
    fgets(current_word,len,stdin);
    
    
    if(strcmp(largest_word,current_word)<0){
        strcpy(largest_word,current_word);
    }
    
    if(strcmp(smallest_word,current_word)>0){
        strcpy(smallest_word,current_word);
    }
    
}

    printf("Smallest word: %s\n",smallest_word);
    printf("largest word: %s\n",largest_word);




    return 0;
}
