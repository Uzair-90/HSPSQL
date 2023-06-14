#include <stdio.h>

int main()
{
    int i1,i2,i3,i4,i5,i6,i7,i8,i9,i10,i11;
    printf("Enter the 11 digit number to find check digit: ");
    scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d",&i1,&i2,&i3,&i4,&i5,&i6,&i7,&i8,&i9,&i10,&i11);
    
    int first_sum = i1+i3+i5+i7+i9+i11;
    int second_sum = i2+i4+i6+i8+i10;
    
    int total_sum = (3*first_sum)+second_sum;
    
    int check_digit = 9 - ((total_sum -1)%10);
    
    printf("Check digit is: %d\n",check_digit);

    return 0;
}

