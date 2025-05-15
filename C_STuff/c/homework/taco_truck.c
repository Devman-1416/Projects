//Devin Combs

#include <stdio.h>
char display_menu();
float taco_menu();
float burrito_menu();
float quesa_menu();
float nacho_menu();
void display_totals(int total_t, int total_b, int total_q, int total_n, float total);

int main(){
	
	char choice, menu;
	float cost;
	int count_t=0, count_b=0, count_q=0, count_n=0;
	
	// See if they wanna order
	printf("Welcome to Tomas Taco Truck!\n\n\nWould you like to place an order? Y/N: ");
	scanf("%c",&choice);
	while (choice !='y' && choice !='Y' && choice != 'n' && choice != 'N'){
    	printf("\n\nInvalid Choice! Please try again! Do you want to place a order?: Y/N: ");
    	scanf("\n%c", &choice);	
	}
	
	// They wanna order, menu
	while(choice == 'y' || choice == 'Y')
	{
  		menu=display_menu();
    	switch(menu)
    	{
        	case'T':case't':
        		cost+=taco_menu();
        		count_t++;
        		break;
        		
	        case'B':case'b':
    	    	cost+=burrito_menu();
    	    	count_b++;
        		break;
        		
    	    case'Q':case'q':
        		cost+=quesa_menu();
        		count_q++;
        		break;
        		
       		case'N':case'n':
       			cost+=nacho_menu();
       			count_n++;
        		break;
    	}
		//End of Order			

	
	 // Check if they wanna order more
	 printf("\n\nWould you like to add to your order? Y/N: ");
	 scanf("\n%c",&choice);
		 
		 while (choice !='y' && choice !='Y' && choice != 'n' && choice != 'N')
			{
			printf("\n\nInvalid Choice! Please try again! Do you wanna add to your order? Y/N: ");
  		 	scanf("\n%c", &choice);	
			}
	}
	display_totals(count_t, count_b, count_q, count_n, cost);
		
	return 0;
}

char display_menu()
{
	char choice;
	printf("\n\n\n\nPlease choose from the following menu categories:");
	printf("\n\n\tT-Tacos\n\tB-Burritos\n\tQ-Quesadillas\n\tN-Nachos\n\n\t-----> ");
	scanf("\n%c",&choice);
	
	// Data Validation
  	while(choice != 'T' && choice != 't' && choice != 'b' && choice != 'B' && choice != 'Q' && choice != 'q' && choice != 'n' && choice != 'N'){
    	printf("\n\nInvalid Choice! Please try again! Pick a menu option: ");
    	scanf("\n%c", &choice);
  	}
  	
  return choice;
}

float taco_menu(){
	float cost;
	int choice;
	
	printf("\n\n\t1-Regular Taco:  $1.99");
	printf("\n\t2-Super Taco:    $2.99");
	printf("\n\t3-Veggie Taco:  $1.99");
	printf("\n\n\tChoose a Taco: ");
	scanf("%d",&choice);
	
	// Data Validation
	while(choice!=1 && choice!=2 && choice!=3){
		printf("\n\n\tInvalid Choice! Please try again! Choose a Taco: ");
		scanf("%d",&choice);
	}
	
	switch (choice) {
		case 1: case 3:
			cost = 1.99;
			break;
		
		case 2:
			cost = 2.99;	
			break;
	}
	
	return cost;
}

float burrito_menu(){
	float cost;
	int choice;
	
	printf("\n\n\t1-Regular Burrito:  $2.99");
	printf("\n\t2-Super Burrito:    $3.99");
	printf("\n\t3-Veggie Burrito:  $2.99");
	printf("\n\t4-Bean & Rice Burrito:  $1.99");
	printf("\n\t5-Bean, Rice, & Cheese Burrito:    $1.99");
	printf("\n\t6-Burrito Bowl:  $4.99");
	printf("\n\n\tChoose a Burrito: ");
	scanf("%d",&choice);
	
	// Data Validation
	while(choice!=1 && choice!=2 && choice!=3 && choice != 4 && choice !=5 && choice !=6){
		printf("\n\n\tInvalid Choice! Please try again! Choose a Burrito: ");
		scanf("%d",&choice);
	}
	
	switch (choice) {
		case 1: case 3:
			cost = 2.99;
			break;
		
		case 2:
			cost = 3.99;	
			break;
			
		case 4: case 5:
			cost = 1.99;	
			break;
			
		case 6:
			cost = 4.99;
			break;
	}
		
	return cost;
}

float quesa_menu(){
	float cost;
		int choice;
	
	printf("\n\n\t1-Regular Quesadilla:  $1.99");
	printf("\n\t2-Meat Quesadilla:    $2.99");
	printf("\n\t3-Beef Quesadilla:  $1.99");
	printf("\n\t4-Super Quesadilla:   $4.99");
	printf("\n\n\tChoose a Quesadilla: ");
	scanf("%d",&choice);
	
	// Data Validation
	while(choice!=1 && choice!=2 && choice!=3 && choice !=4){
		printf("\n\n\tInvalid Choice! Please try again! Choose a Quesadilla: ");
		scanf("%d",&choice);
	}
	
	switch (choice) {
		case 1:
			cost = 1.99;
			break;
		
		case 2:
			cost = 2.99;	
			break;
			
		case 3:
			cost = 3.99;	
			break;
			
		case 4:
			cost = 4.99;	
			break;
	}
	
	return cost;
}

float nacho_menu(){
	float cost;
	int choice;
	char cheese;
	
	printf("\n\n\t1-Regular Nacho:  $3.99");
	printf("\n\t2-Super Nacho:    $5.99");
	printf("\n\n\tChoose a Nacho: ");
	scanf("%d",&choice);
	
	// Data Validation
	while(choice!=1 && choice!=2){
		printf("\n\n\tInvalid Choice! Please try again! Choose a Nacho ");
		scanf("%d",&choice);
	}
	
	printf("\n\tWould you like extra cheese for $1.00? Y/N: ");
	scanf("\n%c",&cheese);
	
	while(cheese!='y' && choice!='Y' && cheese!='n' && cheese!='N'){
		printf("\n\n\tInvalid Choice! Please try again! Extra Cheese? Y/N: ");
		scanf("\n%c",&cheese);
	}
	
	
	switch (choice) {
		case 1:
			cost = 3.99;
			break;
		
		case 2:
			cost = 5.99;	
			break;
	}
	
	if (cheese == 'y' || cheese =='Y') cost++;
	
	return cost;
}

void display_totals(int total_t, int total_b, int total_q, int total_n, float total){
	printf("\n\nYour order consists of: \n");
	if (total_t>0) printf("\n\tTotal Tacos:        %d",total_t);
	if (total_b>0)printf("\n\tTotal Burritos:     %d",total_b);
	if (total_q>0)printf("\n\tTotal Quesadillias: %d",total_q);
	if (total_n>0)printf("\n\tTotal Nachos:       %d",total_n);
	printf("\n\n\n\tTotal Due:   $%.2f",total);
	
	printf("\n\n\nThank you for choosing Tomas Taco Truck!");
}
