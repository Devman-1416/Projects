//Devin Combs

#include <stdio.h>

int main(){
	//Categories (Loops, Repitions, Iteration)
		// 1: Definate (Counter Control) Loop
		// 2: Indefinate (Condition Control) Loop
		// 3: Infinate Loop
		
	// Three Every Loops Need
		// 1: Initialize
		// 2: Test
		// 3: Alter (Last thing before test)
		// loop control variable
		
	//Types of Loops
		// for
			//Initial Test  Alter
			//Definaite
		printf("For Loop: ");
		for (int x=1 ; x<5 ; x=x+1){
			printf("%d ",x);
		}
		
		// while
		printf("\nWhile Loop: ");
		int x = 1;
		while (x<5){
			printf("%d ",x);
			x+=1;
		}
		
		// do-while
		printf("\nDo-While Loop: ");
		x =1;
		do {
			printf("%d ",x);
			x++;
		} 
		while (x<5);
	
		// %i = integer, %d = decimal: Use %d
		int value;
		printf("\n\nEnter a Vaule: ");
		scanf("%d",&value);
		
		printf("The Num is: %d", value);
	
	
	
	
	
	return 0;
}
