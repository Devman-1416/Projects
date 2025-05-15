//Devin	Combs
#include <stdio.h>
int ask_hospital_days(int id, char l, char f);
int ask_surgery_level(int id, char l, char f);
void ask_medication(int id, char l, char f, float med_prices[10]);

int main()
{
	float med_prices[10];
	float s_prices[5]={1500.00,3250.00,6579.99,12999.99,25450.00};
	float lab_fees[5]={500.00,1025.00,2500.99,5290.00,9875.99};
	int id;
	char f,l;
	
	printf("\nPlease enter paitent's medical ID: ");
	scanf("%d",&id);
	
	printf("\nPlease enter paitent's last initial: ");
	scanf("\n%c",&l);
	
	printf("\nPlease enter paitent's first initial: ");
	scanf("\n%c",&f);
	
	int days=ask_hospital_days(id,f,l);
	int sl=ask_surgery_level(id,f,l);
	
	ask_medication( id, l, f, med_prices);
	
	
	return 0;
}

int ask_hospital_days(int id, char l, char f)
{
	int days;
	printf("\nHow many days did patient %c.%c. #%d stay in the hospital? ",f,l,id);
	scanf("%d",&days);
	
	while (days > 21 || days < 1)
	{
		printf("\nInvalid amount of days, Try again!\nHow many days did patient %c.%c. #%d stay in the hospital? ",f,l,id);
		scanf("%d",&days);
	}
	
	return days;
}

int ask_surgery_level(int id, char l, char f)
{
	int sl;
	printf("\nWhat Surgery Level did patient %c.%c. #%d have (1-5) ",f,l,id);
	scanf("%d",&sl);
	
	while (sl < 1 || sl > 5)
	{
		printf("\nInvalid Level, Try again!\nWhat Surgery Level did patient %c.%c. #%d have (1-5) ",f,l,id);
		scanf("%d",&sl);
	}
	
	return sl;
}

void ask_medication(int id, char l, char f, float med_prices[10])
{
	int num;
	printf("\nHow many medsications were used for patient %c.%c. #%d (up to 10 ): ",f,l,id);
	scanf("%d",&num);
	
	while (num < 1 || num > 10)
	{
		printf("\nHow many medsications were used for patient %c.%c. #%d (up to 10): ",f,l,id);
		scanf("%d",&num);
	}
	
	for (int x=0; x < num; x++)
	{
		printf("\nMedication #%d price: ",x+1);
		scanf("%f",&med_prices[x]);
	
		while (med_prices[x] < 1 )
	{
		printf("\nInvalid Price. Try again!\nMedication #%d price: ",x+1);
		scanf("%f",&med_prices[x]);
	}
		
	}
	
}

int ask_()
{
	
	
	return 0;
}
