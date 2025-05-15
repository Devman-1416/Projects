//Devin Combs - #2
//Brenden Bourgoise? #4
//Landon Will - #3
//Peleke Kelly #1

#include <stdio.h>
float inputDeposit(float balance);
float inputWithdrawal(float balance);
void displayBalance(float balance);
char displayMenu();
int main()
{
	float balance;
	char userChoice;
  userChoice=displayMenu();
  while(userChoice!='q' && userChoice!='Q')
  {
    switch(userChoice)
    {
        case'D':case'd':
        	balance=inputDeposit(balance);
        	break;
        case'W':case'w':
        	balance=inputWithdrawal(balance);
        	break;
        case'B':case'b':
        	displayBalance(balance);
        	break;
        case'Q':case'q':
        	break;
    }
    userChoice=displayMenu();
  }
  printf("Thank you!");

	return 0;
}

char displayMenu()
{
  char userChoice;
  printf("Welcome to HFC Federal Credit Union!\n");
  printf("\nPlease select from the following menu: ");
  printf("\nD: Make a deposit");
  printf("\nW: make a withdrawal");
  printf("\nB: Check your account balance");
  printf("\nQ: To quit");
  scanf("\n%c", &userChoice);
  while(userChoice != 'Q' && userChoice != 'q' && userChoice != 'D' && userChoice != 'd' && userChoice != 'W' && userChoice != 'w' && userChoice != 'B' && userChoice != 'b')
  {
    printf("Invalid option");
    scanf("\n%c", &userChoice);
  }
  return userChoice;
}

float inputDeposit(float balance)
{
 float deposit;
 printf ("\nWhat amount would you like to deposit: ");
 scanf("%f",&deposit);
 
 while (deposit<=0) {
 	printf("\n Invalid Amount: Please Try again");  
 	printf ("\nWhat amount would you like to deposit: ");
 	scanf("%f",&deposit);
 }
  
 balance+=deposit;
 return balance;
  
}

void displayBalance(float balance)
{
  printf("\nYour current balance is: $%.2f",balance);
}

float inputWithdrawal(float balance)
{
  float withdrawalAmount;
  printf("\nWhat amount would you like to withdrawal: $");
  scanf("%f", &withdrawalAmount);
  
  while(withdrawalAmount < 0 || (balance - withdrawalAmount) < 0)
  {
    if (withdrawalAmount < 0)
    {
      printf("\nInvalid Amount! Please enter an amount greater than $0!");
      printf("\nWhat amount would you like to withdrawal: $");
      scanf("%f", &withdrawalAmount);
    }
    else if (balance < 0)
    {
      printf("\nInvalid Balance! Balance cannot be lower than $0!");
      printf("\nWhat amount would you like to withdrawal: $");
      scanf("%f", &withdrawalAmount);
    }
  }
  balance -= withdrawalAmount;
  return balance; 
}
