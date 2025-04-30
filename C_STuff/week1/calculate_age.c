// Devin Combs

#include <stdio.h>


int main(){

int current_year, birth_year, age;

printf("What year were you born? ");
scanf("%d",&birth_year);

printf("What year is it? ");
scanf("%d",&current_year);

age = current_year - birth_year;

printf(" In %d you will be %d " , current_year, age);


return 0;
}
