#include <stdbool.h>
#include <stdio.h>

#define N 10
int main()
{
     bool digit_seen[N] = {false};  //initilazing array and =false
    int digit = 0;
    int seen_digits[5];

    long n = 0;
    printf("Enter a number: ");
    scanf("%ld", &n);

    int i = 0;

    while (n > 0) {
        digit = n % 10;

        if (digit_seen[digit]) {
            seen_digits[i] = digit;
            i++;
            if (i == 5) {
                break;
            }
        }

        digit_seen[digit] = true;
        n /= 10;
    }

    if (i > 0) {
        printf("Repeated digits: ");
        for (int j = 0; j < i; j++) {
            printf("%d ", seen_digits[j]);
        }
        printf("\n");
    } else {
        printf("No repeated digits.\n");
    }

    return 0;
}
       
       
       
       
     
 



