#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char phone[16];
    char ch;
    int index = 0;
    int i;
    
    printf("Enter phone number: ");
    
    while ((ch = getchar()) != '\n' && index < 15)
    {
        ch = toupper(ch);
        
        if (isalpha(ch))
        {
            if (ch >= 'A' && ch <= 'C')
                phone[index] = '2';
            else if (ch >= 'D' && ch <= 'F')
                phone[index] = '3';
            else if (ch >= 'G' && ch <= 'I')
                phone[index] = '4';
            else if (ch >= 'J' && ch <= 'L')
                phone[index] = '5';
            else if (ch >= 'M' && ch <= 'O')
                phone[index] = '6';
            else if (ch >= 'P' && ch <= 'S')
                phone[index] = '7';
            else if (ch >= 'T' && ch <= 'V')
                phone[index] = '8';
            else if (ch >= 'W' && ch <= 'Z')
                phone[index] = '9';
        }
        else
        {
            phone[index] = ch;
        }
        
        index++;
    }
    
    printf("In numeric form: ");
    for (i = 0; i < index; i++)
    {
        printf("%c", phone[i]);
    }
    
    
    return 0;
}

