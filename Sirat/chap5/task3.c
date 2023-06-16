#include <stdio.h>

int main() {
    int s;
    float p,v,c,rc;

    printf("Enter the number of shares: ");
    scanf("%d",&s);
    printf("Enter the price per share: ");
    scanf("%f",&p);

    v=s*p;

    if (v<2500.00f)
        c=30.00f+0.017f*v;
    else if (v<6250.00f)
        c=56.00f+0.0066f*v;
    else if (v<20000.00f)
        c=76.00f+0.0034f*v;
    else if (v<50000.00f)
        c=100.00f+0.0022f*v;
    else if (v<500000.00f)
        c=155.00f+0.0011f*v;
    else
        c=255.00f+0.0009f*v;

    if (c<39.00f)
        c=39.00f;

    if (s<2000)
        rc=33.00f+0.03f*s;
    else
        rc=33.00f+0.02f*s;

    printf("Commission: $%.2f\n", c);
    printf("Rival Commission: $%.2f\n",rc);

    return 0;
}

