//Devin Combs

#include <stdio.h>
void print_rent_prices(float rent_prices[3]);
float calculate_rent(float rent_prices[3], int bedrooms);
int main() {
	
	int bedrooms;
	// patteren of +150.-25
	float rent_prices[3] = {1200.75,1350.50,1500.25};  
		//[3] size
		// |a1| |a2| |a3|	
		// |b1|--> |a1| rent_prices
	
	print_rent_prices(rent_prices); //only send array name for a function!!!!
	
	printf("\n\nHow many bedrooms would you like? ");
	scanf("%d",&bedrooms);
	
	float rent = calculate_rent(rent_prices,bedrooms);
	printf("\nYour rent will be: $%.2f",rent);
	
	return 0;
}

void print_rent_prices(float rent_prices[3]){

	for (int x = 0; x < 3; x++)
		{
		printf("\nPrice %d: $%.2f",x+1,rent_prices[x]);
		}
	
}

float calculate_rent(float rent_prices[3], int bedrooms)
{
	float rent = rent_prices[bedrooms-1];
	return rent;
	
}
