//Devin Combs
#include <stdio.h>
char get_flavor();
int get_scoops();
void display_results (int cones, int v, int c, int f, float total);

int main(){
	
	
	char choice = 'a';
	int total_v=0, total_c=0, total_f=0, total_cones=0, scoops=0;
	float total_due;
	
	
	// Menu Loop
	while (choice != 'q' && choice != 'Q' ) {
	
	
	// Get Flavor Choice
	choice = get_flavor();
	
	//Scoops
	if (choice != 'q' && choice != 'Q'){
		scoops = get_scoops();
		total_cones++;
		total_due += .75 + 1.25 * scoops;
	}
	
	// Flavor Counting	
	    switch(choice)
    {
        case'v':case'V':
        	total_v+=scoops;
        	break;
        case'c':case'C':
        	total_c+=scoops;
        	break;
        case'f':case'F':
        	total_f+=scoops;
        	break;
        case'Q':case'q':
        	break;
    }
	
	}
	
	//Display Results
	display_results(total_cones, total_v, total_c, total_f, total_due);
	
	return 0;
}

char get_flavor(){
	char choice;
	printf("\nPlease Choose your Favorite Flavor!");
	printf("\n\n\tV - Vanilla\n\tC - Chocolate\n\tF - Fudge\n\tQ - Quit\n\n\t-----> ");
	scanf("\n%c",&choice);
	
	// Data Validation
	while (choice!='v'&&choice!='V'&&choice!='C'&&choice!='c'&&choice!='F'&&choice!='f'&&choice!='q'&&choice!='Q'){
		printf("\nInvalid Flavor - Please Try again.");	
		printf("\nPlease Choose your Favorite Flavor!");
		printf("\n\n\tV - Vanilla\n\tC - Chocolate\n\tF - Fudge\n\tQ - Quit\n\n\t-----> ");
		scanf("\n%c",&choice);		
	}
	return choice;
}

int get_scoops (){
	int scoops;
	
	do {
	
		printf("\nHow many scoops would you like? ");
		scanf("%d",&scoops);
	
		//  Check Input and clears buffer to stop inifite Loop with char
		if (scoops<1||scoops>4){
			printf("\nInvalid Choice: Must be Between 1 and 4.\nPlease try again!\n");
			while (getchar() != '\n');
		}
	}
	while (scoops<1||scoops>4);
	
	float cost = .75 + 1.25 * scoops;
	printf("\n\n\n\n\nYour ice cream cone cost: $%4.2f\n",cost);
	
	return scoops;
}

void display_results (int cones, int v, int c, int f, float total)
{
	printf("\n\n\nThe total number of cones sold:        %d",cones);
	printf("\n\nThe total scoops of vanilla sold:      %d",v);
	printf("\n\nThe total scoops of chocolate sold:    %d",c);
	printf("\n\nThe total scoops of fudge sold:        %d",f);
	printf("\n\nThe total amount collected:           $%.2f",total);
	
}
