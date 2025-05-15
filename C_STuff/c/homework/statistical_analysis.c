//Devin Combs


#include <stdio.h>
#define MAX 10
int get_data(int nums[MAX]);
void display_data(int nums[MAX]);
int display_largest(int nums[MAX]);
int display_smallest(int nums[MAX]);
void display_average(int nums[MAX]);
void display_Range(int largest, int smallest);
void display_median(int nums[MAX]);
void display_mode(int nums[MAX]);

int main()
{
	int nums[MAX];
	
	
	get_data(nums);
	display_data(nums);
	
	int largest = display_largest(nums);
	int smallest = display_smallest(nums);
	
	display_average(nums);
	display_Range(largest,smallest);
	display_median(nums);
	display_mode(nums);
	
	return 0;	
}

int get_data(int nums[MAX])
{
	printf("Enter %d Numbers\n\n",MAX);
	for (int x=0;x<MAX;x++)
	{
		printf("\tNumber #%d: ",x+1);
		scanf("%d",&nums[x]);
	}
	
}

void display_data(int nums[MAX])
{
	int a;
	printf("\n\nYour Number List: ");
	for (int x=0;x<MAX;x++) printf(" |%d| ",nums[x]);
	
		//Sort
	for (int y=0; y<MAX ;y++)
	{
		for(int x=0 ; x<MAX-1 ;x++)
		{
			if (nums[x] > nums[x+1])
			{
			a = nums[x+1];
			nums[x+1] = nums[x];
			nums[x] = a;
			}
		}
	}
	
	printf("\n\n\nSorted: ");
	for(int x=0; x < MAX; x++) printf(" |%d| ",nums[x]);
}

int display_largest(int nums[MAX])
{
	int largest=0;	
	for (int x=0;x<MAX;x++)
	{
		if (nums[x] > largest) largest=nums[x];			
	}
	printf("\n\nThe Largest Number is: %d",largest);
	return largest;
}

int display_smallest(int nums[MAX])
{
	int smallest=nums[0];
		
	for (int x=0;x<MAX;x++)
	{
		if (nums[x] < smallest) smallest=nums[x];			
	}
	printf("\n\nThe Smallest Number is: %d",smallest);
	return smallest;
}

void display_average(int nums[MAX])
{
	float sum=0;	
	for (int x=0;x<MAX;x++)
	{
		sum+=nums[x];			
	}
	float average=sum/MAX;
	
	printf("\n\nThe Average is: %.1f",average);
}

void display_Range(int largest, int smallest)
{
	int range = largest - smallest;		
	printf("\n\nThe Range is: %d",range);
}

void display_median(int nums[MAX])
{
	
	//Mid points
	int mid1 = MAX/2, mid2 = mid1-1;
	float median;
	
	//Check if even or odd numbers in array
	if (MAX%2==0)
	{
		//Even Number
		median = (nums[mid1] + nums[mid2])/2.0;

		printf("\n\nThe Median is: %.1f    Mid1:%d    Mid2:%d",median,nums[mid1],nums[mid2]);
	}
	else
	{
		//Odd Number
		median = nums[MAX/2];
		printf("\n\nThe Median is: %.1f",median);
	}
	
}

void display_mode(int nums[MAX])
{
	int a;
	
	//Sort
	for (int y=0; y<MAX ;y++)
	{
		for(int x=0 ; x<MAX-1 ;x++)
		{
			if (nums[x] > nums[x+1])
			{
			a = nums[x+1];
			nums[x+1] = nums[x];
			nums[x] = a;
			}
		}
	}
	
	// My gosh, this took alot longer than I thought lol..
	int count=1, max_count=0, modes[MAX],indent=0;
	for (int y=0; y<MAX;y++)
	{
		if (nums[y]==nums[y+1]) count++;
		else
		{
			if(count>max_count)
			{
				max_count=count;
				indent=0;
				modes[indent++]=nums[y-1];
			}
			else if (count==max_count) modes[indent++]=nums[y];
			
			count=1;
		}
	}
	
	for (int x=0; x<indent; x++)
	{
		printf("\n\nThe Mode is: %d\nIt appears %d times",modes[x],max_count);	
	}
}

//Riddle

	//I heed no master.
	//I move with no purpose.
	//The trees dance when I pass.
	//My bite chills to the bone.
	//My touch gentle and warm.
	//What am I?
