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
		Block () :Rectangle::Rectangle (0,0) { height = 0;}
		
	
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


int main() 
{
	
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
return 0;
}


