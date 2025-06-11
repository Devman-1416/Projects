// Devin Combs
// 6/11/2025

#include <iostream>
#include <iomanip>
#include <string>
#include <set>
#include <limits>
#include <stdlib.h>     


int main() 
{
	//Type of Container
	std::set<std::string> setofNums; //requires #include <set>
	
	setofNums.insert("first");
	setofNums.insert("second");
	setofNums.insert("third");
	setofNums.insert("four");
	
	std::cout<<"\n Set Size: "<<setofNums.size()<<std::endl;
	
//	for (int x=0; x<someSize; x++) Old one

				//Making a Interator             //Assigning it address of first Item in set
	for (std::set<std::string>::iterator               it=setofNums.begin()                 
		 ; it!=setofNums.end()     ;       it++)
		 	//Run untill the end       //Increment
	{     
		std::cout<<"\n" +*it + "\n";
	}
	
	
	std::set<std::string>::iterator it;
	
	it = setofNums.find("fourth");
	

	if (it == setofNums.end()) std::cout<<"\nfound";
	
	if (it != setofNums.end()) std::cout<<"\nNot found";
	
	return 0;
}

