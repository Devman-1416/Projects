// Devin Combs
// Car Class


#include <iomanip>
#include <iostream>
#include <string>
#include <cmath>
#include <limits>
#include <chrono>

class Car {
	private:
		int year;
		std::string make;
		std::string model;
		float speed;
		float gallons;
		bool engine;


	public:
	//Constructor
		Car (int year , std::string make, std::string model)
		{
			this->year = year;
			this->make = make;
			this->model = model;
			this->speed = 0;
			this->gallons = 10;
			this->engine = false;
		}
		
	//Accessors
		int getYear() { return this->year;}
		std::string getMake() { return this->make;}
		std::string getModel() { return this->model;}
		float getSpeed() { return this->speed;}
		float getGallons() { return this->gallons;}
		bool getEngine() { return this->engine;}
		
	//Mutators
		void accelerate()
		{
			this->speed += 5;
			this->gallons -= .5;
		}
		
		void brake()
		{
			this->speed -= 5;
			
			if ((this->gallons -= .2) < 0) this->gallons =0;
		}
		
		void fillUp()
		{
			//this->gallons=+5 > 22 ? this->gallons = 22 : this->gallons;
			if ((this->gallons += 5) > 22) this->gallons=22;

		}
		
		void setEngine(bool engine) {this->engine = engine;}

		
	//Utility Functions
	void display()
	{
		std::cout<<"\n--------------Car----------------";
		std::cout<<"\nYear : "<<this->year;
		std::cout<<"\nMake : "<<this->make;
		std::cout<<"\nModel: "<<this->model;
		std::cout<<"\nSpeed: "<<this->speed<<"mph";
		std::cout<<"\nTank : "<<this->gallons<<"gal";
		this->engine ? std::cout<<"\nEngine On" : std::cout<<"\nEngine Off";
	}
		
};

int main() 
{
Car car (2015,"Dodge","Journey");
bool engine = false;
int choice;
int turn = 1;


	
while (true)
{
	std::cout<<"\n--------------------Turn: "<<turn<<"------------------\n";
	car.display();
	std::cout<<"\n-----------Menu--------------\n";
	std::cout<<"\nStart Car    (1)";
	std::cout<<"\nTurn off Car (2)";
	std::cout<<"\nAdd Gas      (3)";
	std::cout<<"\nAccelerate   (4)";
	std::cout<<"\nDeccelerate  (5)\nEnter: ";
	
	while(!(std::cin>>choice) || (choice < 1 || choice > 5))
	{
		std::cout<<"\nInvalid Menu Option! Enter a 1 - 5: ";
		std::cin.clear();
		std::cin.ignore( std::numeric_limits<std::streamsize>::max() ,'\n');
	}

	
	
    switch (choice) {
    	
        case 1:
        	
			if (car.getSpeed()==0 && car.getGallons() != 0)
			{
				car.setEngine(true);
				std::cout<<"\nEngine Turned On\n";
			}
			else std::cout<<"\nCar must be stopped to turn on!";
            break;
            
        case 2:
        	
			if (car.getSpeed()==0)
			{
				car.setEngine(false);
				std::cout<<"\nEngine Turned Off\n";
			}
			else std::cout<<"\nCar must be stopped to shut off!";

            break;
            
        case 3:
            if (!(car.getEngine()))
        	{
				if (car.getSpeed() == 0)
				{
					car.fillUp();
					std::cout<<"\nGas Added!";
				}
				else std::cout<<"\nCar must be stopped to add gas!";
			}
			else std::cout<<"\nEngine must be off! Safty First";
            break;
            
        case 4:
        	if (car.getEngine())
        	{
	        	if (car.getGallons() != 0)
	        	{
					car.accelerate();
					std::cout<<"\nAccelerating!";
				}
			}
			else std::cout<<"\nEngine is Off!";
			
			if (car.getGallons() == 0) 
			{
				std::cout<<"\nOut of Gas!";
				car.setEngine(false);
			}
            break;
            
        case 5:
			if (car.getSpeed() != 0)
			{
				car.brake();
				std::cout<<"\nBraking!";
			}
			else std::cout<<"\nCar is already stoped!";
            break;
  
        default:
        	std::cout<<"\nNot a Valid Input!";
        	break;
        }
        
	if (car.getGallons() == 0) 
	{
		std::cout<<"\nOut of Gas!";
		if (car.getSpeed() != 0)
		{
			car.brake();
			std::cout<<"\nBraking!";
		}
		else std::cout<<"\nCar is Stoped";
	}
        
    turn++;
	std::cout<<"\n\n\n";
}
	

return 0;
}
