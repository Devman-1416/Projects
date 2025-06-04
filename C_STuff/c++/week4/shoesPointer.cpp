// Devin Combs
//Shoes

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <cmath>

class Shoes
{	
	public:
		std::string color;
		std::string style;
		
		
		Shoes ( std::string color, std::string style): color(color), style(style) {;}
		//Shoes () {}
		
		
		void display()
		{
			std::cout<<"\nColor: "<<this->color<<"\nStyle: "<<this->style<<std::endl;
		}
		
		~Shoes() //Destructor
		{
			std::cout<<"\nRemoving my color: "<<color<<"\nStyle: "<<style;
		}
		
};
 
void displayMyShoes (Shoes *shoe);
int main() 
{
	Shoes * allMyShoes[3] =  { new Shoes("Teal","Sneakers"),
								new	Shoes("Yellow","Sneakers"),
	 						 	new	Shoes("Orange","Sneakers")  };
	
	
//	Shoes * newShoes = new Shoes[3] {Shoes("Teal","Sneakers"),
//									Shoes("Yellow","Sneakers"),
//	 						 		Shoes("Orange","Sneakers")};
	
	
	Shoes myShoes ("Red", "Tennis");
	Shoes yourShoes ("Black","Crocks");
	
//	myShoes.display();
//	yourShoes.display();
	
	// new operator returns a address Dynamic Memory, not stack memory
	Shoes * const moreShoes = new Shoes("White","Sneakers");
	
//	moreShoes->display();   //using address use ->
	//(*moreShoes).display(); // using objecy  use .
	
	//moreShoes->display();
	
	//delete moreShoes; // To remove dynamicly memory, from the heap
	
	allMyShoes[0] = &myShoes;
	allMyShoes[1] = &yourShoes;
	allMyShoes[2] = moreShoes;
	
	for (Shoes *shoes : allMyShoes)
	{
		std::cout<<"\nShoe: ";
		displayMyShoes(shoes);
	}
	

	
	
	displayMyShoes(&myShoes);
	displayMyShoes(&yourShoes);
	displayMyShoes(moreShoes);
	
	
	//Float == Float
	const float ESPILON = .0005;
	
	float amount = 56.06, given = 60.00;
	
	float totalDue = given - amount;
	
	std::cout<<std::fixed<<std::setprecision(2);
	
	if (fabs(totalDue - 3.94) < ESPILON)
	{
		std::cout<<"\n\nThey Equal!!!";
	}
	
	else std::cout<<"\n\nNot Equal!!!";
	
			std::cout<<"Amount: "<<totalDue;
	
	
	
	

return 0;
}


void displayMyShoes (Shoes *shoe)
{
	shoe->display();
}
