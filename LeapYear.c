/*
Author: Getem Ratan
Date: 05-12-2019
Description: Program to find leap year
Example: 2004 is a leap year
*/

#include <stdio.h>

int main(){
    int year;
    printf("Enter a year to check if it is a leap year or not: ");
    scanf("%d",&year);

    /* Every 100 year is not a leap year and leap year comes in gap of 4 years  */
    if(((year%4==0) && (year%100!=0)) || ((year%4==0) && (year%100==0) && (year%400==0)))
    {
      printf("%d is a leap year",year);
    }
    else
     printf("%d is not a leap year",year);
}
