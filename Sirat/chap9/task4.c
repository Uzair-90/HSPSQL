#include <stdio.h>
#include <stdbool.h>


void read_word(char c[]) {
    printf("Enter the word: ");
    scanf("%s", c);
}

bool equal_array(char c1[],char c2[]){
	int i;
	int count1[26] = {0};
    int count2[26] = {0};
    
	for(i=0;c1[i]!='\0';i++){
		c1[i]=tolower(c1[i]);
		count1[c1[i] - 'a']++;
	}
	for(i=0;c2[i]!='\0';i++){
		c2[i]=tolower(c1[i]);
		count2[c2[i] - 'a']++;
	}

	for (i = 0; i < 26; i++) {
        if (count1[i] != count2[i]) {
            return false; 
        }
    }

    return true; 
}

int main() {
    char a1[26];
    char a2[26];
    bool s;

    read_word(a1);
    read_word(a2);
    
    s=equal_array(a1,a2);
    
    if(s==true)
    	printf("the word are anagrams");
    	
    else 
		printf("the words are not anagrams");	

    return 0;
}

