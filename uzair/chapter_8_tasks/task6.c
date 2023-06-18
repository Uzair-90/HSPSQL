
#include <stdio.h>
#include <stdbool.h>
#include<ctype.h>

#define N 200

int main() {

    char message[N];

    printf("Enter your message: ");
    for(int i = 0; i < N; i++){
        scanf("%c",&message[i]);
        if(message[i] == '\n'){
            break;
        }
    }
    
    for(int i = 0; i < N; i++){
        message[i] = toupper(message[i]);
    }
    
    
    for(int i = 0; i < N; i++){
        if(message[i] == 'A'){
            message[i] = '4';
        }
        else if(message[i] == 'B'){
            message[i] = '8';
        }
        else if(message[i] == 'E'){
            message[i] = '3';
        }
        else if(message[i] == 'L'){
            message[i] = '1';
        }
        else if(message[i] == 'S'){
            message[i] = '5';
        }
        else if(message[i] == 'O'){
            message[i] == '0';
        }
    }
    
    

    for(int i = 0; i < N; i++){
        printf("%c",message[i]);
    }
    
    printf("!!!!!\n");


    return 0;
}



