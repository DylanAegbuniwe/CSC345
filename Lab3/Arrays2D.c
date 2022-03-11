/*Dylan Aegbuniwe, CSC 345, 3/29/2021, Lab 3
 Arrays2D.c */

#include<stdio.h>

//Calculating the sum of each row
int rowSum(int arr[][20], int x, int y, int rowNum){
	int i, sum = 0;
	for(i = 0; i < y; i++)
	{
		sum = sum + arr[rowNum][i];
	}

	return sum;
}

//Calculating the sum of each column
int columnSum(int arr[][20], int x, int y, int colNum){
	int i, sum = 0;
	for(i = 0; i < x; i++)
	{
		sum = sum + arr[i][colNum];
	}

	return sum;
}

//Square Array Checker
void isSquare(int x, int y){
	if(x == y)
		printf("\nThis is a square array.");
	else
		printf("\nThis is not a square array.");
}

//Array Display
void displayOutputs(int arr[][20], int x, int y){
	int i, j;
	for(i = 0; i < x; i++)
	{
		printf("[");
		for(j = 0; j < y; j++)
		{
			printf("%d", arr[i][j]);
			if(j != y-1)
				printf(", ");
		}
		printf("]\n");
	}
}

//Main method calling the functions and printing them
int main(){
	int arr[20][20], x, y, i, j;

	printf("Let's create a 2Dim array!\n\n");
	
	printf("\tHow many rows? ");
	scanf("%d", &x);
	printf("\tHow many columns? ");
	scanf("%d", &y);

	printf("\n");
	for(i = 0; i < x; i++)
	{
		for(j = 0; j < y; j++)
		{
			printf("\tenter [%d][%d]: ", i, j);
			scanf("%d", &arr[i][j]);
		}
	}

	for(i = 0; i < x; i++)
	{
		printf("\nSum of row %d = %d", i+1, rowSum(arr, x, y, i));
	}

	printf("\n");
	for(i = 0; i < y; i++)
	{
		printf("\nSum of column %d = %d", i+1, columnSum(arr, x, y, i));
	}

	printf("\n");
	isSquare(x, y);

	printf("\n\nHere is your 2Dim array:\n");
	displayOutputs(arr, x, y);
}