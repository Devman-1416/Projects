// Devin Combs
//Retail Inventory


#include <iomanip>
#include <iostream>
#include <string>
#include <cmath>
#include <limits>
const int MAX = 20;

// Da Class!
class RetailItem {
	
	private:
		std::string description;
		int unitsOnHand;
		double price;
		int reorderQuantity;
	
	public:
	//Constructors
		RetailItem ()
		{
			this->description = "";
			this->unitsOnHand = 0;
			this->price = 0.00;
			this->reorderQuantity = 0;
		}
		
		RetailItem (std::string description,int unitsOnHand,double price,int reorderQuantity)
		{
			this->description = description;
			this->unitsOnHand = unitsOnHand;
			this->price = price;
			this->reorderQuantity = reorderQuantity;
		}
	
	//Accessors
		std::string getDescription() {return this->description;}
		int getUnitsOnHand() {return this->unitsOnHand;}
		double getPrice() {return this->price;}
		int getReorderQuantity() {return this->reorderQuantity;}
		
	//Mutators
		void setDescription(std::string description) {this->description=description;}
		void setUnitsOnHand(int unitsOnHand) {this->unitsOnHand=unitsOnHand;}
		void setPrice(double price) {this->price=price;}
		void setReorderQuantity(int reorderQuantity) {this->reorderQuantity=reorderQuantity;}

};



// Proto-Functions
void display(RetailItem AllItems[20]);
int getMenuChoice ();
RetailItem addItem();
int checkItem(RetailItem AllItems[20]);
void checkForReorder(RetailItem AllItems[20]);
void updateItem(RetailItem AllItems[20]);




int main() 
{	
	std::cout<<std::setprecision(2)<<std::fixed;
	RetailItem AllItems[MAX];
	bool loop = true;
	int count = 0;
	
	do {
		//Display Menu and get user choice		
		int user_choice = getMenuChoice ();
		
		//Run Function based on user choice
	    switch (user_choice) {
	        case 1:
	            // Add item
		            if (count != MAX)
					{
						AllItems[count] = addItem();
						count++;
					}
					
					else std::cout<<"\n\nInventory is Full!\n";

	            break;
	        case 2:
	        	//Display All Items
	            display(AllItems);
	            break;
	        case 3:
	            //Check Item
	            checkItem(AllItems);
	            break;
	        case 4:
	            //Display items needing reordering
	            checkForReorder(AllItems);
	            break;
	        case 5:
	            //Update item
	            updateItem(AllItems);
	            break;
	        case 6:
	        	//Exit
	            loop = false;
	            break;
	    }
					
	} while (loop);	
	
	
	return 0;
}

void display(RetailItem AllItems[20])
{
	int x=0;
	while (x < MAX && AllItems[x].getDescription() != "")
	{
		std::cout << "\nDescription: " << AllItems[x].getDescription();
		std::cout << "\nUnits on Hand: " << AllItems[x].getUnitsOnHand();
		std::cout << "\nPrice: " << AllItems[x].getPrice();
		std::cout << "\nReorder Quantity: " << AllItems[x].getReorderQuantity() << std::endl;

		x++;
	}
	
}

int getMenuChoice ()
{
	int choice;
	
	std::cout<<"\n--------------------Menu--------------------";
	std::cout<<"\n1) Add an item to inventory";
	std::cout<<"\n2) Display all items in inventory";
	std::cout<<"\n3) Check to see if an item is in inventory";
	std::cout<<"\n4) Display only those items that need to be re-ordered";
	std::cout<<"\n5) Update an item in inventory";
	std::cout<<"\n6) Exit Program";
	std::cout<<"\nEnter Choice: ";
	
	while(!(std::cin>>choice) || (choice < 1 || choice > 6))
	{
		std::cout<<"\nInvalid Menu Option! Enter a 1 - 5: ";
		std::cin.clear();
		std::cin.ignore( std::numeric_limits<std::streamsize>::max() ,'\n');
	}
	
	return choice;	
	
}

RetailItem addItem()
{
	std::cout<<"\n\n--------------Add Item---------------\n\n";
	//Variables
	std::string desc;
	int units;
	double price;
	int qty;
	
	// Item Description
	std::cout<<"Enter Item Description: ";
	std::cin.ignore(100,'\n'); // Rid of enter Key in buffer
	std::getline(std::cin,desc); // Grabs whole line in buffer, store in desc	
	
	//Units on Hand
	std::cout<<"Enter Units on Hand: ";
	while(!(std::cin>>units) || units < 0)
	{
		std::cout<<"\nInvalid Input! Enter a Number: ";
		std::cin.clear();
		std::cin.ignore( std::numeric_limits<std::streamsize>::max() ,'\n');
	}
	
	//Price
	std::cout<<"Enter Price: ";
	while(!(std::cin>>price) || price < 0)
	{
		std::cout<<"\nInvalid Input! Enter a Price: ";
		std::cin.clear();
		std::cin.ignore( std::numeric_limits<std::streamsize>::max() ,'\n');
	}
	
	//Reorder Quantity
	std::cout<<"Enter Reorder Quantity: ";
	while(!(std::cin>>qty) || qty < 0)
	{
		std::cout<<"\nInvalid Input! Enter a Reorder Quantity: ";
		std::cin.clear();
		std::cin.ignore( std::numeric_limits<std::streamsize>::max() ,'\n');
	}
	
	RetailItem item(desc,units,price,qty);
	return item;
}

int checkItem(RetailItem AllItems[20])
{
	bool found = false;
	std::string desc;	
	std::cout<<"\n\n---------------Check Item---------------";
	
	do 
	{
		//Get User Item description to compare
		std::cout<<"\nEnter Item Description: ";
		std::cin.ignore(100,'\n'); // Rid of enter Key in buffer
		std::getline(std::cin,desc); // Grabs whole line in buffer, store in desc
		
		//Compare String
		int x=0;
		while (x < MAX && AllItems[x].getDescription() != "")
		{
			if (AllItems[x].getDescription()==desc)
			{
				std::cout<<"\nItem Found in Inventory!";
				std::cout << "\nDescription: " << AllItems[x].getDescription();
				std::cout << "\nUnits on Hand: " << AllItems[x].getUnitsOnHand();
				std::cout << "\nPrice: " << AllItems[x].getPrice();
				std::cout << "\nReorder Quantity: " << AllItems[x].getReorderQuantity() << std::endl;
				return x;
				break;
			}
			
			x++;
		}
		
		if (!(found)) 
		{
			std::cout<<"\nItem Not Found!!";
			std::cout<<"\nTry Again? (0-Yes) (1-No): ";
			while(!(std::cin>>found))
			{
				std::cout<<"\nInvalid Input! (0-Yes) (1-No): ";
				std::cin.clear();
				std::cin.ignore( std::numeric_limits<std::streamsize>::max() ,'\n');
			}
		}
		
	} while (!(found));
	return 20;
	
}

void checkForReorder(RetailItem AllItems[20])
{
	int x=0;
	std::cout<<"\n\n------------------Items to be Re-Ordered--------------------";
	while (x < MAX && AllItems[x].getDescription() != "")
	{
		if (AllItems[x].getReorderQuantity() >= AllItems[x].getUnitsOnHand())
		{
			std::cout << "\nDescription: " << AllItems[x].getDescription();
			std::cout << "\nUnits on Hand: " << AllItems[x].getUnitsOnHand();
			std::cout << "\nPrice: " << AllItems[x].getPrice();
			std::cout << "\nReorder Quantity: " << AllItems[x].getReorderQuantity() << std::endl;
		}
		x++;
	}
}

void updateItem(RetailItem AllItems[20])
{
	int x;
	
	//Get Index in array for desired Item to update
	// If No Item was found to Update and User Didnt want to try again
	if (x = checkItem(AllItems) == 20) return;

	//Update the Item
	std::cout<<"\n\n--------------Update Item---------------\n\n";
	//Variables
	int units;
	double price;
	int qty;
	
	//Units on Hand
	std::cout<<"Enter Units on Hand: ";
	while(!(std::cin>>units) || units < 0)
	{
		std::cout<<"\nInvalid Input! Enter a Number: ";
		std::cin.clear();
		std::cin.ignore( std::numeric_limits<std::streamsize>::max() ,'\n');
	}
	AllItems[x].setUnitsOnHand(units);
	
	//Price
	std::cout<<"Enter Price: ";
	while(!(std::cin>>price) || price < 0)
	{
		std::cout<<"\nInvalid Input! Enter a Price: ";
		std::cin.clear();
		std::cin.ignore( std::numeric_limits<std::streamsize>::max() ,'\n');
	}
	AllItems[x].setPrice(price);
	
	//Reorder Quantity
	std::cout<<"Enter Reorder Quantity: ";
	while(!(std::cin>>qty) || qty < 0)
	{
		std::cout<<"\nInvalid Input! Enter a Reorder Quantity: ";
		std::cin.clear();
		std::cin.ignore( std::numeric_limits<std::streamsize>::max() ,'\n');
	}
	AllItems[x].setReorderQuantity(qty);
	
}

