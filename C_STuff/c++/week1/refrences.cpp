// Devin Combs
// 5/14/2025


#include <iomanip>
#include <iostream>
#include <string>
void getData(int &length, int &width);
void calculate(int &area, int &perimeter, int length, int width);

int main() {

	int length,width,area,perimeter;
	
	getData(length,width);
	calculate(area,perimeter,length,width);
	
	std::cout<<"Area: "<<area<<"\nPerimeter: "<<perimeter;

return 0;
}

				// catching as references!
void getData(int &length, int &width)
{
	std::cout<<"\n\nLength: "; std::cin>>length;
	std::cout<<"\nWidth: "; std::cin>>width;
}


void calculate(int &area, int &perimeter, int length, int width)
{
	area = length * width;
	perimeter = length +  width;
}
