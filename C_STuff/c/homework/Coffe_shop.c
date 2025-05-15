//Devin Combs
#include <stdio.h>
#include <ctype.h>
#include <string.h>
	float orderCoffee(float total,char *creamPtr, char *sugarPtr, char *user_size, char *user_flavor );
	void displayOrder(float total,char cream, char sugar, char *user_size, char *user_flavor);

int main ()
{
	char user_size[20];
	char user_flavor[20];
	char cream,sugar;
	float total;

	total += orderCoffee(total,&cream,&sugar,user_size,user_flavor);
	displayOrder(total,cream,sugar,user_size,user_flavor);

}

float orderCoffee(float total,char *creamPtr, char *sugarPtr, char *user_size, char *user_flavor)
{
	char *AllFlavors[6]={"House","Iced","Vanilla","Hazelnut","Mocha"};
	char *Sizes[3]={"small","medium","large"};
	int found=0;
	
	//Get Size
	do {
		
		printf("\n\nEnter your Size (Small: $3.00/ Medium: $4.50/ Large: $6.00 ): ");
		fgets(user_size,15,stdin);
	
		for (int x=0;x<strlen(user_size);x++)
		{
			user_size[x]=tolower(user_size[x]);	
		}
		user_size[strlen(user_size) - 1] = '\0';
		
		
		for (int x=0;x<3;x++)
		{

			if (strcmp(user_size,Sizes[x])==0)
			{
				found =1;
				if (user_size == Sizes[0]) total+=3;
				else if (user_size == Sizes[1]) total +=4.5;
				else total +=6;
				break;
			}
		}
		
		if (!found) printf("\nInvalid Size! Try again.");
	}
	while(!found);

	
	//Get Flavor

	found = 0;
	do {
		
		printf("\n\nAvaliable Flavors: \n");
		for (int x=0;x<5;x++)
		{
			printf("\n\t%s",AllFlavors[x]);
			
		}
		printf("\n\n\tEnter Flavor: ");
		
		fgets(user_flavor,15,stdin);
		user_flavor[0]=toupper(user_flavor[0]);
	
		for (int x=1;x<strlen(user_flavor);x++)
		{
				user_flavor[x]=tolower(user_flavor[x]);	
		}
		user_flavor[strlen(user_flavor) - 1] = '\0';
		
		
		for (int x=0;x<5;x++)
		{		
			if (strcmp(user_flavor,AllFlavors[x])==0)
			{
				found =1;
				break;
			}
		}
		
		if (!found) printf("\nInvalid flavor! Try again.");
	}
	while(!found);
	
	//Cream or Sugar Good Madam?
	
		printf("\n\nDo You want cream (Y/N): ");
		scanf("\n%c",creamPtr);
		tolower(*creamPtr);
		
		while (*creamPtr != 'y' && *creamPtr != 'n' )
		{
			printf("\nNot a valid choice.\n\nDid you want cream (Y/N): ");
			scanf("\n%c",creamPtr);
			tolower(*creamPtr);
		}
		
		
		printf("\n\nDo You want Sugar (Y/N): ");
		scanf("\n%c", sugarPtr);
		tolower(*sugarPtr);
		
		while (*sugarPtr != 'y' && *sugarPtr != 'n')
		{
			printf("\nNot a valid choice.\n\nDid you want sugar (Y/N): ");
			scanf("\n%c",sugarPtr);
			tolower(*sugarPtr);
		}
		
		
	return total;
}

void displayOrder(float total, char cream, char sugar, char *user_size, char *user_flavor)
{
	printf("\n\nYour coffee order:\n\t%s %s coffee ",user_size,user_flavor);
	
	
	if (cream == 'y' && sugar == 'y') printf ("with cream and sugar.");
	else if (cream == 'y') printf("with cream.");
	else if (sugar == 'y') printf("with sugar.");
	
	printf("\n\n\tTotal due: $%.2f",total);
}
