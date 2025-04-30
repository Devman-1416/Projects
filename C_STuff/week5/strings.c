//Devin Combs 4/16
//Pointers

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main ()
{
	// String: array of Characters
	// C-strings
	
	
	char greeting[6]={"Hello"};
	char name[10];
	char message[6];
	//Stored as H E L L O \0	\0 = NULL char

	printf("\nName: \n\n\n");
	
	//End on blank space, so a space
		//scanf("%s",name);
	
	// gets string: enter string and ignore blank space
		//gets(name); dangours memory overide
	
	//Use fgets	
		//Where put it,size,standord input/keyboard
	fgets(name,10,stdin);
	
	int x=0;
	while (greeting[x] != '\0')
	{
		printf("|%c|",greeting[x]);
		message[x] = greeting[x];
		x++;
	}
	//Add the null char
	message[x]='\0';
	
	printf("\n\n%s %s",greeting,name);
	
	
	
	char *allMonth[6]={"Jan", "Feb", "March", "April", "May", "June"};
	
	
	return 0;
}
