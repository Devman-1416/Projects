// Devin Combs
// Credit Card

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>
#include <limits>
#include <stdlib.h>     
#include <time.h>       

class AccountHolder
{
	private:
		std::string name;
		std::string address;
		std::string city;
		std::string state;
		std::string zip;
		int creditScore;
		long int ss;
		
	public:
		AccountHolder(std::string name, std::string address, std::string city, std::string state, std::string zip, long int ss)
			: name(name), address(address), city(city), state(state), zip(zip), ss(ss) {;}
		
		int getCreditScore()
		{
			return creditScore = rand() % (850 - 300 + 1) + 300;
		}
		
		void displayAccount()
		{
			std::cout<<"\nName: " + name + "\tAddress: " + address + "\n"; 
		}
};
 // End AccountHolder

class Transaction
{
	private:
		std::string date;
		std::string desc;
		double amount;
		
	public:
		Transaction () {;}
		
		double getAmount() {return amount;}
		
		void inputTransaction()
		{
			std::string date, desc;
			double amount;
			std::cin.clear();
		    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			
			
			std::cout<<"\nEnter Date: ";
			std::getline(std::cin, this->date);
			std::cout<<"\nEnter Description: ";
			std::getline(std::cin, this->desc);
			
			std::cout<<"\nEnter Amount: ";
		    while (!(std::cin >> this->amount) || this->amount < 0) {
		        std::cout << "\nInvalid amount! Must be real number! ";
		        std::cin.clear();
		        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		    }
		    
			
		}
		
		void displayTransaction()
		{
			std::cout<<"\n\nDate: " + date + "\t   Description: " + desc + "\t     Amount: $" + std::to_string(amount)<<std::endl;
		}
	
}; // End Transaction

class CreditCard
{
	private:
		long int accountNum;
		int creditScore;
		AccountHolder holder;
		double creditLimit;
		double balance;
		double intrest;
		std::vector<Transaction> allTransaction;
		static int newAccountNumber;
		
		void determineLimitAndInterest()
		{
			if (creditScore > 799)
			{
				creditLimit = 20000;
				intrest = .085;
			}
			else if (creditScore > 739)
			{
				creditLimit = 15000;
				intrest = .155;
			}
			else if (creditScore > 669)
			{
				creditLimit = 10000;
				intrest = .225;
			}
			else
			{
				creditLimit = 5000;
				intrest = .295;
			}
		}
		
	public:
	
		CreditCard(std::string name, std::string address, std::string city, 
				   std::string state, std::string zip, long int ss) :
				   holder(name, address, city, state, zip, ss) 
			{
				if ((creditScore =holder.getCreditScore()) < 580)
				{
					std::cout<<"\nDenied Credit!!!! ";
					accountNum = 0;
				}
				else
				{
					std::cout<<"\nYou Been Approved!!!";
					accountNum = newAccountNumber;
					newAccountNumber++;
					determineLimitAndInterest();
				}
				
				std::cout<<"\n\nAcount Number #"<<accountNum;
				balance = 0;
					
			}
				
		long int getAccountNumber() {return accountNum;}
		
		void addTransaction(Transaction transaction)
		{
			if (transaction.getAmount() < (creditLimit - balance))
			{
				allTransaction.push_back(transaction);
				balance += transaction.getAmount();
				std::cout<<"\n\nTransaction Added!"<<std::endl;
			}
			else
			{
				std::cout<<"\n\nTransaction Denied!!"<<std::endl;
			}
		}
					
		void display()
		{
			std::cout<<"\n\n------------Account Number #"<<accountNum<<"------------"
				<<"\n\nCurrent Balance: $"<<balance
				<<"\n\nAvailable Credit: $"<<creditLimit - balance<<std::endl;
		}
		
		void printStatment ()
		{
			std::cout<<"\n\nAccount Number #"<<accountNum
				<<"\n\n--------Transactions------\n";
			holder.displayAccount();
			for (Transaction t : allTransaction)
			{
				t.displayTransaction();
			}
			
			std::cout<<"\nTotal Intrest $"<<(balance * intrest);
			std::cout<<"\nTotal Balance $"<<(balance + (balance * intrest))<<std::endl;
			
			
			
		}

	
}; // End CreditCard

int CreditCard::newAccountNumber = 100200;

//proto
int displayMenu();
CreditCard createAccount();
void displayAccount(std::vector<CreditCard> allCards);
void inputTransaction(std::vector<CreditCard> &allCards);
void printStatments(std::vector<CreditCard> allCards);

// Main

int main() 
{
	std::vector<CreditCard> allCards;
	srand(time(0));
	std::cout << std::fixed << std::setprecision(2);
	
	int choice,cardCount=0;
	
	while (true) 
	   {
	
		    switch (choice=displayMenu()) {
		        case 1:
		        	allCards.push_back(createAccount());
		        	cardCount++;
		            break;
		
		        case 2:
					displayAccount(allCards);
		            break;
		
		        case 3:
					inputTransaction(allCards);
		            break;
		
		        case 4:
					printStatments(allCards);
		            break;
		
				case 0:
					exit(0);
					break;
		
			}
	    }
	
	

	return 0;
}




// Functions


int displayMenu()
{
		int choice;
        std::cout << "\n--------------------- Menu ------------------------\n";
        std::cout << "\nPlease choose from the following menu\n";
        std::cout << "1: Create an account and apply for a credit card\n";
        std::cout << "2: See the balance and available credit for an existing account\n";
        std::cout << "3: Input a transaction\n";
        std::cout << "4: Print all monthly statments\n";
        std::cout << "0: Exit program \n\n\tEnter: ";

        while (!(std::cin >> choice) || (choice < 0 || choice > 4)) {
            std::cout << "\nInvalid Menu Option! Enter a 0 - 4: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return choice;
}


CreditCard createAccount()
{
	std::string name, address, city, state, zip;
	long int ss;

	std::cout << "\nName: ";
	std::getline(std::cin, name);
	std::cout << "\nAddress: ";
	std::getline(std::cin, address);
	std::cout << "\nCity: ";
	std::getline(std::cin, city);
	std::cout << "\nState: ";
	std::getline(std::cin, state);
	std::cout << "\nZip: ";
	std::getline(std::cin, zip); 

	std::cout << "\nSSN: ";
	while (!(std::cin >> ss)) {
		std::cout << "\nInvalid SSN! Try again: ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 

	CreditCard newCard(name, address, city, state, zip, ss);
	return newCard;
}


void displayAccount(std::vector<CreditCard> allCards)
{
	long int num;
	bool found = false;
	std::cout<<"\n\nEnter Account Number: ";

	while (!(std::cin >> num)) {
		std::cout << "\nInvalid Account Number! Try again: ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	
	for (CreditCard card : allCards)
	{
		if (card.getAccountNumber() == num)
		{
			found = true;
			card.display();
			return;
		}
	}
	
	if (!(found)) std::cout<<"\n\nNo Account Found!";
	
}


void inputTransaction(std::vector<CreditCard> &allCards)
{
	long int num;
	bool found = false;
	std::cout<<"\n\nEnter Account Number: ";

	while (!(std::cin >> num)) {
		std::cout << "\nInvalid Account Number! Try again: ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	
	for (CreditCard &card : allCards)
	{
		if (card.getAccountNumber() == num)
		{
			found = true;
			Transaction transaction;
			transaction.inputTransaction();
			card.addTransaction(transaction);
			return;
		}
	}
	
	if (!(found)) std::cout<<"\n\nNo Account Found!";	
	
}

void printStatments(std::vector<CreditCard> allCards)
{
	for (CreditCard &card : allCards)
	{
		card.printStatment();
	}
}
