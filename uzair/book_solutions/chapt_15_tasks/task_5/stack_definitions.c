#include <stdbool.h>
#include<stdio.h>


#define size 100

int contents[size];
int top = 0;

void empty(void) {
    top = 0;
}

bool isempty(void) {
    return top == 0;
}

bool isfull(void) {
    return top == size;
}

void push(int i) {
    if (isfull())
        printf("Stack overflow\n");
    else
        contents[top++] = i;
}

int pop(void) {
    if (isempty()) {
        printf("Stack underflow\n");
        return -1;
    } else {
        return contents[--top];
    }
}
