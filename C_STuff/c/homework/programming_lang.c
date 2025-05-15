// Devin Combs
//

#include <stdio.h>

int main(){
	
	// Delcare Variables
	int html, java, c_plus, c_sharp, java_s, php, swift, kotlin, python;
	int total, total_web, total_mob, total_ool;
	
	// Welcome Message
	printf("Welcome to the Calumet High School Programming Survey");
	printf("\n\nPlease enter the total number of students who know:\n\n");
	
	
	// Get input
	printf("\t%-20s", "HTML: ");
	scanf("%d",&html);
		
	printf("\t%-20s", "Java: ");
	scanf("%d",&java);
	
	printf("\t%-20s", "C++: ");
	scanf("%d",&c_plus);
	
	printf("\t%-20s", "C#: ");
	scanf("%d",&c_sharp);
	
	printf("\t%-20s", "JavaScript: ");
	scanf("%d",&java_s);
	
	printf("\t%-20s", "PHP: ");
	scanf("%d",&php);
	
	printf("\t%-20s", "Swift: ");
	scanf("%d",&swift);
	
	printf("\t%-20s", "Kotlin: ");
	scanf("%d",&kotlin);
	
	printf("\t%-20s", "Python: ");
	scanf("%d",&python);
	
	// Get Totals
	total = html + java + c_plus + c_sharp + java_s + php + swift
		+ kotlin + python;
		
	total_web = html + java_s + php;
	
	total_mob = swift + kotlin;
	
	total_ool = java + c_plus + c_sharp + python;
	
	// Display Totals {^ . ^}
	printf("\n\n\nTotal students:                          %5d",total);
	printf("\nTotal who know Web languages:            %5d",total_web);
	printf("\nTotal who know Mobile App Dev languages: %5d",total_mob);
	printf("\nTotal who know Object Oriented languages:%5d",total_ool);


	return 0;
}
