
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


#define stacksize 100

char stack[stacksize];
int top =0;

int stack_overflow(void){
    printf("stack overflow\n");
    return 0;
    
}
int stack_underflow(void){
    printf(" stack_underflow\n");
    return 0;
}

void make_empty(void)
{
    top = 0;
}


bool empty(void){
    return top==0;
}

bool full(void){
     return top==stacksize;
}


void push(char i)
{
    if (full())
        stack_overflow();
    else
        stack[top++] = i;
}


char pop(void)
{
    if (empty())
        stack_underflow();
    else
        return stack[--top];
}
int main()
{
    char ch;
      printf("Enter parentheses and/or braces\n: ");
    while ((ch = getchar()) != '\n') {

        if (ch == '{' || ch == '(') {
            push(ch);
        } else if (ch == '}' && pop() != '{') {
            printf("Parentheses not nested properly\n.");
            break;
        } else if (ch == ')' && pop() != '(') {
            printf("Parentheses not nested properly\n.");
            break;
        }
    }

    if (empty())
        printf("All parentheses and braces are matched: \n");
    else
        printf("Parentheses and braces are not matched");

    
    return 0;
}
