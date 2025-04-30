//Devin Combs
#include <stdio.h>
int add_num(int num1,int num2); // Prototype
void print_sum(int sum);
int ask_num();

int main(){
	int num1,num2,sum;
	
	num1 = ask_num();
	num2 = ask_num();
	
	sum=add_num(num1,num2); // functions call + (argument)
	print_sum(sum);
	// print_sum(add_num(num1,num2)) more efficent
	// print_sum(add_num(ask_num(),ask_num())) most efficent
	
	
	return 0;
}
// Do functions for Class under main, prototype
// Name 2 word, verb + noun
// int function() is returntype + name + (parameters)
int add_num(int num1,int num2){ //functions Header
	int sum = num1 + num2;				// Whole this is Function Defination
								// Function Body
	return sum;
	// return (num1 + num2) more efficent
}								// Whole Thing is Function Definitions

void print_sum(int sum){ // use void since nothing return
		printf("\nThe sum is: %d",sum);
		 // No return Data Type
	}
	
int ask_num(){
	int num;
	printf("\nEnter Your Number: ");
	scanf("%d",&num);
	
	return num;
}
	
	
