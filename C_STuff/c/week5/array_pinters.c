//Devin Combs 4/17
//Pointers and arrays

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void printTemps (int temp[]);

int main ()
{
	int temp[7]={60,50,45,72,64,78,90};
	
	printTemps(temp);

	return 0;
}

// Array name like pointer
void printTemps (int *temp)
{
	for(int x=0;x<7;x++)
	{
		//printf("%d |",temp[x]);   <-------Subscipt Notation
		//printf("%d ", *temp++);   <-------Pointer Arithmetic (changes the pointer)
		//printf("%d ", *(temp+x)); <------Pointer Notation
	}
	
}
