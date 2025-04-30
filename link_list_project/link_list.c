//Devin Combs
//Link List Project

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

struct Inventory
{
	int num;
	int qty;
	float price;	

	struct Inventory *next;

};

void get_choice(char *choice);
struct Inventory* create_list(struct Inventory *first);
void print_list(struct Inventory *first);
void select_item(struct Inventory *first);
void modify_item (struct Inventory *first);
struct Inventory* delete_item(struct Inventory *first);
struct Inventory* insert_item(struct Inventory *first);
void save_list(struct Inventory *first);
struct Inventory* add_list(struct Inventory *first);
void print_help();
void free_list(struct Inventory *first);
int item_num_check(struct Inventory *item, struct Inventory *first);


int main ()
{
	char choice [8];
	char c;
    struct Inventory *first = NULL;
    char endless [10] = "\00/";
		
	while (strcmp(endless, "Youll_never_leave!") != 0)
	{

		get_choice(choice);
		c = 'y';
		
		// Run fuction based on user Choice
		if (strcmp(choice, "create") == 0)
		{
			//If current list is present Warn Them
			if (first != NULL)
			{
				printf("\nYou have a List currently loaded!");
				printf("\nThis will remove the delete the List.");
				printf("\nDo you want to Proceed?  (Y/N) ");
		        scanf(" %c", &c);
		        c = tolower(c);
		
		        while (c != 'y' && c != 'n') {
		            printf("\n\nInvalid Response! Try again.");
					printf("\nDo you want to Proceed?  (Y/N) \n");
		            scanf(" %c", &c);
		            c = tolower(c);
		        }
			}
			
			
			if (c == 'y')first = create_list(first);
		}
		
		else if (strcmp(choice, "print") == 0)
		{
			print_list(first);
		}
		
		else if (strcmp(choice, "select") == 0)
		{
			select_item(first);
		}
		
		else if (strcmp(choice, "modify") == 0)
		{
			modify_item (first);	
		}
		
		else if (strcmp(choice, "delete") == 0)
		{
			first = delete_item(first);
		}
		
		else if (strcmp(choice, "insert") == 0)
		{

			first = insert_item(first);
		}
		
		else if (strcmp(choice, "save") == 0)
		{
			save_list(first);
		}
		
		else if (strcmp(choice, "add") == 0)
		{
			//If current list is present Warn Them
			if (first != NULL)
			{
				printf("\nYou have a List currently loaded!");
				printf("\nThis will remove the delete the List.");
				printf("\nDo you want to Proceed?  (Y/N) ");
		        scanf(" %c", &c);
		        c = tolower(c);
		
		        while (c != 'y' && c != 'n') {
		            printf("\n\nInvalid Response! Try again.");
					printf("\nDo you want to Proceed?  (Y/N) \n");
		            scanf(" %c", &c);
		            c = tolower(c);
		        }
			}
			
			
			if (c == 'y') first = add_list(first);
		}
		
		else if (strcmp(choice, "exit") == 0)
		{
			exit(0);
		}
		
		else if (strcmp(choice, "help") == 0)
		{
			print_help();
		}
		
		else break;
		
		//Clears buffer Yay!

		while ( getchar() != '\n' );

	}


	return 0;
}

void get_choice(char *choice)
{
	char *menuChoices[10]={"create","print","select","modify","delete","insert","save","add","exit","help"};
	int found =0;
	
	printf("----------------------Menu--------------------------\n");
	//Display Menu
	do {
		
		printf("\n(Enter Help to see list commands)");
		printf("\nEnter Command: ");
		fgets(choice,8,stdin);

		choice[strlen(choice) - 1] = '\0';
		
		for (int x=0;x<strlen(choice);x++)
		{
				choice[x]=tolower(choice[x]);	
		}

		
		//test if valid input from string array
		for (int x=0;x<10;x++)
		{		
			if (strcmp(choice,menuChoices[x])==0)
			{
				found =1;
				break;
			}
		}
		
		if (!found) printf("\nInvalid Menu choice!\n\n");
	}
	while(!found);
	
}


struct Inventory* create_list(struct Inventory *first)
{
	//Free Old List Memory
	free_list(first);
	
	//create variables / pointers
	first = NULL;
    struct Inventory *current = NULL;
    struct Inventory *prev = NULL;
    char again;
    int check,count=1;
    
    
    //For Bubble Sort
    int num,qty;
    float price;
    


    printf("\n\n---------------Create List---------------\n");

    do {
        // Set memory for a new item	//based on size of struct Inventory
        current = (struct Inventory*)malloc(sizeof(struct Inventory));

		do {
	        // Get user input
	        printf("\n----New Item----");
	        printf("\nEnter Part Number: ");
	        scanf("%d", &current->num);
	
	        printf("Enter Quantity: ");
	        scanf("%d", &current->qty);
	
	        printf("Enter Price: ");
	        scanf("%f", &current->price);
		}
        //Check If there is already a Item with same part number
		while ((check = item_num_check(current, first)) == 1);

		//Sets next list address to NULL
        current->next = NULL;
        

        // Link the list
          // First item in the list
        if (first == NULL) 
		{
            first = current;
        } 
		else 
		{
          // Link previous item to current using address/next
            prev->next = current;
        }
        

	  	// Move prev forward
        prev = current;

        // Ask if to add another item
        printf("\nDo you want to add another Item? (Y/N) ");
        scanf(" %c", &again);
        again = tolower(again);

        while (again != 'y' && again != 'n') {
            printf("\nInvalid Response! Try again.");
            printf("\nDo you want to add another Item? (Y/N) ");
            scanf(" %c", &again);
            again = tolower(again);
        }
		if (again == 'y') count++;
    } 
	while (again == 'y');


	//Bubble Sort List
		//Sets Y at start as first Item // Runs untill end list // Moves y to next item
	for ( struct Inventory *y = first ; y != NULL; y = y->next)
	{
		//Sets x to be next Item after Y // Runs untill end list // Moves current to next item
		for ( struct Inventory *x = y->next; x != NULL; x = x->next)
		{
			if (y->num > x->num)
			{
				//Swap it all
				num = x->num;
				x->num = y->num;
				y->num = num;
				
				qty = x->qty;
				x->qty = y->qty;
				y->qty = qty;
				
				price = x->price;
				x->price = y->price;
				y->price = price;

			}
		}
	}

    // Clear Buffer Yay!!
    while (getchar() != '\n');

    printf("\nList created!\n");
    printf("\n-----------------------------------------\n\n");
	
	//return first item of the whole connected list
    return first;
	
	
}


void print_list(struct Inventory *first)
{
	printf("\n\n---------------Print List---------------\n");
	//Start at the first list
	struct Inventory *current = first;
	int x=1;
	
	//While current has data in it
	while (current != NULL )
	{
		printf("\n--------Item %d--------",x);
        printf("\n\nPart Number:   %d", current->num);
        printf("\nPart Quantity: %d", current->qty);
        printf("\nPart Price:    $%.2f\n", current->price);
		printf("\n---------------------\n");
		
		//Move to next list
		x++;
		current = current->next;	
	}				

	printf("\n\n-----------------------------------------\n\n");
}

void select_item(struct Inventory *first)
{
	//Get user input for list part number
	int id,found=0;
	char again;
	
	//Start at the first list
	struct Inventory *current = first;
	
	printf("\n\n---------------Select Item---------------\n");
	do 
	{
		printf("\n\nEnter Item's Part Number: ");
		scanf("%d",&id);
		//Runs untill data is Null, aka end of the Link list
		while (current != NULL )
		{
			//Prints only user select list number
			if (current->num == id)
			{
		        printf("\n\nPart Number:   %d", current->num);
		        printf("\nPart Quantity: %d", current->qty);
		        printf("\nPart Price:    $%.2f\n\n", current->price);
		        found = 1;
			}
			
			//Move to next list
			current = current->next;	
		}
		
		
		// No list found with user entered part number, Try again
		if (found == 0)
		{
			printf("\n\nNo List found! Try again? (Y/N) ");
			scanf("\n%c",&again);
			again=tolower(again);
			while (again != 'y' && again != 'n')
			{
				printf("\n\nInvalid Response!");
				printf("\nNo List found! Try again? (Y/N) ");
				scanf("\n%c",&again);
				again=tolower(again);
			}			

			// Exit if they wanna leave
			if (again == 'n') break;

		}				
	}
	while (found == 0);
	printf("\n\n-----------------------------------------\n\n");	

}


void modify_item (struct Inventory *first)
{
	int id,found=0;
	char again;
	
	//Start at the first list
	struct Inventory *current = first;
	
	printf("\n\n---------------Modify Item---------------\n");
	do 
	{
		//Get user input for list part number
		printf("\n\nEnter Item's Part Number: \n\n");
		scanf("%d",&id);
		//Runs untill data is Null, aka end of the Link list
		while (current != NULL )
		{
			//finds The list To modify
			if (current->num == id)
			{	
				//current data in list
				printf("\n\nPart Number:   %d", current->num);
		        printf("\nPart Quantity:   %d", current->qty);
		        printf("\nPart Price:     $%.2f\n\n", current->price);

				//User enters new data
				printf("Change Quantity: ");
				scanf("%d",&current->qty);
				printf("Change Price:  $");
				scanf("%f",&current->price);
				
				//print updated list
				printf("\n\nPart Number:   %d", current->num);
		        printf("\nPart Quantity:   %d", current->qty);
		        printf("\nPart Price:     $%.2f\n\n", current->price);
				
		        found = 1;
		        break;
			}
			
			//Move to next list
			current = current->next;	
		}
		
		
		// No list found with user entered part number, Try again
		if (found == 0)
		{
			printf("\n\nNo List found! Try again? (Y/N) ");
			scanf("\n%c",&again);
			again=tolower(again);
			while (again != 'y' && again != 'n')
			{
				printf("\n\nInvalid Response!");
				printf("\nNo List found! Try again? (Y/N) ");
				scanf("\n%c",&again);
				again=tolower(again);
			}			

			// Exit if they wanna leave
			if (again == 'n') break;

		}				
	}
	while (found == 0);

	printf("\n\n-----------------------------------------\n");
}


struct Inventory* delete_item(struct Inventory *first)
{
	int id,found=0;
	char again;
	
	//Start at the first list
	struct Inventory *current = first;
	struct Inventory *prev = NULL;
	
	printf("\n\n---------------Delete Item---------------\n");
	do 
	{
		//Get user input for list part number
		printf("\n\nEnter Item's Part Number: ");
		scanf("%d",&id);
		//Runs untill data is Null, aka end of the Link list
		while (current != NULL )
		{
			//Find Desired List
			if (current->num == id)
			{
				//If its deleting first list	
				if (prev == NULL)
				{
					//Sets a New first, deleting the old
					first = current->next;
				}
				else
				{
					//Deletes list
					prev->next = current->next;
				}
				
				//Free memory of deleted list
				free(current);
				
		        found = 1;
		        break;
			}
			
			//Move to next list
			prev = current;
			current = current->next;	
		}
		
		
		// No list found with user entered part number, Try again
		if (found == 0)
		{
			printf("\n\nNo List found! Try again? (Y/N) ");
			scanf("\n%c",&again);
			again=tolower(again);
			while (again != 'y' && again != 'n')
			{
				printf("\n\nInvalid Response!");
				printf("\nNo List found! Try again? (Y/N) ");
				scanf("\n%c",&again);
				again=tolower(again);
			}			
			while ( getchar() != '\n' );
			// Exit if they wanna leave
			if (again == 'n') break;

		}				
	}
	while (found == 0);
	if (found == 1) printf("\nList Deleted!\n");

	printf("\n\n-----------------------------------------\n\n");
	return first;
	
}


struct Inventory* insert_item(struct Inventory *first)
{
	struct Inventory *current = first;
	struct Inventory *prev = NULL;
	//Get user input for list part number
	int num, qty;
	float price;
	int check = 0;
	char again;
	
	do
	{
		printf("\n\n---------------Insert Item---------------\n");
		//Make New Item
		struct Inventory* item = 
				//Cast malloc -> pointer //allocate enough bytes to fix inventory
				(struct Inventory*)malloc(sizeof(struct Inventory));
	
		//Get User Data For Item	
		
		printf("\n----New Item----");
		printf("\n\nEnter Part Number: ");
		scanf("%d",&item->num);
		
		printf("\nEnter Quantity: ");
		scanf("%d",&item->qty);
		
		printf("\nEnter Price: ");
		scanf("%f",&item->price);
		printf("\n----------------");
		
		while ( getchar() != '\n' );
		
		//Insert into List
			//Sets Y at start as first Item // Runs untill end list // Moves y to next item
		for ( current; current != NULL; current = current->next)
		{
			//If There is already a Item with same Part Num
			if (item->num == current->num)
			{
				printf("\n\nAlready Item with Part Number %d",item->num);
				printf("\nPlease try again using a availiable Part Number!");
				free(item);
				break;
			}
			//Finds a slot to insert
			else if (item->num < current->num)
			{
				// Insert in Middle
				if (prev != NULL)
				{
				  prev->next = item;
				  item->next=current;
				  printf("\nItem Inserted!\n");
				}
				//Insert at beginning
				else
				{
					item->next=first;
					first = item;
					printf("\nItem Inserted!\n");
				}
				check = 1;
			}
			
			//Its inserted so break out loop
			if (check == 1) break;
			prev = current;
			
		}
		//Insert at end
		if (current == NULL && check == 0)
		{
			prev->next = item;
			item->next = NULL;
			check = 1;
			printf("\nItem Inserted!\n");
		}

		if (check == 1) break;
        // Ask if still wanna try add another item
        printf("\nDo Still want to Insert another Item? (Y/N) ");
        scanf(" %c", &again);
        again = tolower(again);

        while (again != 'y' && again != 'n') {
            printf("\nInvalid Response! Try again.");
            printf("\nDo you want to Insert another Item? (Y/N) ");
            scanf(" %c", &again);
            again = tolower(again);
        }
    	//Clears buffer Yay!
		while ( getchar() != '\n' );
        if (again == 'n') check = 1;
		
	}
	while (check == 0);

	
	printf("-----------------------------------------------\n\n");
	return first;
}

void save_list(struct Inventory *first)
{
	//Step 1: Create a file pointer
	FILE *fp;
	
	//Step 2: Attempt to open
			  //file name  w=write
	fp=fopen("item_list.csv","w");

	//Step 3: Check if file was not found, Terminate programe
	if (fp==NULL)
	{
		printf("Could open file");
		exit(0);
	}
	
	
	
	//Step 4: Read or write to a file
	
	struct Inventory *current = first;

	
	//While current has data in it
	while (current != NULL )
	{
        fprintf(fp,"%d,", current->num);
        fprintf(fp,"%d,", current->qty);
        fprintf(fp,"%.2f\n", current->price);

		
		//Move to next list
		current = current->next;	
	}

	

	//Step 5: Close file
	printf("\nList Saved\n");
	fclose(fp);
}

struct Inventory* add_list(struct Inventory *first)
{
	//Step 1 + 2: Create a file pointer + Attempt to open
	FILE *fp =fopen("item_list.csv","r");

	
	//Step 3: Check if file was not found, Terminate program
	if (fp==NULL)
	{
		printf("Could'nt' open file");
		exit(0);
	}

	
	
	//Step 4: Read or write to a file

	
	//Free Old List Memory
	free_list(first);	
	char line[20]; // takes a whole line of data
	char *sp; //string pointer for commas stuff
	int num,qty;
	float price;
	
	struct Inventory *current = first;
    struct Inventory *prev = NULL;
	first = NULL;
	
	
	while (fgets(line,20,fp)!=NULL)
	{
		//Chuck out Data between the commas, for a whole line
		//Store Data
		
		//strtok (string to be uses,"delimiter for sperating")
		sp=strtok(line,","); //starts at line, stops at comma, pulls into sp
		num=atoi(sp); //convert string to int

		
		sp=strtok(NULL,","); //starts at last NULL, stops at next comma
		qty=atoi(sp); //convert string to int

		sp=strtok(NULL,","); //starts at last NULL, stops at next comma
		price=atof(sp); //convert string to float

       // Set memory for a new item	//based on size of struct Inventory
        current = (struct Inventory*)malloc(sizeof(struct Inventory));

        //Store in new current Item
        
        current->num=num;
        current->qty=qty;
        current->price=price;
		current->next = NULL;

        // Link the list
          // First item in the list
        if (first == NULL) 
		{
            first = current;
        } 
		else 
		{
          // Link previous item to current using address/next
            prev->next = current;
        }

	  	// Move prev forward
        prev = current;	
	}
	

	//Step 5: Close file
	printf("\nList Loaded\n");
	fclose(fp);	
	return first;
}


void print_help()
{
    printf("\nAvailable Commands:\n");
    printf("\tcreate  - Create a new linked list\n");
    printf("\tprint   - Print the entire list\n");
    printf("\tselect  - Print information for one user-selected part number\n");
    printf("\tmodify  - Modify an existing structure\n");
    printf("\tdelete  - Delete an existing structure\n");
    printf("\tinsert  - Insert a new structure into the sorted linked list\n");
    printf("\tsave    - Save a list (to a file)\n");
    printf("\tadd     - Add to an existing list (read from a file)\n");
    printf("\texit    - Exit from the program\n");
    printf("\thelp    - Displays this list of commands\n");
}

void free_list(struct Inventory *first)
{
	struct Inventory *current = first;
    struct Inventory *prev = NULL;
	
	//Free any memory if there is a list already made for new list
	while (current != NULL )
	{
		//Walk down the list liberating THe memory
		prev = current;
		current = current->next;
		free(prev);	
	}
}

int item_num_check(struct Inventory *item, struct Inventory *first)
{
	int check=0;
	struct Inventory *current = first;
	
	for (current; current != NULL; current = current->next)
	{
		if (item->num == current->num)
		{
			printf("\n\nAlready Item with Part Number %d",item->num);
			printf("\nPlease try again using a availiable Part Number!\n");
			check = 1;
			break;
		}
		
	}
	
	return check;
}
