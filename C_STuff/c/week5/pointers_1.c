//Devin Combs 4/14
//Pointers

#include <stdio.h>

int main ()
{
	
	//Pointer: A Variable, that can only contain a adresse (memory)
	int num, num2;
	int *numPtr; //A declared Pointer ( use * )
	num=5;
	numPtr=&num; // Store the momory address of num (not the 5!)
	
	printf("Num: %d",num);
	printf("\nNumPtr: %d",numPtr); //print addrese store in numPtr
	printf("\nNumPtr: %d",*numPtr); // go to memory spot of num, print contents
	
	//*numPtr = 8  changes num=8
	// * means (go to)
	printf("\n\nNumPtr: %d",*numPtr)
	
	
	
	
	
	return 0;
}




