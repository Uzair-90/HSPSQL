#include<stdio.h>
#include<string.h>

#define max_len 20

int main(){
    char smallest_word[max_len+1];
    char largest_word[max_len+1];
    char current_word[max_len+1];
    
    printf("Enter a word: ");
    fgets(current_word,20,stdin);
    
    strcpy(smallest_word,current_word);
    strcpy(largest_word,current_word);
    
    while(strlen(current_word)!=5){
        printf("Enter a word: ");
        fgets(current_word,20,stdin);
        
        if(strcmp(smallest_word,current_word)>0){
            strcpy(smallest_word,largest_word);
        } else if(strcmp(largest_word,current_word)<0){
            strcpy(largest_word,current_word);
        }
    }
    
    printf("Smallest word: %s",smallest_word);
    printf("Largest word: %s",largest_word);
}

