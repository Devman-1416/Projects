// Devin Combs
//5/15/2025


#include <iomanip>
#include <iostream>
#include <string>

struct Pet {
	//Declare variable on sperate lines
	std::string name;
	std::string petType;
	int birthMonth;
	int birthDay;
	int birthYear;
	
	
	
	
	
};


int main() 
{
	struct Pet onePet= {"Smaug","bearded dragon",6,14,2024};
	
	std::cout<<onePet.name<<" "<<onePet.petType;
	
	

return 0;
}
