//Devin Combs
#include <stdio.h>
#include <ctype.h>
#include <string.h>
int count_vowels(int vowel_counts[5], char string[100]);

int main ()
{

	char string[100];
	int vowel_counts[5]={0,0,0,0,0};

	
	printf("Enter a String: ");
	fgets(string,100,stdin);
	int x=0;
	

	int total_vowels = count_vowels(vowel_counts, string);
	
	printf("\n%s\n\nTotal",string);
	
	printf("\t A's: %d",vowel_counts[0]);
	printf("\n\t E's: %d",vowel_counts[1]);
	printf("\n\t I's: %d",vowel_counts[2]);
	printf("\n\t O's: %d",vowel_counts[3]);
	printf("\n\t U's: %d",vowel_counts[4]);
	printf("\n\n\e[1mTotal vowels: %d\e[m",total_vowels);
	
	

	return 0;
}

int count_vowels(int vowel_counts[5], char string[100])
{
	int total=0;
	
	for (int x=1;x<strlen(string);x++)
	{
		switch (string[x])
		{
			case 'a': case 'A':
				vowel_counts[0] ++;
				total++;
				break;
				
			case 'e': case 'E':
				vowel_counts[1] ++;
				total++;
				break;;
				
			case 'i': case 'I':
				vowel_counts[2] ++;
				total++;
				break;
				
			case 'o': case 'O':
				vowel_counts[3] ++;
				total++;
				break;
				
			case 'u': case 'U':
				vowel_counts[4] ++;
				total++;
				break;
			}
	}
	
	return total;
}
