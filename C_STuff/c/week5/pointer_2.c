//Devin Combs 4/14
//Pointers

#include <stdio.h>
 void calcValues(float length, float width, float *areaPtr, float *perimeterPtr);
 void inputValues(float *lengthPtr, float *widthPtr);

int main ()
{
	float length, width, area, perimeter;
	//length =5;
	//width =10;
	
	
				// Pass in adress of length abd perimeter
    inputValues(&length, &width);
	
	
	
	
	

							// Pass in adress of area and perimeter
	calcValues(length,width, &area, &perimeter);
	printf("%.2f area and %.2f perimeter",area,perimeter);
	
	
	
	
	
	return 0;
}
												// Make pointers to hold addresse pass over from main
 void calcValues(float length, float width, float *areaPtr, float *perimeterPtr)
{
	// Go to address in *areaPtr (so area) and store the math: kinda like saying [ area (from main) = lenght * width ]
	*areaPtr = length * width;
	*perimeterPtr = (2*length) + (2*width);
	
	
}

void inputValues(float *lengthPtr, float *widthPtr)
{
	printf("\n\nEnter Width: ");
				//store input at address in widthPtr
	scanf("%f",widthPtr);
	
	printf("\n\nEnter Length: ");
	scanf("%f",lengthPtr);
	
	
	
}
