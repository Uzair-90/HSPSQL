/* Computer dimensionsal weigth of the 
*  box through input provided by the user*/

#include <stdio.h>
#define INCHES_PER_POUND 166

int main(void) 
{
    int length = 0, width = 0, height = 0, volume = 27;

    printf("Enter length of the box: ");
    scanf("%d", &length);
    printf("Enter width of the box: ");
    scanf("%d", &width);
    printf("Enter heigth of the box: ");
    scanf("%d", &height);
    volume = length * width * height;

    printf("Volume of the box is %d\n", volume);
    printf("Dimensional weight: %d", ((volume + (INCHES_PER_POUND - 1)) / INCHES_PER_POUND));
    
    return 0;
}