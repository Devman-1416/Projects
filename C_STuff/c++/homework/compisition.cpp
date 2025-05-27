// Devin Combs
// 5/22/2025


#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

class Person {
	private:
		std::string firstName;
		std::string lastName;
		
	public:
		Person(std::string firstName, std::string lastName)
		{
			this->firstName = firstName;
			this->lastName = lastName;
		}
		
		std::string display ()
		{
			return firstName + " " + lastName;
		}
	
}; //end Person

class InventoryItem{
	private:
		int stockNum;
		double price;
		
	public:
		InventoryItem(int stockNum, double price)
		{
			this->stockNum = stockNum;
			this->price = price;
		}
		
		void display()
		{
			std::cout<<"Stock Number: "<<stockNum<<"\nPrice: $"<<price;
		}
};//end Inventory Item


class Transaction {
	private:
		int transNum;
		//composition is using classes in class
		Person seller; // Object
		InventoryItem itemSold; // Object
		
	public:
		Transaction(int tN, std::string fN, std::string lN, int sN, double price):
			seller(fN,lN), itemSold(sN,price) //Since using Class in Class
												//Initizaing List
		{	
			this->transNum = tN;
		}
		
		void display()
		{
			std::cout<<"Name: "<<seller.display()<<std::endl;
			itemSold.display();
			std::cout<<std::endl;
			std::cout<<"Transaction Number: "<<this->transNum;
		}
		
		//void setTransNum(int tn):transNum(tn){}
		
		//void setTransNum(int tn)
		//{
		//	transNum = tn;
		//}
};

int main() {
	
	//int x(5);
	//std::cout<<x;
	
	//Person onePerson ("Carl","Jung");
	
	//std::cout<<onePerson.display()<<std::endl;
	
	InventoryItem oneItem (12345, 12.00);
	
	//oneItem.display();
	std::cout<<"\n"<<std::endl;
	Transaction oneTrans(1,"Patrick","Star", 714, 1.99);
	oneTrans.display();
	
	return 0;
}
