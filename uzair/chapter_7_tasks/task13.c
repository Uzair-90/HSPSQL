#include <stdio.h>

int main() {
    float average = 0.0f;
    int count = 0;
    int divident = 1;
    char ch;
    printf("Enter a sentence: ");
    while((ch = getchar())!='\n'){
        if(ch == ' '){
            divident++;
        }else{
            count++;
        }
    }
    
    average = (float)count/(float)divident;
    printf("The average word count is: %.2f",average);
}

