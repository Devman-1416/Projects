//Devin Combs 4/22
//FIles read and write

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main ()
{
	//Step 1: Create a file pointer
	FILE *infp,*outfp;
	
	//Step 2: Attempt to open
			  //file name  w=write
	infp=fopen("payroll.txt","r");
						//csv = comman seperated comma
						// can be used with excel
	outfp=fopen("report.csv","w");


	//Step 3: Check if file was found, Terminate programe
	if (infp==NULL)
	{
		printf("Error Reading File!");
		exit(0);
	}
	
	if (outfp==NULL)
	{
		printf("Error Writing File!");
		exit(0);
	}
	
	
	//Step 4: Read or write to a file
	int id;
	float hours,rate,pay;
	int em; //ending marker
	//Reads data in order from file, store in variables
	em = fscanf(infp,"%d%f%f",&id,&hours,&rate);
	fprintf(outfp,"ID,Hours,Rate,Gross Pay\n");
	
	while (em!=EOF)
	{	
		fprintf(outfp,"%d,%.2f,%.2f,%.2f\n",id,hours,rate);
		em = fscanf(infp,"%d%f%f",&id,&hours,&rate);
	}
	
	

	//Step 5: Close file
	fclose(infp);
	fclose(outfp);

	return 0;
}
