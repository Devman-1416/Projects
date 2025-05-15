//Devin Combs

#include <stdio.h>

int main(){
	char first,last;
	int fav_num;
	
	printf("Enter Your Favorite Number: ");
	scanf("%d",&fav_num);
	
	printf("\nEnter Your first Inital: ");
	scanf("\n%c",&first); // The "\n%c for enter key in the buffer
	
	printf("\nEnter Your last Inital: ");
	scanf("\n%c",&last);
	
	printf("\nYour Initals are %c.%c and your number is %d",first,last,fav_num);
	
	printf("\n 1: %d",fav_num);
	printf("\n 2: %c",fav_num);
	printf("\n 3: %c",first);
	printf("\n 4: %d",first);
	
	first = first + 5;
	printf("\n 5: %c",first);
	printf("\n 6: %d",first);
	
	
	
	
	
	
	
	
	
	
	return 0;
	
	
}
