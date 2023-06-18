#include <stdio.h>

int main(void)
{
    int item_no, date, month, year;
    float unit_price;

    printf("Enter item number: ");
    scanf("%d", &item_no);
    printf("Enter unit price: ");
    scanf("%f", &unit_price);
    printf("Enter purhase date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &month, &date, &year);

    printf("\nItem\t\tUnit\t\tPurchase\n\t\tPrice\t\tDate\n%d\t\t$%.2f\t\t%.2d/%.2d/%.4d", item_no, unit_price, month, date, year);

    return 0;
}