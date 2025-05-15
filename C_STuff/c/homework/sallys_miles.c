//Devin Combs
#include <stdio.h>
short int calc_total_driven(short int m1, short int m2, short int m3);
short int calc_average(short int m1, short int m2);
unsigned short int calc_total_miles (short int m1, short int m2);

int main(){
	
	// Variables
	short int start_miles = 27920, daily_miles = 6213, trip1 = 2490, trip2 = 2780;
	
	// Get Results
	short int total_driven = calc_total_driven(daily_miles, trip1, trip2);
	short int average_miles = calc_average(trip1,trip2);
	unsigned short int total_miles = calc_total_miles(total_driven,start_miles);
	
	// Display Output
	printf("Sally's Miles");
	printf("\n\nTotal Miles Driven: %hd",total_driven); //11483
	printf("\nAverage Trip Miles: %hd",average_miles); //2635
	printf("\nCurrent Miles:      %hu",total_miles); //39403
	
	return 0;
}

short int calc_total_driven(short int m1, short int m2, short int m3){
	short int td = m1 + m2 + m3;
	return td;
}

short int calc_average(short int m1, short int m2){
	short int a = (m1 + m2) /2;
	return a;
}

unsigned short int calc_total_miles (short int m1, short int m2){
	short int tm = m1 + m2;
	return tm;
}

