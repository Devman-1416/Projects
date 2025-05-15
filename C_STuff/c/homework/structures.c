//Devin Combs 4/21
//File Strucutres

#include <stdio.h>
#include <ctype.h>
#include <string.h>

//Struture -stars with cap for name
//not store in memory, like defintion
struct Inventory
{
	int num;
	char des[30];
	int qty;
	float price;	

};

void load_all_parts(struct Inventory allParts[]);
void display(struct Inventory allParts[]);

int main ()
{

	//Calls structures, stores in memory
	//|____A1____|
	//|__________|
	//|__________|
	//|__________|
	//|	  Part	 |
	struct Inventory part, part2={22,"Driver",2,120.99};
	part.num=111;
	part.qty=10;
	part.price=1.99;

	strcpy(part.des,"Hammer");

	
	//printf("\n%d %s %d $%.2f",part.num,part.des,part.qty,part.price);
	//printf("\n%d %s %d $%.2f",part2.num,part2.des,part2.qty,part2.price);

	//struct Inventory part3;
	//printf("\n\nEnter part Number: ");
	//scanf("%d",&part3.num);
	
	//Get rid of \n for fgets
	//getchar();
	//printf("\nEnter Description: ");
	//fgets(part3.des,30,stdin);

	
	//printf("\nEnter Quantity: ");
	//scanf("%d",&part3.qty);


	//printf("\nEnter Price: ");
	//scanf("%f",&part3.price);

	//printf("\n%d %s %d $%.2f",part3.num,part3.des,part3.qty,part3.price);

	struct Inventory allParts[3];
	
	load_all_parts(allParts);
	display(allParts);

	return 0;
}

void display(struct Inventory *allParts)
{
	for (int x=0;x<3;x++)
	{
		//printf("\n\nPart Number: %d\nDescription: %s\nQuanity: %d\nPrice: $%.2f\n\n",
					//allParts[x].num,allParts[x].des,allParts[x].qty,allParts[x].price);
					
		printf("\n\nPart Number: %d\nDescription: %s\nQuanity: %d\nPrice: $%.2f\n\n",
					allParts->num,allParts->des,allParts->qty,allParts->price);
		allParts++; //Increment the address for the loop		
	}
}

void load_all_parts(struct Inventory allParts[])
{
	for (int x=0; x<3; x++)
	{
	
	printf("\n\nEnter part Number: ");
	scanf("%d",&allParts[x].num);
	
	//Get rid of \n in string for fgets
	getchar();
	printf("Enter Description: ");
	fgets(allParts[x].des,30,stdin);
	allParts[x].des[strlen(allParts[x].des) - 1] = '\0';
	
	printf("Enter Quantity: ");
	scanf("%d",&allParts[x].qty);


	printf("Enter Price: ");
	scanf("%f",&allParts[x].price);
	
	}
	
	
	
}

