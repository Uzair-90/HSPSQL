#include <stdio.h>
#include <stdbool.h>
#include "stack.h"

int main() {
    char ch[10];
    int i;

    printf("Enter an RPN expression: ");
    scanf("%s", ch);

    for (i = 0; ch[i] != '\0'; i++) {
        if (ch[i] == '+' || ch[i] == '-' || ch[i] == '*' || ch[i] == '/' ) {
            int result;
            switch (ch[i]) {
                case '+':
                    result = pop() + pop();
                    break;
                case '-':
                    result = pop() - pop();
                    break;
                case '*':
                    result = pop() * pop();
                    break;
                case '/':
                    result = pop() / pop();
                    break;
                default:
                    printf("\n!!error!!\n");
                    return 1;
            }
            push(result);
        } 
        else if(ch[i] == '='){
        	printf("%d\n", pop());
		}
		
		else if (ch[i] >= '0' && ch[i] <= '9') {
            push(ch[i] - '0');
        }
		
    }
    
    return 0;
}
