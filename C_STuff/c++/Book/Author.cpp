#include "Author.h"


// Uses Code from Author.h file

	Author::Author(std::string Fname,std::string Lname,char initial)
	{
		this->Fname = Fname;
		this->Lname = Lname;
		this->initial = initial;
	}
	
	void Author::display()
	{
		std::cout<<Fname<<"."<<initial<<" "<<Lname;
	}
