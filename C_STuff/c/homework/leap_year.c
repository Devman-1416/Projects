//Devin Combs
#include <stdio.h>


int main(){
	// Month, Day, Year
	int m,d,y;
	
	// Get input
	printf("\nEnter Your Date of Birth: ");
	scanf("%d/%d/%d", &m, &d, &y);

	// Check if leap Year, 1 = yes | 0 = no
	int num1 = y % 400;
	int num2 = y % 100;
	int leap;
	
	if (num1 == 0){
		leap = 1;
	}
	else if (num1 != 0)
	{
		num1 = y % 4;
		if (num1 == 0 && num2 != 0) leap = 1;
		else leap = 0;
	}

	// Display Results
		switch(m)
	{
		case 1:
			printf("\nYour birthday, January %d, %d, ",d,y);
			break;
			
		case 2: 
			printf("\nYour birthday, Febuary %d, %d, ",d,y);
			break;
			
		case 3: 
			printf("\nYour birthday, March %d, %d, ",d,y);
			break;
	
		case 4: 
			printf("\nYour birthday, April %d, %d, ",d,y);
			break;
		
		case 5: 
			printf("\nYour birthday, May %d, %d, ",d,y);
			break;
		
		case 6: 
			printf("\nYour birthday, June %d, %d, ",d,y);
			break;
		
		case 7: 
			printf("\nYour birthday, July %d, %d, ",d,y);
			break;
		
		case 8: 
			printf("\nYour birthday, August %d, %d, ",d,y);
			break;
		
		case 9: 
			printf("\nYour birthday, September %d, %d, ",d,y);
			break;
		
		case 10: 
			printf("\nYour birthday, October %d, %d, ",d,y);
			break;
		
		case 11: 
			printf("\nYour birthday, November %d, %d, ",d,y);
			break;
		
		case 12: 
			printf("\nYour birthday, December %d, %d, ",d,y);
			break;
			
		default:
			printf("\n Invalid Month, %d",y);
					
	}
	
	if (leap == 1) printf("is a leap year.");
	else printf("is not a leap year.");0
	
	return 0;
	
}
