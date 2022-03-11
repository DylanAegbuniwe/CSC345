/*Dylan Aegbuniwe, CSC 345, 3/12/2021, Lab 2
 atm.c */

#include <stdio.h>
#include <stdlib.h>

int pinCheck(){
   int i, inputPIN; 
   const int PIN = 3014;
  
   for(i=1; i<=3; i++){
       printf("\nPlease enter PIN to continue : ");
       scanf("%d", &inputPIN);
       if(inputPIN == PIN) return 1;
       else printf("You have entered the wrong pin. Please try again.");
   }
   if(i==4){
       printf("\nYou have entered wrong PIN for 3 times. For security, please start over and try again.\n");
       exit(0);
   }
   return 1;
}

int withdrawl(int rec, int with, int bal){
   int i, amount;
   for(i=0; i<3; i++) {
       printf("Enter amount of withdrawal. It must be a multiple of 20. ");
       scanf("%d", &amount);
       if(amount!=0 && amount%20 == 0) break;
       printf("\nPlease enter amount in multiples of $20.\n");
   }
   if(i==3){
       printf("You have entered an invalid amount 3 times. Please start over and try again.");
       exit(0);
   }
  
   if(bal < amount){
       printf("\nYou don't have enough balance to withdraw $%d", amount);
       return 0;
   }
   with += amount;
   if(with<=10000){
       if(rec==1) printf("\n\t You have successfully withdrawn $%d. The reciept is displayed.\n", amount);
       if(rec==2) printf("\n\t You have successfully withdrawn $%d.\n", amount);
   }
   return amount;
}

int deposit(int rec, int dep) {
   int i, amount;
  
   for(i=0; i<3; i++) {
       printf("Enter amount of the deposit: ");
       scanf("%d", &amount);
       if(amount!=0 && amount%5 == 0) break;
       printf("\nPlease enter amount in multiples of $5. Try again !\n");
   }
   if(i==3) {
       printf("You have entered an invalid amount 3 times. Please start over and try again.");
       exit(0);
   }
   dep+=amount;
   if(dep<=10000) {
       if(rec==1) printf("\n\tYou have successfully deposited $%d. The reciept is displayed.\n", amount);
       if(rec==2) printf("\n\tYou have successfully deposited $%d.\n", amount);
   }
   return amount;
}

int main(){
   int balance = 5000; 
   int choice;
   int transcations = 0, withdrawn = 0, deposited = 0, reciept = 0, amount=0;
  
   while(1){
       printf("Welcome to the ATM.");
       printf("\n\nMenu: \t 1. Account balance \t 2. Cash withdrawal \t 3. Cash deposit \t 4. Quit");
       printf("\nEnter choice: ");
       scanf("%d", &choice);
      
       if(choice == 4){
           printf("\n\nTotal transcations made in this session: %d \nThank you for using this bank.\n", transcations);
           break;
       }
       if(choice<1 || choice>4){
           printf("Please select a valid option.");
           continue;
       }
      
       switch(choice){  
           case 1 :
               if(pinCheck()){
                   printf("\tTotal balance: $%d \n\n", balance);
                   transcations++;
               }
               break;
          
           case 2 :
               if(pinCheck()){
                   printf("Would you like a reciept? 1. Yes   2. No");
                   scanf("%d", &reciept);
                   while (reciept < 1 || reciept > 2){
                       printf("Please enter 1 or 2 for a receipt. 1. Yes 2. No");
                       scanf("%d", &reciept);
                   }
                   if(amount = withdrawl(reciept, withdrawn, balance)){
                       withdrawn += amount;
                       if(withdrawn <= 10000){
                           balance -= amount;
                           transcations++;
                           printf("\nTotal withdrawal amount done in this session: $%d\n\n", withdrawn);
                       } else{
                           printf("Sorry, you are not allowed to withdraw more than $10000 in one day.");
                           withdrawn -= amount;
                       }
                   }
               }
               break;
              
           case 3 :
              
               if(pinCheck()) { 
                   printf("Would you like a reciept? 1. Yes   2. No ");
                   scanf("%d", &reciept);
                   while (reciept < 1 || reciept > 2){
                       printf("Please enter 1 or 2 for a receipt. 1. Yes 2. No ");
                       scanf("%d", &reciept);
                   }
                   if(amount = deposit(reciept, deposited)){
                       deposited += amount;   
                       if(deposited<=10000){ 
                           balance += amount; 
                           transcations++;
                           printf("\nTotal deposit amount made in this session: $%d\n\n", deposited);
                       } else{
                           printf("\n You are not allowed to deposit more than $10000 in one day.\n\n");
                           deposited -= amount;   
                       }
                   }
               }
               break;      
       } 
   } 
}