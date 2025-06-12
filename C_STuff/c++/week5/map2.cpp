// Devin Combs
// 6/12/2025

#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <limits>
#include <stdlib.h>     


int main() 
{
	std::map <int,int> myMap { {100,1} , {200,2} };
	std::map <int, std::string> music { {1,"Journey"} , {2, "Led Zeppelin"} , {3,"Gretta"} };

					//at ( Use Key )
//	std::cout<<music.at(1);
	
					// using Key still
//	std::cout<<music[2];
//	music.at(1) = "Def Leppard";
	try
	{
		music.at(4) = "Shinedown";
	}
	catch (std::exception &e)
	{
		std::cout<<"\nKey dose not exist!\n";
		std::cout<<"\n"<<e.what()<<std::endl;
	}
//	music[4]= "Shinedown";

	music[5] = "Eminem";
	music[3] = "Postal Service";

	
	for (std::map<int,std::string>::iterator it = music.begin();
			 it != music.end() ; it++  )
			 {
			 	std::cout<<"\n"<<it->first<<" "<<it->second;
			 }

	myMap[300] = 3;
	myMap[400] = 4;
	myMap[500] = 5;
	
	std::map<int,int>::iterator i,j;
	i = myMap.find(200);
	j = myMap.find(400);
	
	std::map<int,int> newMap;
					// j is end bound, not printed
					
	newMap.insert(i,j);

	for (std::map<int, int>::iterator it = newMap.begin();
			 it != newMap.end() ; it++  )
			 {
			 	std::cout<<"\n"<<it->first<<" "<<it->second;
			 }

	return 0;
}
