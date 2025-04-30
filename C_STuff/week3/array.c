//Devin Combs

#include <stdio.h>

int main (){
	
	//Array
	// index starts at 0
	int temps[7];
	int avg, total=0;
	
	for (int x = 0; x < 7; x++){
		printf("\nEnter a High temperature for day %d: ",x+1);
		scanf("%d",&temps[x]);

}
printf("\n\n");	
	for (int x = 0; x < 7; x++){
		printf("\nTemp for Day %d is: %d",x+1,temps[x]);
		total+=temps[x];
}
	avg = total / 7;
	printf("\n\nThe Temp average is: %d",avg);
	
	float price[3]={1.99,2.79,3.59};
	
	for (int x = 0; x < 3; x++){
		printf("\nPrice %d: $%.2f",x+1,price[x]);

}

	int sort[5]={6,8,5,2,5};
	
	for (int x=0; x<6; x++){
	sort[x+1] = sort[x];
}



	
	
	
	
	return 0;
}
