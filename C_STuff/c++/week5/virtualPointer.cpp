// Devin Combs
// 6/10/2025

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <limits>
#include <stdlib.h>     

class Parent
{
	private:
		int num1;
		
	public:
		Parent (int x = 2) { num1=x;}
		virtual int getNum () {return num1;}
		virtual	void twistIt() {num1 *=3;}
		int getTwist()
		{
			twistIt();
			return getNum();
		}	
};     

class Child:public Parent
{
	private:
		int num2;
		
	public:
		Child(int x = 5): Parent(2) 
			{num2=x;}
		int getNum () {return num2;}
		void twistIt () {num2 *=10;}
};

void display (Parent &x);
int main() 
{
	Parent yondu;
//	std::cout<<"\nNum1: "<<yondu.getNum(); // 2
//	
	yondu.twistIt();

//	std::cout<<"\nNum1: "<<yondu.getNum(); // 6

	Child judy;
//	std::cout<<"\nNum1: "<<judy.getNum(); // 5 
//	
//	judy.twistIt();
//	std::cout<<"\nNum1: "<<judy.getNum(); // Still 5
//	
//	std::cout<<"\nNum1: "<<judy.Parent::getNum(); // 6
	
	std::cout<<"\n\n"<<judy.getNum();
	judy.twistIt();
	
	
	std::cout<<"\n\n"<<judy.Parent::getNum();
	
	std::cout<<"\n\n"<<judy.getTwist();	
	std::cout<<"\n\n"<<judy.getNum();
	
	display(yondu);
	display(judy);
	



	return 0;
}


void display (Parent &x)
{
	std::cout<<"\nThe objects number is: "<<x.getNum();
}

