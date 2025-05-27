// Devin Combs
//5/27/2025

#include <iomanip>
#include <iostream>
#include <string>
#include "author.h"
#include "publisher.h"
#include "book.h"

int main() 
{

	Author oneAuthor("J.R", "Tolkien", 'R');
	Publisher onePublisher("Perason", "New York");
	
	//oneAuthor.display();
	//onePublisher.display();
	
	Book oneBook("Fellowship of the Ring", "4th", 1982, "997855145588", "J.R", "Tolkien", 'R', "Perason", "New York");
	
//Book (std::string bName, std::string edition, int copyRight, std::string isbn, std::string Fname,std::string Lname,char initial, std::string name, std::string city); 
	
	oneBook.display();
	
	
	
	
return 0;
}
