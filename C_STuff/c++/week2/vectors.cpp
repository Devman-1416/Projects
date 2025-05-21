// Devin Combs
// 5/21/2025


#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

int main() {
	// Vectors are Object-Based / Dynamic
	//Array - Static
	
	// < mean data type >
	std::vector<int> temps(5,20);  // int temps [5]
	//temps.reserve(20); //Reserve 20 memory
	
	//push_back: add to back
	temps.push_back(55); //Add 55 s:1 c:1
	//std::cout<<temps[0]; //subscript Notation
	
	temps.push_back(66); //Add 66 s:2 c:2
	temps.push_back(77); //Add 77 s:3 c:4
	temps.push_back(88); //Add 88 s:4 c:4
	temps.push_back(99); //Add 99 s:5 c:8	
	std::cout<<"\nSize: "<<temps.size()<<"\nCapacity: "<<temps.capacity()<<std::endl;

	for (int x = 0; x < temps.size(); x++)
	{
		std::cout<<" "<<temps.at(x); //at is safer, cant go out of rangr
	}
	std::cout<<std::endl;

	for (int &oneTemp : temps) //Range Based For Loop : Works Like for-each
	{
		oneTemp++;
		std::cout<<" "<<oneTemp;
	}
	std::cout<<std::endl;
	
	for (int oneTemp : temps) //Range Based For Loop : Works Like for-each
	{
		std::cout<<" "<<oneTemp;
	}
	
	// Last In First Out (LIFO)
	
	
	
	
	
	
	
	
	
	return 0;
}
