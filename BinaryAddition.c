/*
Author: Getem Ratan
Date: 08-12-2019
Description: Program to add two binary numbers
Example:  101
        +1101
        10010
*/

#include <stdio.h>
/* Funtion to add two binary numbers */
void add(int bin1, int bin2){
    int carry = 0;
    int x, y, sum = 0;
    int arr[50];
    int i = 0;

    while(bin1 != 0 || bin2 != 0){
        x = bin1 % 10;
        y = bin2 % 10;
        if(x == 1 && y == 1){
            sum = (sum * 10) + carry;
            carry = 0;
            carry++;
        }
        else if(carry == 1 && (x + y) == 1){
            sum = (sum * 10);
            carry = 0;
            carry++;
        }
        else{
            sum = (sum * 10) + (x + y) + carry;
            carry = 0;
        }
        i++;
        bin1 = bin1 / 10;
        bin2 = bin2 / 10;
    }
    if(carry == 1){
        arr[i] = 1;
    }
    int size = i;

    printf("Binary Sum is: ");
    for(i=size;i>=0;i--){
        printf("%d", arr[i]);
    }
}

int main(){
    /* Enter two binary numbers to add */
    int bin1, bin2;
    printf("Enter two binary numbers to add: \n");
    scanf("%d %d", &bin1, &bin2);

    add(bin1, bin2);
}
