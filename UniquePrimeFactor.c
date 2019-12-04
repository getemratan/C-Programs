/*
Author: Getem Ratan
Date: xx-xx-2019
Description: Program to sort a list of numbers provided by the user depending on the total number of
their unique prime factor
Example: a: 4, 15
         4: 2*2
         15: 3*5
         a: 15, 4
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 50
/* function to return the total number of unique prime factors  */
int uniq(int num){
	int count = 1;
	int arr[MAX];      /* array holding the prime factors of num */
	int ite = 0;

	int i;
	/* calculating if '2' is the prime factor for the given number or not */
	while(num%2 == 0){
		arr[ite] = 2;
		ite++;
		num = num / 2;
	}
	/* dividing the given number with prime numbers other than 2 */
	for(i=3;i<=num;i=i+2){
		while(num%i == 0){
			arr[ite] = i;
			ite++;
			num = num / i;
		}
	}

	int size = ite;
	if(size == 1){
		return 1;
	}
	else{
		for(ite=0;ite<size-1;ite++){
			if(arr[ite] != arr[ite+1]){
			count++;
			}
		}
		return count;
	}
}

int main(){
    int s;
	printf("Enter the size: ");
	scanf("%d", &s);

    int *arr1 = (int *)malloc(s * sizeof(int));

    printf("Enter the elements: \n");
    int i;
    for(i=0;i<s;i++){
        int temp;
        scanf("%d", &temp);
        if(temp == 1){
            printf("1 is neither prime nor a composite number. Please re-enter the value!!\n");
            scanf("%d", &temp);
            arr1[i] = temp;
        }
        arr1[i] = temp;
    }

    int arr2[s];    /* array for holding the number of unique prime factors */
    int result = 0;
    for(i=0;i<s;i++){
        result = uniq(arr1[i]);
        arr2[i] = result;
    }

    /* sorting the arrays */
    for(i=0;i<s;i++){
        if(arr2[i] > arr2[i+1]){
            int temp;

            temp = arr2[i+1];
            arr2[i+1] = arr2[i];
            arr2[i] = temp;

            temp = arr1[i+1];
            arr1[i+1] = arr1[i];
            arr1[i] = temp;
        }
    }

    printf("Sorted according to unique prime factors: \n");
    for(i=0;i<s;i++){
        printf("%d\t%d\n", arr1[i], arr2[i]);
    }
}
