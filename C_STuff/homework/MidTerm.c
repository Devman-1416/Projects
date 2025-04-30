// Devin Combs

#include <stdio.h>
int show_menu();
void add_request(char pick_ups[10],int driver_counts[4]);
int assign_request(char pick_ups[10], char unsigned_pick_ups[10], int driver_counts[4], int total_request);
void print_driver_summary(char unsigned_pick_ups[10], int driver_counts[4], int count_unsign);




int main ()

{
	
	char pick_ups[10] = {'x','x','x','x','x','x','x','x','x','x'};
	char unsigned_pick_ups[10] = {'x','x','x','x','x','x','x','x','x','x'};
	int driver_counts[4] = {0,0,0,0};
	int choice = 0, count_unsign=0, total_request=0;
	
	while(choice!= 4)
   {
	    switch(choice)
	    {
	        case 1:
	        	add_request(pick_ups,driver_counts);
	        	total_request++;
	        	break;
	        	
	        case 2:
				count_unsign = assign_request(pick_ups,unsigned_pick_ups,driver_counts,total_request);
	        	break;
	        	
	        case 3:
				print_driver_summary(unsigned_pick_ups, driver_counts, count_unsign);
	        	break;

    	}
    	
    	choice = show_menu();
    }

	

	
	return 0;
}


int show_menu()
{
	int choice;
	
	
	printf("\n\nDriver Dispatch Menu");
	printf("\n1. Add a pickup request");
	printf("\n2. Assign Drivers");
	printf("\n3. View driver assignments");
	printf("\n4. Exit");
	printf("\nChoose an option: ");
	scanf("%d",&choice);
	
	while(choice < 1 || choice > 4)
	{

		printf("\n\nInvalid option: Pick from the menu (1-4)\n");		
		printf("\nDriver Dispatch Menu");
		printf("\n1. Add a pickup request");
		printf("\n2. Assign Drivers");
		printf("\n3. View driver assignments");
		printf("\n4. Exit");
		printf("\nChoose an option: ");
		scanf("%d",&choice);
			
	}
	
	return choice;
	
}

void add_request(char pick_ups[10],int driver_counts[4])
{
	char driver;
	
	printf("\n\nChoose a driver:  (A/B/C/D): ");
	scanf("\n%c",&driver);
	
	while(driver != 'A' && driver != 'a' && driver != 'B' && driver != 'b' && driver != 'C' && driver != 'c' && driver != 'D' && driver != 'd')
	{

		printf("\nInvalid Driver! Please pick from the list.");
		printf("\n\nChoose a driver:  (A/B/C/D): ");
		scanf("\n%c",&driver);
			
	}
	
	if (driver == 'a') driver = 'A';
	else if (driver == 'b') driver = 'B';
	else if (driver == 'c') driver = 'C';
	else if (driver == 'd') driver = 'D';
	
	for (int x=0; x<10; x++)
	{
		if (pick_ups[x] == 'x')
		{
			pick_ups[x] = driver;
			printf("\n\tRequest added successfully.");
			break;
		}
	}
	
	printf("\n\nCurrent Pickup Requests:     ");
	for (int x=0; x<10; x++)
	{
		printf("%c  ",pick_ups[x]);
	}
	
}



int assign_request(char pick_ups[10], char unsigned_pick_ups[10], int driver_counts[4], int total_request)
{
	int total_unsign =0;
	
	for (int x=0; x<total_request; x++)
	{
		
		if (pick_ups[x] == 'A')
		{
			driver_counts[0]++;
			if (driver_counts[0] > 3)
			{
				unsigned_pick_ups[total_unsign] = pick_ups[x];
				total_unsign++;
			}
		}
		
		if (pick_ups[x] == 'B')
		{
			driver_counts[1]++;
			if (driver_counts[1] > 3)
			{
				unsigned_pick_ups[total_unsign] = pick_ups[x];
				total_unsign++;
			}
		}
		
		if (pick_ups[x] == 'C')
		{
			driver_counts[2]++;
			if (driver_counts[2] > 3)
			{
				unsigned_pick_ups[total_unsign] = pick_ups[x];
				total_unsign++;
			}
		}
		
		if (pick_ups[x] == 'D')
		{
			driver_counts[3]++;
			if (driver_counts[3] > 3)
			{
				unsigned_pick_ups[total_unsign] = pick_ups[x];
				total_unsign++;
			}
		}
		
	}
	

	
	return total_unsign;
	
}



void print_driver_summary(char unsigned_pick_ups[10], int driver_counts[4], int count_unsign)
{
//	printf("\n\nUnassigned requests due to full capacity: $d",)
	printf("\n\nDriver Assignment Summary");
	
	if (driver_counts[0] < 3)
	{
		printf("\n\nDriver A : \n\tTotal Pickups:  %d",driver_counts[0]);
	}
	else
	{
		printf("\n\nDriver A : \n\tTotal Pickups:  3");
		printf("          (Driver is at full capacity)");
	}

	if (driver_counts[1] < 3)
	{
		printf("\n\nDriver B : \n\tTotal Pickups:  %d",driver_counts[1]);
	}
	else
	{
		printf("\n\nDriver B : \n\tTotal Pickups:  3");
		printf("          (Driver is at full capacity)");
	}
	
	if (driver_counts[2] < 3)
	{
		printf("\n\nDriver C : \n\tTotal Pickups:  %d",driver_counts[2]);
	}
	else
	{
		printf("\n\nDriver C : \n\tTotal Pickups:  3");
		printf("          (Driver is at full capacity)");
	}
	
	if (driver_counts[3] < 3)
	{
		printf("\n\nDriver D : \n\tTotal Pickups:  %d",driver_counts[3]);
	}
	else
	{
		printf("\n\nDriver D : \n\tTotal Pickups:  3");
		printf("          (Driver is at full capacity)");
	}
	
	
	printf("\n\nUnassigned requests due to full capacity: %d",count_unsign);
	printf("\nUnassigned Pick ups      ");
	

		for (int x=0; x<count_unsign; x++)
	{
		printf("%c  ",unsigned_pick_ups[x]);

	}
	
}





