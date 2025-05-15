// Devin Combs
//5/15/2025


#include <iomanip>
#include <iostream>
#include <string>

class Pet {
// Want data in classes private!!
private:
	//Declare variable on sperate lines
	std::string name;
	std::string petType;
	int birthMonth;
	int birthDay;
	int birthYear;
	
//Funcations will be public
public:
	
	//Constructor (Same name as Class and no return
	Pet(std::string n, std::string t, int m, int d, int y)
	{
		name = n;
		petType = t;
		birthMonth = m;
		birthDay = d;
		birthYear = y;	
	}
	
		//Default Constructor
	pet() 
	{
		name = "Unknown";
		petType = "Unknown";
		birthMonth = 0;
		birthDay = 0;
		birthYear = 0;		
	}
	
	pet(std::string t) 
	{
		name = "Unknown";
		petType = t;
		birthMonth = 0;
		birthDay = 0;
		birthYear = 0;
	}
	
	//Accessors to get private data //getters
	std::string getName()
	{
		return name;
	}
	std::string getPetType()
	{
		return petType;
	}
	int getBirthMonth()
	{
		return birthMonth;
	}
	int getBirthDay()
	{
		return birthDay;
	}
		//Condense it on one line like this
	int getBirthYear() { return birthYear; }
	
	//Mutators  / Setters
	void setName(std::string name) { this->name=name; } //this-> point to class private variable
	void setPetType(std::string petType) { this->petType=petType; }
	void setBirthMonth(int birthMonth) { this->birthMonth=birthMonth; }
	void setBirthDay(int birthDay) { this->birthDay=birthDay; }
	void setBirthYear(int birthYear) { this->birthYear=birthYear; }
	
		
	//Utility Functions
	void display()
	{
		std::cout<<"\nName:        "<<this->name;
		std::cout<<"\nType:        "<<this->petType;
		std::cout<<"\nBirth Month: "<<this->birthMonth;
		std::cout<<"\nBirth Day:   "<<this->birthDay;
		std::cout<<"\nBirth Year:  "<<this->birthYear<<std::endl;
	}
	
	
};


int main() 
{
	Pet onePet ("Smaug","bearded dragon",6,14,2024);
	onePet.setName("Griffin");
	
	std::cout<<onePet.getName()<<" "<<onePet.getPetType();
	
	//objects
	Pet twoPet();
	Pet threePet ("Death","Horse",1,2,1978);
	
	onePet.display();
	twoPet.display();
	threePet.display();
	
	
	

return 0;
}
