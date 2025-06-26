// Devin Combs
// 6/17/2025

#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <limits>
#include <stdlib.h>     
//
//bool compare (int a, int b);
//bool compare (std::string a, std::string b);

// Templete Classes
template <class T>
class Item
{
	private:
		T value;
	public:
		Item(T value): value(value)
		{
		}
		
		T getValue ()  {return value;}
		void display() {std::cout<<"\n\n"<<value;}
};// End




// Template using primative data 
template <typename T> 
bool compare (T a, T b)
{
	return a>b;
}

template <typename T, typename U>
T add(T a, U b)
{
	return a + b;
}

template <class T>
void display(){std::cout<<"\n\n"<<value;}

int main() 
{

	int a = 10, b =20;
	
	
	
	if (compare(a,b)) std::cout<<"\n A is greater than b";
	else std::cout<<"\n b is greater than A";
	
	std::string first = "Dev", last = "Comb";
	if (compare(first,last)) std::cout<<"\n first is greater than last";
	else std::cout<<"\n last is greater than first";

	std::cout<<"\n\n"<<"Num: "<<add(10,10.5);
	std::cout<<"\n\n"<<"Num: "<<add(10.5,10);

	Item<int> oneItem(123); // Templete class
	Item<std::string> twoItem("Hello");
	
	oneItem.display();
	twoItem.display();


	return 0;
}
//
//bool compare (int a, int b)
//{
//	return a>b;
//}
//
//bool compare (std::string a, std::string b)
//{
//	return a>b;
//}


