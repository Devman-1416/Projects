// Devin Combs

#include <stdio.h>
#include <ctype.h>

int main(){

	/*
	int grade;
	
	printf("Enter your grade: ");
	scanf("%d", &grade);
	
	if (grade >= 90) printf("A");
	else if (grade >=80) printf("B");
	else if (grade >=70) printf("C"); 
	else if (grade >=60) printf("D"); 
	else printf("E");
	
	int age;
	printf("Enter your age: ");
	scanf("%d", &age);
	
	if (age >= 18) 
	{
		printf("\nYou may enter!");
		if (age >=21) printf("\nYou may drink!");
	}
	else printf("\nYour too young.");
	*/
	  

	char status;

	printf("Enter your Status: ");
	scanf("%c", &status);
	
	//Requiers #include <ctype.h>
		//status = toupper(status);
	
	// Using Char binary math
	if (status >= 97) status=status - 32;
	
	// Only Int and Chars in Switch
	switch(status)
	{
		case 'S':
			printf("Single");
			break;
			
		case 'M': case 'm': 
			printf("Married");
			break;
			
		case 'D': 
			printf("Divorced");
			break;
	
		case 'E': case 'e': 
			printf("Engaged");
			break;
	
		case 'W': case 'w': 
			printf("Widowed");
			break;
			
		default:
			printf("Invalid");
					
	}






	  
	
	
	printf("\n\n");
	return 0;
}
