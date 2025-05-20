// Devin Combs
//5/20/2025



#include <iomanip>
#include <iostream>
#include <string>
//Find and replace at complie, more efficent

//#define TAXRATE 0.06
const float TAXRATE=0.06; // Global Constant, Global Scope Since outside Main
static int number = 0; //static global, extends to other files

void calculate();

int main() 
{
	// Cool Data check   #include <limits>
	// std::cin.ignore( std::cumeric_limits<std::streamsize>::max() ,'\n');
	
	
	float amount = 100.00;
	float taxDue = amount * TAXRATE;
	
	std::cout<<"Tax Due: "<<taxDue;
	calculate();
	
return 0;
}


void calculate()
{
	static int num1 = 0; //static global extends lifetime out of scope
	
	std::cout<<"\nNumber: "<<num1;
	num1++;	
}



