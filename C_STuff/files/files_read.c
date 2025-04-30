//Devin Combs 4/22
//FIles Read

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main ()
{
	//Step 1: Create a file pointer
	FILE *fp;
	
	//Step 2: Attempt to open
			  //file name  w=write
	fp=fopen("payroll.txt","r");

	//Step 3: Check if file was found, Terminate programe
	if (fp==NULL)
	{
		printf("Could open file");
		exit(0);
	}
	
	
	//Step 4: Read or write to a file
	int id;
	float hours,rate;
	int em; //ending marker
	//Reads data in order from file, store in variables
	em = fscanf(fp,"%d%f%f",&id,&hours,&rate);
	while (em!=EOF)
	{
		printf ("\nID: %d   Hours: %.2f  Rate %.2f",id,hours,rate);
		em = fscanf(fp,"%d%f%f",&id,&hours,&rate);
	}
	
	
	
	

	//Step 5: Close file
	fclose(fp);


}



