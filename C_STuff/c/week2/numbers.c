// Devin Combs
#include <stdio.h>
#include <math.h>

int main (){
	//Binary 0..1
		//Base 2: 2 4 8 16 32 64 ...

	//int is total 4 bytes
	//short int 2 bytes
	//unsigned no negatives
	int zip = 98128;
	
	printf("Zip: %d",zip);	// Rolls over since number out of short int range
	
	//Octal 0..7
		//Base 8: 010 , 111
		//3 bit: 1.2.4
		//Leading 0 for Ocatal = 072
		// 042 = 100010
		//0113 = 000 001 001 011
	
	int num1 = 75;
	printf("\nNum1 Decimal: %d",num1);
	printf("\nNum1 Ocatal: %o",num1);
	printf("\nNum1 Character: %c",num1);
	
	int num = 075; 
	//Adding leading 0 makes octal num
	printf("\nNum Decimal: %d",num1);
	printf("\nNum Ocatal: %o",num1);
	printf("\nNum Character: %c",num1);
	
	//Hexadecimal
		//Base 16: 0..9 A,B,C,D,E,F
		//4 bit: 8.2.4.1
		// Hex 0x42 = binary 01000010
		
	int num2 = 0x2eb5; //Adding leading 0 makes octal num
	printf("\nNum2 Decimal: %d",num1);
	printf("\nNum2 Ocatal: %o",num1);
	printf("\nNum2 Character: %c",num1);	
		
	// Computers cant do proper float/decimal math
	double price = 56.05, amount = 60.00;
	double sum = amount - price; 
	printf("Float Stuff: %.20lf", sum);
		//%lf for double
		//Never compare Float for equality!!!!
	
		//To compare floats
		//fabs: absolute value, needs math.h
	if ( fabs(sum - 3.94) < .005) printf("\nEqual");
	else printf("\nNot Equal");		
			
			
	// 2 bytes = -32... to 32...
	// 4 bytes = -2bil to 2 bil
	// 8 bytes = -9...................... to 9.........................
return 0;
}
