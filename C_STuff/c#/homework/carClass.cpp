// Devin Combs
//Car Class


#include <iomanip>
#include <iostream>
#include <string>

class Car {
	private:
		int year;
		std::string make;
		std::string model;
		float speed;
		float gallons;


	public:
	//Constructor
		car (int year , std::string make, std::string model)
		{
			this->year = year;
			this->make = make;
			this->model = model;
			this->speed = 0;
			this->gallons = 10;
		}
		
	//Accessors
		int getYear() { return year;}
		std::string getMake() { return make;}
		std::string getModel() { return model;}
		float getSpeed() { return speed;}
		float getGallons() { return gallons;}
		
	//Mutators
		void accelerate()
		{
			this->speed += 5;
			this->gallons -= .5;
		}
		
		void brake()
		{
			this->speed -= 5;
			this->gallons -= .2;
		}
		
		void fillUp()
		{
			this->gallons=+5 > 22 ? this->gallons = 22 : this->gallons;
			// if (this->gallons += 5 > 22) this->gallons=22;
		}
		
		bool startCar() {return 1;}
		bool shutOff()	{return 0;}
		
};

int main() 
{

return 0;
}
