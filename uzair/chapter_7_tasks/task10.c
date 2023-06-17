#include<stdio.h>

int main(){
    char ch;
    int count = 0;
    printf("Enter a sentence: ");
    while((ch = getchar())!='\n'){
        if(ch == 65 || ch == 97 || ch == 69 || ch == 101 ||ch == 105 || ch == 73 ||ch == 111 || ch == 79 ||ch == 117 || ch == 85){
            count++;            
        }
    }
    
    printf("The number of vowels in your sentence is: %d\n",count);
}
