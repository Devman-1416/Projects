// Devin Combs
// 6/17/2025

#include <iostream>
  
namespace MySpace
{
	void display()
	{
		std::cout<<"\nMy Space!\n";
	}
}

void display()
{
	std::cout<<"\nNo Space!\n";
}

namespace YourSpace
{
	void display()
	{
		std::cout<<"\nYour Space!\n";
	}	
}

//using namespace Myspace;

int main() 
{
	
	MySpace::display();
	YourSpace::display();
	display();


	return 0;
}

