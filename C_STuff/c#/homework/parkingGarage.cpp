// Devin Combs
//Parking Garage


#include <iomanip>
#include <iostream>
#include <string>
#include <cmath>




int main() {
std::cout<<std::setprecision(2)<<std::fixed;
int again;
float fee,hours,total_hours=0,total_fee=0;	
	
do 
{
	std::cout<<"Welcome to the Garage\nHow long is your car going to be staying: ";
	
	while(!(std::cin >> hours) || hours <= 0 || hours > 24)
	{
		std::cout<<"\n\nInvalid amount of hours, must be between 0 and 24!";
		std::cout<<"\nHow long is your car going to be staying: ";
		
		std::cin.clear();
		std::cin.ignore(10,'\n');
	}
	total_hours+= hours;
	

	if ( hours > 3)
	{
		fee = 2.5 + (ceil(hours) - 3);
	}
	else fee = 2.5;
	
	if (fee > 20) fee = 20;
	
	total_fee += fee;
	
	
	std::cout<<"\n\nFee: $"<<fee<<"\nHours: "<<hours;
	
	std::cout<<"\n\nGo Again? Yes = 1 No = 0 : ";
	while (!(std::cin >> again) || (again != 0 && again != 1))
	{
		std::cout<<"\n\nInvalid Choice! Yes = 1 No = 0 : ";
		std::cin.clear();
		std::cin.ignore(100,'\n');
	}
	std::cout<<"-----------------------------------\n\n";
} while (again);

std::cout<<"\n\nThanks for Parking with us!";
std::cout<<"\n\nTotal Fee: $"<<total_fee<<"\nTotal Hours: "<<total_hours;

return 0;
}
