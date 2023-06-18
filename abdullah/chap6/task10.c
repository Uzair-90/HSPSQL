

#include <stdio.h>
int main()
{
    int m2=1;
    int d2=1;
    int y2=1;
    
    int m1 = 12;
    int d1 = 30;
    int y1 = 23;
    
    while(m2 != 0 && d2 != 0 && y2 != 0){
        printf("Enter the date of Birth (mm/dd/yyyy): ");
        scanf("%d/%d/%d",&m2,&d2,&y2);
        
        if(m2 == 0 && d2 == 0 && y2 == 0){
            break;
        }
        
        
    if(d1 < d2 && m1==m2 && y1 == y2){
        continue;
    } else if (d1 > d2 && m1==m2 && y1 == y2){
        m1 = m2;
        d1 = d2;
        y1 = y2;
    } else if (d1 == d2 && m1<m2 && y1 == y2){
       continue;
    } else if (d1 == d2 && m1>m2 && y1 == y2){
       continue;
    } else if (d1 == d2 && m1==m2 && y1 > y2){
         m1 = m2;
        d1 = d2;
        y1 = y2;
    } else if (d1 == d2 && m1==m2 && y1 < y2){
       continue;
    } else if (d1 < d2 && m1 < m2 && y1 < y2){
        continue;
    } else if (d1 > d2 && m1 > m2 && y1 > y2 ){
        m1 = m2;
        d1 = d2;
        y1 = y2;
    } else if (d1 < d2 && m1 > m2 && y1 < y2){
        continue;
    } else if (d1 > d2 && m1 < m2 && y1 > y2){
         m1 = m2;
        d1 = d2;
        y1 = y2;
    } else if (d1 > d2 && m1 < m2 && y1 == y2){
       continue;   
    } else if (d1 < d2 && m1 > m2 && y1 == y2){
        m1 = m2;
        d1 = d2;
        y1 = y2;
    } else if (d1 < d2 && m1 < m2 && y1 == y2){
        continue;
    } else if (d1 > d2 && m1 > m2 && y1 == y2){
         m1 = m2;
        d1 = d2;
        y1 = y2;
    } else if (d1 < d2 && m1 < m2 && y1 > y2){
        m1 = m2;
        d1 = d2;
        y1 = y2;
    }
        
    }

    printf("The earliest date is: %d/%d/%d\n",m1,d1,y1);
    
    return 0;
}
