#include<stdio.h>
#include<string.h>

#define add(x,y) (x+y)
#define mk_str(k) #k

int main(){
    int x = 10;
    int y = 15;
    
    int z = add(x,y);
    
    char str[] = mk_str();
    
    printf("%d\n",z);
    printf("%ld",strlen(str));
    
}
