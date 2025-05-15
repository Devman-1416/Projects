//Devin Combs


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void playLevel(int level, int *answerPtr);
int spinWheel();
int determineLevelUp(int num, int *levelPtr, int answer);

int main ()
{
	int level = 1,answer, health=50;
	
	
	while ( level > 0)
	{
		playLevel(level,&answer);
		int num=spinWheel();
		health -= determineLevelUp( num, &level, answer);
	
		//Won the Game
		if (level==4)
		{
			printf("\n\nYou Won The Game!\nThanks for playing.\nRemaining Health: %d",health);
			break;
		}
		
		//Loss the Game
		else if (health < 1)
		{
			printf("\n\nHealth below 0: You Lost The Game!\nThanks for playing.");
			break;
		}
		
		//Display Current Health
		printf("\n\nHealth: %d",health);
	}

	
	
	return 0;
}

void playLevel(int level, int *answerPtr)
{
	if (level == 1)
	 {
		printf("\n\nLevel 1:  Choose odd (1) or even (2): ");
		scanf("%d",answerPtr);
		
		while (*answerPtr != 1 && *answerPtr != 2)
		{
			printf("\n\nInvalid Choice. Try again!");
			printf("\nLevel 1:  Choose odd (1) or even (2): ");
			scanf("%d",answerPtr);
		}
		
	 }
	 

	else if (level == 2)
	 {
		printf("\n\nLevel 2:  Find the dozen (1st, 2nd or 3rd) ->(1-12) or (13-24) or (25-36): ");
		scanf("%d",answerPtr);
		
		while (*answerPtr != 1 && *answerPtr != 2 && *answerPtr != 3)
		{
			printf("\n\nInvalid Choice. Try again!");
	 		printf("\nLevel 2:  Find the dozen (1st, 2nd or 3rd) ->(1-12) or (13-24) or (25-36): ");
			scanf("%d",answerPtr);
		}
		
	 }
	 
	else 
	 {
		printf("\n\nLevel 3:  Choose the number (0-36): ");
		scanf("%d",answerPtr);
		
		while (*answerPtr < 0 || *answerPtr > 36)
		{
			printf("\n\nInvalid Choice. Try again!");
			printf("\nLevel 3:  Choose the number (0-36): ");
			scanf("%d",answerPtr);
		}
		
		
	 }		 
	
	
}


int spinWheel()
{
	
	srand(time(0));
	int num=rand() % 35;
	
	return num;

}

int determineLevelUp(int num, int *levelPtr, int answer)
{
	int damage=0;
	
//-------------------------------Level 1---------------------------------
	if (*levelPtr == 1)
	 {
	 	//Odd wins
		if (num%2 != 0 && answer == 1) 
		{
			(*levelPtr)++;
			printf("\n\nYour Correct, its odd! Number is: %d.   Level UP!",num);
		}
		//Even wins
		else if (num%2 == 0 && answer == 2)
		{
			(*levelPtr)++;
			printf("\n\nYour Correct, its even! Number is: %d.  Level UP!",num);
		}
		//loss
		else
		{
			damage=2;
			if (num%2 ==0) printf("\n\nYour Wrong, its even! Number was: %d\nTake 2 points of damage!",num);
			else printf("\n\nYour Wrong, its odd! Number is: %d\nTake 2 points of damage!",num);
		}	

	 }
	 

//-------------------------------Level 2---------------------------------
	else if (*levelPtr == 2)
	 {
	 	//First Range
		if (answer == 1 && num > 0 && num < 13)
		{
			(*levelPtr)++;
			printf("\n\nCorrect Range (1-12)! Number is: %d.   Level UP!",num);	
		}
		
		//Second Range
		else if (answer == 2 && num > 12 && num < 25)
		{
			(*levelPtr)++;
			printf("\n\nCorrect Range (13-24)! Number is: %d.   Level UP!",num);	
		}
		
		//Third Range
		else if (answer == 3 && num > 24 && num < 37)
		{
			(*levelPtr)++;
			printf("\n\nCorrect Range (25-36)! Number is: %d.   Level UP!",num);	
		}
		
		else 
		{
			(*levelPtr)--;
			printf("\n\nWrong Range Choice! Number is: %d\nLevel Down! Take 5 points of damage!",num);
			damage=5;
				
		}
		
	 }
	 
//-------------------------------Level 3---------------------------------
	else 
	 {
		if (answer == num)
		{
			printf("\n\nYour Correct! Number is: %d.",num);
			(*levelPtr)++;
		}
		
		//Within 5
		else if (abs(num - answer) < 6)
		{
			damage=3;
			printf("\nYour Number: %d.   Your off by: %d\nTake 3 points of damage!",answer,abs(num - answer));
		}
		
		//Within 10
		else if (abs(num - answer) > 5 && abs(num - answer) < 11 )
		{
			damage=6;
			printf("\nYour Number: %d.   Your off by: %d\nTake 6 points of damage!",answer,abs(num - answer));
		}
		
		//Really off
		else 
		{
			damage=9;
			(*levelPtr)--;
			printf("\nYour Number: %d.   Your off by: %d\nLevel Down! Take 9 points of damage!",answer,abs(num - answer));
		}
		
	 }
	
	
	return damage;
} 
