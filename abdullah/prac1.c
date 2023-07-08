#include <stdio.h>

#define NUM_RATES ((int) sizeof(value) / sizeof(value[0]))
#define INITIAL_BALANCE 100.00
int main()
{
    int  low_rates,period_years,years;
    double value[50];
    
    printf("Enter the Interest Rate: \n");
    scanf("%d",&low_rates);
    
    printf("Enter the number of years: \n");
    scanf("%d",&years);
    
    printf("Years: \n");
    
    for(int i=0;i<NUM_RATES;i++){
        printf("%6d%%",low_rates+i);
        value[i]=INITIAL_BALANCE
    }

printf("interest\n")    


    
