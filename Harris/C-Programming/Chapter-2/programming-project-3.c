#include <stdio.h>
#define FRACTION 4.0f/3.0f
#define PI 3.1415926

int main(void) 
{
    int radius = 0;
    float volume = 0.0f;

    printf("Enter radius: ");
    scanf("%d", &radius);
    volume = FRACTION * PI * (radius * radius * radius);

    printf("The volume is: %.2f\n", volume);

    return 0;
}