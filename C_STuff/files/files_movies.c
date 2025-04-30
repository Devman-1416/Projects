//De//Devin Combs 4/23
//FIles Read

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
struct Movies
{
	char name [20];
	char rating [5];
	int minutes;
	int stars;
	
};

int main ()
{
	//Step 1 + 2: Create a file pointer + Attempt to open
	FILE *fpin =fopen("movies.csv","r");
	FILE *fpout =fopen("movies.txt","w");
	

	//Step 3: Check if file was found, Terminate program
	if (fpin==NULL)
	{
		printf("Could open file");
		exit(0);
	}
	
	if (fpout==NULL)
	{
		printf("Could Make file");
		exit(0);
	}
	
	
	//Step 4: Read or write to a file
	struct Movies movie[5];
	int x=0;
	int count_mins=0;
	int count_stars=0;
	

	char line[100]; // takes a whole line of data
	char *sp; //string pointer
	
			//gets a whole line fron fp, stops when NULL
			
	fprintf(fpout,"%-30s%-20s%-20s%-20s","Name","Rating","Minutes","Stars");
	fprintf(fpout,"\n----------------------------------------------------------------------------\n");
	
	while (fgets(line,50,fpin)!=NULL)
	{
		//Chuck out Data between the commas, for a whole line
		
		//strtok (string to be uses,"delimiter for sperating")
		sp=strtok(line,","); //starts at line, stops at comma, pulls into sp
		strcpy(movie[x].name,sp); //copy string to name
		fprintf(fpout,"%-30s",movie[x].name);
		
		sp=strtok(NULL,","); //starts at last NULL, stops at next comma
		strcpy(movie[x].rating,sp); //copy string to name
		fprintf(fpout,"%-20s",movie[x].rating);
		
		sp=strtok(NULL,","); //starts at last NULL, stops at next comma
		movie[x].minutes=atoi(sp); //convert string to int
		count_mins += movie[x].minutes;
		fprintf(fpout,"%-20d",movie[x].minutes);
		
		sp=strtok(NULL,","); //starts at last NULL, stops at next comma
		movie[x].stars=atoi(sp); //convert string to int
		count_stars += movie[x].stars;
		fprintf(fpout,"%-20d\n",movie[x].stars);
		
		x++;
		
	}
	fprintf(fpout,"\n----------------------------------------------------------------------------\n");
	fprintf(fpout,"\n\nAverage Minutes: %.2f",(float)count_mins/x);
	fprintf(fpout,"\nAverage Stars: %.2f\n\n\n\n",(float)count_stars/x);
	
	
	

	//Step 5: Close file
	fclose(fpin);
	fclose(fpout);
	
	
	
}
