#include<stdio.h>
#include<stdlib.h>

int main(){
	float price,total;
	int quantity; 
	printf("Welcome to \"Temple\" Store\n\n");
	printf("\tEnter item price: ");
	scanf("%f", &price);
	if(price<=0){
		printf("\n\n");
		printf("\tThis is not a valid item price.\n");	
		printf("\tPlease run the program again\n\n");
		printf("Thank you for using \"Temple\"store\n");
		exit(0);
	}
	printf("\tEnter quantity: ");
	scanf("%d", &quantity);
	if(quantity<=0){
		printf("\n\n");
		printf("\tThis is not a valid quantity order.\n");	
		printf("\tPlease run the program again\n\n");
		printf("Thank you for using \"Temple\"store\n");
		exit(0);
	}
	printf("\n\n");
	printf("\tThe item price is: $%.1f\n", price);
	printf("\tThe order is: %d item(s)\n", quantity);
	printf("\tThe cost is: $%.1f\n", price*quantity);
	if(quantity>=1 && quantity<=49){
		printf("\tThe discount is: 0.0%\n", price*quantity);
		printf("\tThe discount is: $%.1f\n", 0*quantity);
		printf("\tThe total is: $%.1f\n", price*quantity);
		printf("\n\n");	
	}
	else
	if(quantity>=50 && quantity<=99){
		total = (price*quantity) - (price*quantity*0.10);
		printf("\tThe discount is: 10.0%\n", price*quantity);
		printf("\tThe discount is: $%.1f\n", 0.10*quantity*price);
		printf("\tThe total is: $%.1f\n", total);
		printf("\n\n");	
	}
	else
	if(quantity>=100 && quantity<=149){
		total = (price*quantity) - (price*quantity*0.15);
		printf("\tThe discount is: 15.0%\n", price*quantity);
		printf("\tThe discount is: $%.1f\n", 0.15*quantity*price);
		printf("\tThe total is: $%.1f\n", total);
		printf("\n\n");	
	}
	else
	if(quantity>=150){
		total = (price*quantity) - (price*quantity*0.25);
		printf("\tThe discount is: 25.0%\n", price*quantity);
		printf("\tThe discount is: $%.1f\n", 0.25*quantity*price);
		printf("\tThe total is: $%.1f\n", total);
		printf("\n\n");	
	}
	printf("Thank you for using \"Temple\"store\n");
	
}