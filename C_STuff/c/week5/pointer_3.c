//Devin Combs 4/15
//Pointers

#include <stdio.h>

//For the rand()
#include <stdlib.h>

//for time()
#include <time.h>


int main ()
{
	int num;
	int min = 1;
	int max = 6;
	
		//Seed Value
	srand(time(0));
	
	num=rand() % 6 + min;
	//Equation for random number
		// (rand() % (max-min+1)) + min
	
	printf("\n%d\n",num);
	
	
	return 0;
}

