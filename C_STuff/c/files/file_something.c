//Devin Combs 4/22
//Files read and write

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


int main ()
{
	//Step 1: Create a file pointer
	FILE *infp,*outfp;
	
	//Step 2: Attempt to open
			  //file name  w=write
	outfp=fopen("report.txt","w");
						//csv = comman seperated comma
						// can be used with excel
	infp=fopen("refunds.csv","r");


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
	char name[30];
	char city[20];
	char state[3];
	float refund;
	char line[100]; // takes a whole line of data
	char *sp; //string pointer
	
			//gets a whole line fron infp, stops when NULL
	while (fgets(line,100,infp)!=NULL)
	{
		//printf("%s",line);
		//starts at line, stops at , pulls into sp
		sp=strtok(line,",");

		id=atoi(sp); //convert string to int
		printf("%d",id);
		
		sp=strtok(NULL,","); //starts at last NULL, line
		strcpy(name,sp); //copy string to name
		printf("\n%s",name);
		
		sp=strtok(NULL,","); //starts at last NULL, line
		strcpy(city,sp); //copy string to name
		printf("\n%s",name);
		
		sp=strtok(NULL,","); //starts at last NULL, line
		strcpy(state,sp); //copy string to name
		printf("\n%s",name);
		
	}
	

	//Step 5: Close file
	fclose(infp);
	fclose(outfp);

	return 0;
}
