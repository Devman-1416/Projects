//Devin Combs

#include <stdio.h>

int main() 
{
	int numbers[8]={9,5,2,1,8,6,7,3};
	int a;
	
	for(int x =0; x < 8; x++) printf(" |%d| ",numbers[x]);	
	
	// -------------------bubble sort--------------------------
	for (int y=0; y<8 ;y++)
	{
		for(int x=0 ; x<7 ;x++)
		{
			if (numbers[x] > numbers[x+1])
			{
			a = numbers[x+1];
			numbers[x+1] = numbers[x];
			numbers[x] = a;
			}
			
		}
	}
	
	printf("\n\n\nSorted: ");
	for(int x=0; x < 8; x++) printf(" |%d| ",numbers[x]);
	
	
	return 0;
}
