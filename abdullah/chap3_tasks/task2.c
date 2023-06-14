#include <stdio.h>

int main()
{
    int item_num=0;
    float unit_price=0;
    int mm,dd,yyyy;
    
    printf("Enter the item number: ");
    scanf("%d",&item_num);
    
    printf("Enter unit price: ");
    scanf("%f",&unit_price);
    
    printf("Enter the purchase date: ");
    scanf("%d/%d/%d",&mm,&dd,&yyyy);
    
    printf("Item\tUnit\tPurchase\n");
    printf("\tPrice\tdate\n");
    printf("%d\t%f\t%d/%d/%d",item_num,unit_price,mm,dd,yyyy);
    return 0;
}
