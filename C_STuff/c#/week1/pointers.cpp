// Devin Combs
// 5/14/2025


#include <iomanip>
#include <iostream>
#include <string>
void getData(int *length, int *width);
void calculate(int *areaPtr, int *perimeterPtr, int length, int width);

int main() {

	int length,width,area,perimeter;
	
	getData(&length,&width);
	calculate(&area,&perimeter,length,width);
	
	std::cout<<"Area: "<<area<<"\nPerimeter: "<<perimeter;

return 0;
}

void getData(int *lengthPtr, int *widthPtr)
{
	std::cout<<"\n\nLength: "; std::cin>>*lengthPtr;
	std::cout<<"\nWidth: "; std::cin>>*widthPtr;
}

void calculate(int *areaPtr, int *perimeterPtr, int length, int width)
{
	*areaPtr = length * width;
	*perimeterPtr = length +  width;
}

