// Devin Combs
//5/28/2025



#include <iomanip>
#include <iostream>
#include <string>


class Date{

	
	private:
		int month;
		int day;
		int year;
		
		
	public:
		Date(int month, int day, int year)
		{
			this->month = month;
			this->day = day;
			this->year = year;
		}
		
		void display (){
			std::cout<<month<<"/"<<day<<"/"<<year;
		}
};
class Sale; //foward declaration

class SalePerson{
	friend void displaySale (Sale aSale, SalePerson aSeller);
	
	private:
		std::string name;
		int id;
		
		
	public:
		SalePerson(std::string name, int id): name(name), id(id) { }
};

void displaySale (Sale aSale, SalePerson aSeller);

class Sale{
	// Member Function
	friend void displaySale (Sale aSale, SalePerson aSeller);
	
	private:
		Date saleDate;
		double amount;
		int id;
		
		
	public:
		Sale(int month, int day, int year, double amount, int id):
			saleDate(month,day,year), amount(amount), id(id) {} //more efficient

		//double getAmount() {return this->amount;}
		//int getId() {return this->id;}
		//Date getSaleDate() {return this->saleDate;}
		
};






int main() 
{

	SalePerson seller("Kevin James", 12);
	Sale saleOne(5,15,2025, 15.50, 9988);
	
	
	displaySale (saleOne, seller);
	
	
return 0;
}



void displaySale (Sale aSale, SalePerson aSeller)
{
	std::cout<<"\nDate: ";
	aSale.saleDate.display();
	std::cout<<"\nAmount: $"<<aSale.amount;
	std::cout<<"\nSeller: "<<aSeller.name;
	std::cout<<"\nSeller ID: #"<<aSale.id;
}
