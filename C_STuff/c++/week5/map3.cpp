// Devin Combs
// 6/12/2025

#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <limits>
#include <stdlib.h>     

class Pizza {
	
	private:
		int x;
		
	public:
		Pizza ()
		{
			x = 5;
		}
		
		int getPizza ()
		{
			return x;
		}
};

int main() 
{
	
	Pizza aPizza;
	
	std::map <int, Pizza> testPizza;
	
	testPizza.insert(std::pair<int,Pizza>(1,aPizza));

	std::cout<<testPizza.at(1).getPizza();
	
	for (std::map<int,Pizza>::iterator it = testPizza.begin();
			 it != testPizza.end() ; it++  )
			 {
			 	std::cout<<"\n"<<it->first<<" "<<it->second.getPizza();
			 }
	
	return 0;
}
