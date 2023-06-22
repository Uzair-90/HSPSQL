#include <stdio.h>
#include <stdbool.h>

#define size 100

int contents[size];
int top = 0;

void mempty(void) {
    top = 0;
}

bool empty(void) {
    return top == 0;
}

bool full(void) {
    return top == size;
}

void push(int i) {
    if (full())
        printf("stack overflow\n");
    else
        contents[top++] = i;
}

int pop(void) {
    if (empty()) {
        printf("stack underflow\n");
        return -1; 
    } else
        return contents[--top];
}

int main() {
    char c[10];
    int i;

    printf("Enter parentheses or braces: ");
    fgets(c, sizeof(c), stdin);

    for (i = 0; c[i] != '\0'; i++) {
        if (c[i] == '(' || c[i] == '{')
            push(c[i]);
        else if ((c[i] == ')' && pop() != '(') || (c[i] == '}' && pop() != '{')) {
            printf("Mismatched parentheses or braces!\n");
            return 0;
        }
    }

    if (empty())
        printf("Balanced parentheses or braces!\n");
    else
        printf("Mismatched parentheses or braces!\n");

    return 0;
}

