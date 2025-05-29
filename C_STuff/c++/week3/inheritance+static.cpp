// Devin Combs
//Inheritance



#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <limits>

// Parent -> Child
// Base -> Derived
// SuperClass -> SubClass
// Ancestor -> Descendant

class Rectangle {
	//protected:
	private:
		int length;
		int width;
		
	public:
		Rectangle (int l, int w)
		{
			length = l;
			width = w;
		}
		
		void setData(int l, int w) { length = l; width =w; }
		
		void display() {std::cout<<"L: "<<length<<"  W: "<<width;}
		int computer() {return length * width;}
};

		// Inheritance
class Block : public Rectangle {
	
	private:
		int height;
		
	public:
		//To use Constructor, Initilzation
		Block (int l, int w, int h) :Rectangle::Rectangle(l,w), height(h) {}

		void setData(int l, int w, int h) 
		{ 
		
		//To Make  default Constructor
		//Block (): Rectangle::Rectangle (0,0) { height = 0;}
		
	
		// use . with objects | << and :: with classes
		Rectangle::setData(l,w); 
		height=w; 
		}
		
		// Over-riding the parents function
		void display()
		{
			Rectangle::display();
			std::cout<<" H: "<<height;
		}
		
		int computer()
		{
			return height * Rectangle::computer();
		}
};


//Static 
class Bank{
	private:
		static int newAccountNum;
		int accountNum;
		double balance;
		
	public:
		Bank(): accountNum(newAccountNum++), balance(0) {;}
		
	std::string display()
	{
		return "\nAcct #: " + std::to_string(accountNum) + "\nBalance: $" + std::to_string(balance);
	}
	
	// To use and pull static variable without using object
	static int gerNewNum()
	{
		return newAccountNum;
	}
};
//For the Static
int Bank::newAccountNum = 1000;


int main() 
{
	
	std::cout<<Bank::gerNewNum();
	
	Rectangle square(0,0);
	square.setData(5,5);
	square.display();
	std::cout<<"\nArea: "<<square.computer()<<std::endl;
	
	
	Block cube(0,0,0);
	cube.setData(3,3,3);
	cube.display();
	std::cout<<"\nVolume: "<<cube.computer()<<std::endl;

			// TO use Parents setData
	cube.Rectangle::setData(8,8);
	
	Bank me;
	Bank you;
	
	std::cout<<me.display()<<std::endl;
	std::cout<<you.display()<<std::endl;
	
	
	
	
	
return 0;
}


