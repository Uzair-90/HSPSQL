#include<stdio.h>

#define func_call() printf("%s called...\n",__func__);
#define func_termination() printf("%s terminated...\n",__func__);

void dummy(){
    func_call();
    printf("How are you doing?\n");
    func_termination();
}

int main(){
    dummy();
}
