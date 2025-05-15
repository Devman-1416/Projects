//Devin Combs
#include <stdio.h>
float calc_area ( float length, float width);
float calc_perimeter (float length, float width); //Prototype

int main (){
	float area, perimeter;
	float length, width;
	char answer;
	
	// Get User Input
	printf ("Enter Length: ");
	scanf("%f",&length);
	
	printf ("\nEnter Width: ");
	scanf("%f",&width);
	
	printf("\nEnter A for Area or P for Perimeter: ");
	// \n in scanf for enter char
	scanf("\n%c",&answer);
	printf("\nYou Chose: %c",answer);
	
	// Select and run function choice, and display
	float result;
	if ( answer == 'A' || answer == 'a'){
		result = calc_area(length,width);
		printf("\nThe Area is: %.2f",result);
		
	}
	else if ( answer == 'P' || answer == 'p'){
		result = calc_perimeter(length,width);
		printf("\nThe Perimeter is: %.2f",result);
	}
	else printf("\nYou didnt enter a vaild choice!");

	
	
return 0;	
}
// float = return type
//calc_area = name
// ( Float l, Float w ) parameters
float calc_area ( float length, float width)//Head
{
	float area = length * width;
	return area;							// Whole this is defination
	//body
}

float calc_perimeter (float length, float width){
	float perimeter = 2 * length + 2 * width;
	return perimeter;
}


