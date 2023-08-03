#include <stdio.h>

struct time {
    int d;
    int a;
};

int main() {
    struct time t1[] = {
        {8 * 60, 10 * 60 + 16}, {9 * 60 + 43, 11 * 60 + 52},
        {11 * 60 + 19, 13 * 60 + 31}, {12 * 60 + 47, 15 * 60},
        {14 * 60, 16 * 60 + 8}, {15 * 60 + 45, 17 * 60 + 55},
        {19 * 60, 21 * 60 + 20}, {21 * 60 + 45, 23 * 60 + 58}
    };

    int h, m;

    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &h, &m);

    int t = h * 60 + m;

    int i, departure = 0;

    for (i = 1; i < 8; i++) {
         if (abs(t1[i].d - t) < abs(t1[departure].d - t)){
            departure = i;
        }
    }

    int time = t1[departure].d;
    int hour = time / 60;
    int minute = time % 60;
    int atime = t1[departure].a;
    int ahour = atime / 60;
    int aminute = atime % 60;

    printf("Closest departure time is %02d:%02d, arriving at %02d:%02d\n", hour, minute, ahour, aminute);

    return 0;
}

