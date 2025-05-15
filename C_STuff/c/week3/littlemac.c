//Devin Combs

#include <stdio.h>
float calculateToll(int type[10], int axels, int x);
void display_all_vel(int count, float toll[10], int vel[10] );
void display_vel_count(int count, float toll[10], int vel[10] );


int main ()
{
	char c = 'y';
	int vel_type[10];
	float toll_amount[10];
	int type, axels;
	int count=0;

	
	
	while (c=='y' || c=='Y' )
	{
		if (count == 10) break;
			
		printf("\nEnter vehicle type (1-Car, 2-Truck, 3-Motorcycle): ");
		scanf("%d",&type);
		while (type != 1 && type != 2 && type != 3)
		{
			printf("\n\nInvalid Choice Try again\nEnter vehicle type (1-Car, 2-Truck, 3-Motorcycle): ");
			scanf("%d",&type);
		}
		
		if (type == 2)
		{
		  printf("\nEnter the number of axles: ");
		  scanf("%d",&axels);
		  
		  while (axels < 2 || axels > 18)
		  {
			  printf("\nInvalid Amount\nEnter the number of axles: ");
			  scanf("%d",&axels);	  	
		  }
		  
		}
		
		if (count < 10)
		{
			vel_type[count] = type;
			toll_amount[count] = calculateToll( vel_type, axels, count);
			count ++;
		}
		
		
		printf("\n\nIs there another vehicle?  Y/N: ");
		scanf("\n%c",&c);
	}
	
	display_all_vel( count, toll_amount, vel_type );
	display_vel_count( count, toll_amount, vel_type );

	
	
	return 0;
}



float calculateToll(int type[10], int axels, int x)
{
	float toll;
	
		switch (type[x])
		{
			case 1:
				toll = 2.50;
				break;
				
			case 2:
				toll = 5 + (axels * 1.5);
				break;
				
			case 3:
				toll = 1;
				
			default:
				break;
			
		}
	
	
	
	return toll;
}



void display_all_vel(int count, float toll[10], int vel[10] )
{
	printf("\n--- Toll Booth Records ---");
	
	for (int x = 0; x < count + 1; x++)
	{
		if (vel[x] == 1) printf("\nCar                       - Toll: $%4.2f",toll[x]);
		if (vel[x] == 2) printf("\nTruck                     - Toll: $%4.2f",toll[x]);
		else if (vel[x] == 3) printf("\nMotorcycle                - Toll: $%4.2f",toll[x]);
	}
	
	
}


void display_vel_count(int count, float toll[10], int vel[10] )
{
	int c = 0, t = 0, m = 0;
	float f_toll;
	
	for (int x = 0; x < count + 1; x++)
		{
			if (vel[x] == 1) c++;
			if (vel[x] == 2) t++; 
			else if (vel[x] == 3) m++;
			
			f_toll += toll[x];
		}
	
	printf ("\n\n\n--- Vehicle Count ---");
	printf("\nTotal Cars:          %d",c);
	printf("\nTotal Trucks:        %d",t);
	printf("\nTotal Motorcycle:    %d",m);
	printf("\n\n\nTotal Revenue:          $%.2f",f_toll);
	
}
