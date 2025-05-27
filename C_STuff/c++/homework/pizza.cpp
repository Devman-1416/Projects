// Devin Combs
// Pizza


#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

class Pizza {
	
	private:
		std::string type;
		std::string size;
		int numToppings;
		
		
	public:
		//Constructor
		Pizza ()
		{
			this->type = "";
			this->size = "";
			this->numToppings = 0;
		}
		
		Pizza (std::string type, std::string size ,int numToppings)
		{
			this->type = type;
			this->size = size;
			this->numToppings = numToppings;
		}
		//Accesors
		std::string getType() {return this->type;}
		std::string getSize() {return this->size;}
		int getNumToppings() {return this->numToppings;}
		
		//Mutators
		void setType(std::string type) {this->type = type;}
		void setSize(std::string size) {this->size = size;}
		void setNumToppings(int numToppings) {this->numToppings = numToppings;}
		
		float calcTotal ()
		{
			if (this->size=="small") return 10 + (2 * this->numToppings);
			else if (this->size=="medium") return 14 + (2 * this->numToppings);
			else return 17 + (2 * this->numToppings);
		}
		
	
		void displayPizza ()
		{
			std::cout<<"\nType: "<<this->type;
			std::cout<<"\nSize: "<<this->size;
			std::cout<<"\nTotal Toppings: "<<this->numToppings;	
			std::cout<<"\nPizza Total: $"<<calcTotal();
		}
}; //End Pizza

class Order {
	private:
		std::string name;
		std::string phone;
		std::vector<Pizza> allPizzas;
		double total;
		int count;
				
	public:
		//Constructor
		Order ()
		{
			this->name = "";
			this->phone = "";
			this->total = 0;
			this->count = 0;
		}
		
		Order (std::string name, std::string phone)
		{
			this->name = name;
			this->phone = phone;
			this->total = 0;
			this->count = 0;
		}
		
		
		
		//Add Pizza
		
		void addPizza(std::string type, std::string size ,int numToppings)
		{
			Pizza newPizza (type,size,numToppings);
		
			this->allPizzas.push_back(newPizza);
			
			this->allPizzas[count].displayPizza();
			this->count++;
		}
		
		// Display Order
		
		void displayOrder()
		{
			std::cout<<"\n--------------Order----------------\n";
			
			for (int x = 0; x < this->allPizzas.size(); x++)
			{
				
				std::cout<<"\nPizza "<<x+1;
				this->allPizzas.at(x).displayPizza();
				std::cout<<"\nPizza Total: $"<<this->allPizzas[x].calcTotal(); 
				total += this->allPizzas[x].calcTotal();
				std::cout<<"\n";
			}
			
			std::cout<<"\n\nNumber of Pizzas: "<<count;
			std::cout<<"\n Final Total: $"<<total<<std::endl;
			
		}
		
		
}; // End Order









int main() {
	
	bool add = true;
	std::string pizzaType;
	std::string pizzaSize;
	int toppings;
	Order order;
	
	std::cout<<"-------------------Han's Pizzeria---------------------";
	
	while (add)
	{	
	
		std::cin.clear();
		std::cin.ignore( std::numeric_limits<std::streamsize>::max() ,'\n');
	    // Get Pizza Type
	    std::cout << "\n\nNew Pizza:";
	    std::cout << "\n\n Pick a Type: Deep Dish, Hand tossed, Pan\n: ";
	    std::getline(std::cin, pizzaType);
	    std::transform(pizzaType.begin(), pizzaType.end(), pizzaType.begin(), ::tolower);
	
	    while (pizzaType != "deep dish" && pizzaType != "hand tossed" && pizzaType != "pan") {
	        std::cout << "\n Not a Valid Pizza Type! Try Again: ";
	        std::getline(std::cin, pizzaType);
	        std::transform(pizzaType.begin(), pizzaType.end(), pizzaType.begin(), ::tolower);
	    }
	
	    // Get Pizza Size
	    std::cout << "\n\n Pick a Size: Small, Medium, Large\n: ";
	    std::getline(std::cin, pizzaSize);
	    std::transform(pizzaSize.begin(), pizzaSize.end(), pizzaSize.begin(), ::tolower);
	
	    while (pizzaSize != "small" && pizzaSize != "medium" && pizzaSize != "large") {
	        std::cout << "\n Not a Valid Pizza Size! Try Again: ";
	        std::getline(std::cin, pizzaSize);
	        std::transform(pizzaSize.begin(), pizzaSize.end(), pizzaSize.begin(), ::tolower);
	    }
	
		//Get Toppings	
		std::cout<<"\nHow many toppings: ";
		while(!(std::cin>>toppings) || toppings < 0)
		{
			std::cout<<"\n\nInvalid amount of toppings, must be 0 or more!";
			std::cout<<"\nHow many toppings: ";
			
			std::cin.clear();
			std::cin.ignore( std::numeric_limits<std::streamsize>::max() ,'\n');
		}
		
		
		order.addPizza(pizzaType,pizzaSize,toppings);
		
		//Add another Pizza?
		std::cout<<"\n\nAdd another Pizza? 1= Yes  0= No: ";
		while(!(std::cin>>add) && add != 1 && add != 0)
		{
			std::cout<<"\n\nInvalid response! 1= Yes  0= No: ";
			std::cin.clear();
			std::cin.ignore( std::numeric_limits<std::streamsize>::max() ,'\n');
		}
			
	}
	
	
	
	
	order.displayOrder();
	
	
	return 0;
}
