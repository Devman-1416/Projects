#include "Book.h"

		Book::Book (std::string bName, std::string edition, int copyRight, std::string isbn, std::string Fname,std::string Lname,char initial, std::string name, std::string city):
		anAuthor(Fname,Lname,initial), anPublisher (name, city)
		{
			this->bName = bName;
			this-> edition = edition;
			this->copyRight = copyRight;
			this-> isbn = isbn;
		}
		
		void Book::display()
		{
			anAuthor.display();
			
			std::cout<<"\n"<<bName<<" "<<edition;
			anPublisher.display();
			std::cout<<copyRight<<" "<<isbn;
			
			
		}
