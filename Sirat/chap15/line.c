#include <stdio.h>
#include <string.h>
#include "line.h"

#define MAX_LINE_LEN 60

char line[MAX_LINE_LEN+1];
int line_len=0;
int num_word=0;

void clear_line(void)
{
	line[0]='\0';
	line_len = 0;
	num_word = 0;
}

void add_word(const char*word){
	if (num_word > 0) {
	
	line[line_len]=' ';
	line[line_len+1]='\0';
	line_len++;
	}
	
	strcat(line,word);
	line_len+= strlen(word);
	num_word++;
}

int space_remaining(void){
	return MAX_LINE_LEN -line_len;
}

void write_line(void){
	int extra_space ,space_to_insert,i,j;
	
	extra_space=MAX_LINE_LEN -line_len;
	int end=0;
	for(i=0;i< line_len;i++) {
		if(line[i] !=' ')
			putchar(line[i]);
		
		else {
			space_to_insert =extra_space/(num_word-1);
			
			if(end)
			{
			
			for(j=1;j <= space_to_insert+1;j++)
				putchar(' ');
				end=0;			//larger gaps at the begining
			}
			else{
				for(j=1;j <= space_to_insert+1;j++)
				putchar(' ');
				end=1;			//larger gaps at the end
			}
			extra_space -=space_to_insert;
			num_word--;	
		}
	}
	putchar('\n');
}

void flush_line(void){
	if(line_len >0)
		puts(line);
}
