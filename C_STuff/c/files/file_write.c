//Devin Combs
//Files write

#include <stdio.h>
#include <ctype.h>
#include <string.h>

//For exit(0)
#include <stdlib.h> 


int main ()
{
	//Step 1: Create a file pointer
	FILE *fp;
	
	//Step 2: Attempt to open
			  //file name  w=write
	fp=fopen("payroll.txt","w");

	//Step 3: Check if file was found, Terminate programe
	if (fp==NULL)
	{
		printf("Could open file");
		exit(0);
	}
	
	
	
	//Step 4: Read or write to a file
	int id;
	float hours,rate;
	
	for(int x=0;x<5;x++)
	{
		printf("\nEnter id: ");
		scanf("%d",&id);
		
		printf("Enter Hours: ");
		scanf("%f",&hours);
		
		
		printf("Enter rate: ");
		scanf("%f",&rate);
		
		//prints to file						\n at the end!
		fprintf(fp,"%d %.2f %.2f\n",id,hours,rate);
	}

	

	//Step 5: Close file
	fclose(fp);

	return 0;
}
