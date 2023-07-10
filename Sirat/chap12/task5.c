#include <stdio.h>
#include <string.h>

int main() {
    char s[30],a;
    int i=0,j;
    char *f;
    char *e;
    char *wf=0,*we;

    printf("Enter a message: ");
    while ((a= getchar()) != '\n' && i < 30) {
        s[i] = a;
        i++;
    }
    s[i]='\0';
	f=s;
	e=s+i-1;   

   
    while (f < e) {
        char t = *f;
        *f = *e;
        *e = t;
        f++;
        e--;
        }
     
	wf=s;    
    f=s;    

  	while (*f!='\0'){
  	if (*f==' '){
  		we=f-1;
  			
		while (wf < we) {
        char t = *wf;
        *wf = *we;
        *we = t;
        wf++;
        we--;
        }		
  		wf=f+1;		  			
	  }
	  	f++;
	  }

    
    printf("Reversal of sentence: %s\n", s);

    return 0;
}
