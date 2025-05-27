#ifndef AUTHOR_H
#define AUTHOR_H
#include <string>
#include <iostream>

class Author
{
	private:
		std::string Fname;
		std::string Lname;
		char initial;
		
	public:
		
		Author(std::string Fname,std::string Lname,char initial);

		void display();

};

#endif
