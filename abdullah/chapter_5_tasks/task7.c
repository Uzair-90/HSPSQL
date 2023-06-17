
#include <stdio.h>

int main()
{
    
 int d1,d2,d3,d4;
 
 printf("Enter 4 numbers: ");
 scanf("%d%d%d%d",&d1,&d2,&d3,&d4);
 
 int minimum=d1;
 int maximum=d1;
 
 if(minimum>d2){
     minimum=d2;
 }
 else if (maximum<d2){
     maximum=d2;
 }
 
if(minimum>d3){
     minimum=d3;
 }
 else if (maximum<d3){
     maximum=d3;
 }
 
if(minimum>d4){
     minimum=d4;
 }
 else if (maximum<d4){
     maximum=d4;
 }
 
 printf("minimum:%d, maximum:%d \n",minimum,maximum);
