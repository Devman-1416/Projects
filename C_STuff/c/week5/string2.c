//Devin Combs
#include <stdio.h>
#include <ctype.h>
#include <string.h>

//toupper()
//tolower()
//strlen()
//strcmp(string1, string2)


int main ()
{

	char birthMonth[15];
	char *allMonth[6]={"Jan", "Feb", "March", "April", "May", "June"};
	int found=0;

	do
	{
		//ask for a string
		printf("\n\nEnter your Birth Month: ");
		fgets(birthMonth,15,stdin);
		
		//conver string to proper upper/lower case like string
		birthMonth[0]=toupper(birthMonth[0]);
		
		for (int x=1;x<strlen(birthMonth);x++)
		{
			birthMonth[x]=tolower(birthMonth[x]);
			
		}
		
		//Get rid of \n from fgets with null
		birthMonth[strlen(birthMonth) - 1] = '\0';
		
		printf("\nNow is %s its",birthMonth);
		
		
		//Go and compare months
		for (int x=0;x<6;x++)
		{
			printf("\n%s - %s ",birthMonth,allMonth[x]);
			//If they Match
			if (strcmp(birthMonth,allMonth[x])==0)
			{
				printf("---------Its a Valid Month!\n\n\n");
				found =1;
				break;
			}
		}
		
		//Didnt find it, continue loop
		if (!found) printf("\n\nNot a valid Month! Try again! ");
	}
	//while true Not opp reverses value
	while(!found);
	
	return 0;
}
