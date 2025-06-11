// Devin Combs
// 6/11/2025

#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <limits>
#include <stdlib.h>     


int main() 
{
		//Key                   //Value
	std::map<std::string, int> mapofPlanets; //#include <map>
	
						// Making a Pair  //Key = Earth  Value = 3
	mapofPlanets.insert(std::make_pair(     "earth",          3));
	mapofPlanets.insert(std::make_pair(     "mars",           4));
	mapofPlanets["jupiter"]=5;
	mapofPlanets["earth"]=1;
	
	std::map<std::string,int>::iterator it;
	it = mapofPlanets.begin();
	
	while (it != mapofPlanets.end())
	{
		std::cout<<"\n"<<it->first<<"-"<<it->second;
		it++;
	}
	
	if (mapofPlanets.insert(std::make_pair("earth",3)).second == false)
	{
		std::cout<<"\nEarth Not Inserted!";
	}
	
	if(mapofPlanets.find("sun") != mapofPlanets.end())
	{
		std::cout<<"\nFound!";
	}
	return 0;
}
