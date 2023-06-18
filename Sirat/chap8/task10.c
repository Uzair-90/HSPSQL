#include <stdio.h>

int main() {
    int h, m;

    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &h, &m);

    int t = h * 60 + m;
    int d[] = {8 * 60, 9 * 60 + 43, 11 * 60 + 19, 12 * 60 + 47, 14 * 60, 15 * 60 + 45, 19 * 60, 21 * 60 + 45};
    int a[] = {10 * 60 + 16, 11 * 60 + 52, 13 * 60 + 31, 15 * 60, 16 * 60 + 8, 17 * 60 + 55, 21 * 60 + 20, 23 * 60 + 58};
    int i,departure = 0;

    for (i = 1; i < 8; i++) {
        if ((d[i] - t) < (d[departure] - t)) {
            departure = i;
        }
    }

    int time = d[departure];
    int hour = time / 60;
    int minute = time % 60;
    int atime = a[departure];
    int ahour = atime / 60;
    int aminute = atime % 60;

    printf("Closest departure time is %02d:%02d, arriving at %02d:%02d\n", hour,minute,ahour,aminute);

    return 0;
}

