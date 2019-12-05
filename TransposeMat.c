/*
Author: Getem Ratan
Date: 05-12-2019
Description: Program to print the transpose of two matrices entered by the user
Example: 1 2 3        1 4 7
         4 5 6  --->  2 5 8
         7 8 9        3 6 9
*/

#include <stdio.h>

int main(){
    int m,n,i,j;
	printf("Enter the number of rows: ");
	scanf("%d",&m);
	printf("Enter the number of columns: ");
	scanf("%d",&n);
    int a[m][n],b[m][n];

	printf("Enter the elements in the matrix: \n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}


	printf("Transpose of the matrix is: \n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			b[i][j]=a[j][i];
		}
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",b[i][j]);
		}
		printf("\n");
	}
	return 0;
}
