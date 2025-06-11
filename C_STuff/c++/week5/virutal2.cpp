// Devin Combs
// 6/10/2025

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <limits>
#include <stdlib.h>     

class Pet
{
	private: 
		std::string name;
	
	public:
		Pet(std::string n)
		{
			name = n;
		}
		std::string getName()
		{
			return name;
		}
		virtual void print()
		{
			std::cout<<"\nName Only! "<<name;
		}
		virtual std::string says()
		{
			
		}
};

class Dog : public Pet
{
	private:
		std::string breed;
		
	public:
		Dog (std::string n, std::string breed): Pet(n)
		{
			this->breed = breed;
		}
		std::string getBreed()
		{
			return breed;
		}
		void print()
		{
			std::cout<<"\nName: "<<getName()<<"   Breed: "<<breed;
		}
		
		std::string says()
		{
			return "woof....";
		}
};

class Cat : public Pet
{
	private:
		std::string breed;
		
	public:
		Cat (std::string n, std::string breed): Pet(n)
		{
			this->breed = breed;
		}
		
		std::string getBreed()
		{
			return breed;
		}
		
		void print()
		{
			std::cout<<"\nName: "<<getName()<<"   Breed: "<<breed;
		}
		
 		std::string says()
		{
			return "Meow....";
		}
};

void speak (Pet *pet)
{
	std::cout<<pet->says();
}

int main() 
{

	Dog vDog("Titus","Malamute");
	
	Pet vPet("Connor");
	
	vDog.print();
	vPet.print();
	
	Pet aPet("Yeller");
	aPet = vDog;
	aPet.print();
	
	Pet *myPet;
	Dog *myDog;
	Cat *myCat;
	
	myCat = new Cat("Shadow", "Callic");
	myDog = new Dog("Strider","Shiba");
	myDog->print(); // using -> because its a pointer
	
	myPet = myDog;
	myPet->print();
	
	std::cout<<"\n"<<myDog->says();
	
	speak(myDog);
	speak(myCat);

	return 0;
}



