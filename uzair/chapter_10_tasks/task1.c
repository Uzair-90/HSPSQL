#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

int top = -1;
char stack[MAX_SIZE];

void push(char ch) {
    if (top >= MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    
    stack[++top] = ch;
}

char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return '\0';
    }
    
    return stack[top--];
}

bool isMatchingPair(char opening, char closing) {
    if (opening == '(' && closing == ')')
        return true;
    else if (opening == '{' && closing == '}')
        return true;
    else if (opening == '[' && closing == ']')
        return true;
    else
        return false;
}

bool isBalanced(char expression[]) {
    for (int i = 0; expression[i] != '\0'; i++) {
        if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[')
            push(expression[i]);
        else if (expression[i] == ')' || expression[i] == '}' || expression[i] == ']') {
            if (top == -1 || !isMatchingPair(pop(), expression[i]))
                return false;
        }
    }
    
    return (top == -1);
}

int main() {
    char expression[MAX_SIZE];
    
    printf("Enter an expression: ");
    scanf("%s", expression);
    
    if (isBalanced(expression))
        printf("Parentheses are used correctly.\n");
    else
        printf("Parentheses are not used correctly.\n");
    
    return 0;
}

