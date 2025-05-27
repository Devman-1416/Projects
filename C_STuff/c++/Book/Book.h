#ifndef BOOK_H
#define BOOK_H
#include "author.h"
#include "publisher.h"

class Book
{
	private:
		Author anAuthor;
		Publisher anPublisher;
		std::string bName;
		std::string edition;
		int copyRight;
		std::string isbn;
		
	public:
		
		Book (std::string bName, std::string edition, int copyRight, std::string isbn, std::string Fname,std::string Lname,char initial, std::string name, std::string city);
		
		void display();

};

#endif
