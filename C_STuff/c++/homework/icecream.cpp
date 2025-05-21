// Devin Combs
//Ice Cream


#include <iomanip>
#include <iostream>
#include <string>


int main() 
{
//Declare variables

std::string flavor[5] = {"vanilla", "butter pecan", "superman", "chocolate fudge", "strawberry"};
int scoops[5] = {0,0,0,0,0};
int total_scoops = 0, best_flavor=0, worst_flavor=6;

// Get Data
for (int x = 0; x < 5 ; x++)
{
	std::cout<<"\nHow many scoops of "<<flavor[x]<<" was sold? ";
	
	// Data validation
	while(!(std::cin>>scoops[x]) || scoops[x] < 0)
	{
		std::cout<<"\n\nInvalid amount of scoops, must be 0 or more!";
		std::cout<<"\nHow many scoops of "<<flavor[x]<<" was sold? ";
		
		std::cin.clear();
		std::cin.ignore(100,'\n');
	}
	
	
	total_scoops+=scoops[x];
}


for (int x = 0; x < 5 ; x++)
{
	std::cout<<"\nTotal "<<flavor[x]<<" sold: "<<std::setw(-10)<<scoops[x];
	
	if (best_flavor < scoops[x]) best_flavor = scoops[x];
	if (worst_flavor > scoops[x]) worst_flavor = scoops[x];
}




// Display Stuff
std::cout<< "\nTotal Scoops: "<<total_scoops<<std::endl;

for (int x = 0; x < 5 ; x++)
{
	if (scoops[x] == best_flavor)
	{
		std::cout<<"\nTop Sold Flavor: "<<flavor[x]<<" sold: "<<best_flavor;
	}
}

for (int x = 0; x < 5 ; x++)
{
	if (scoops[x] == worst_flavor && worst_flavor != best_flavor)
	{
		std::cout<<"\nLowest Sold Flavor: "<<flavor[x]<<" sold: "<<worst_flavor;
	}
}

return 0;
}


