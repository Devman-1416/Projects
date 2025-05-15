#include <stdio.h>

int main(){
	
	char marriage;
	
	printf("Are you married or single? Then enter a M or S: ");
	scanf("%c",&marriage);

	
	if (marriage == 'm' || marriage == 'M' || marriage == 's' || marriage == 'S')
	{
		if (marriage == 'm' || marriage == 'm') printf("You are married!");
		else printf("Your not Married?");
	}
	else printf("Enter M or S, wrong status.");
	
	printf("\n\n");
	return 0;
}
