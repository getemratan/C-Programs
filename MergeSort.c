/*
Author: Getem Ratan
Date: 07-12-2019
Description: Merge Sorting using recursive function
Example: 4 2 6 1
         1 2 4 6
*/

#include <stdio.h>
/* Function to compare and sort the array */
void Mergesort(int arr[], int beg, int end){
    int i, j;
    for(i=beg;i<end-1;i++){
        for(j=i+1;j<end;j++){
            if(arr[i] > arr[j]){
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}
/* Function to split the array until only 2 elements
are left in the array */
void Split(int arr[], int beg, int end){
    if((beg + 1) < end){
        int mid = (beg + end) / 2;
        Split(arr, beg, mid);
        Split(arr, mid + 1, end);
    }

    Mergesort(arr, beg, end);
}

int main(){
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements in the array: \n");
    int i;
    for(i=0;i<size;i++){
        scanf("%d", &arr[i]);
    }

    Split(arr, 0, size);

    printf("Sorted array is: \n");
    for(i=0;i<size;i++){
        printf("%d\n", arr[i]);
    }
}
