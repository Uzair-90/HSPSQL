#include <stdio.h>
#include <string.h>

#define MAX_REMIND 50
#define MSG_LEN 60

int read_line(char str[], int n);

int main(void) {
    char reminders[MAX_REMIND][MSG_LEN+3];
    char day_str[3], msg_str[MSG_LEN+1];
    int day, num_remind = 0, i, j;

    for (;;) {
        printf("Enter day and reminder: ");
        scanf("%2d", &day);
        
        if (day == 0)
            break;
        
        if (day < 1 || day > 31) {
            printf("Invalid day. Please enter a value between 1 and 31.\n");
            while (getchar() != '\n')
                ;
            continue;
        }
        
        sprintf(day_str, "%2d", day);
        read_line(msg_str, MSG_LEN);
        
        for (i = 0; i < num_remind; i++) {
            if (strcmp(day_str, reminders[i]) < 0)
                break;
        }
        
        for (j = num_remind; j > i; j--) {
            strcpy(reminders[j], reminders[j-1]);
        }
        
        strcpy(reminders[i], day_str);
        strcat(reminders[i], msg_str);
        
        num_remind++;
        
        if (num_remind == MAX_REMIND) {
            printf("-- No space left --\n");
            break;
        }
    }
    
    printf("\nDay Reminder\n");
    for (i = 0; i < num_remind; i++) {
        printf("%s\n", reminders[i]);
    }
    
    return 0;
}

int read_line(char str[], int n) {
    int ch, i = 0;
    
    while ((ch = getchar()) != '\n') {
        if (i < n) {
            str[i++] = ch;
        }
    }
    str[i] = '\0';
    
    return i;
}


