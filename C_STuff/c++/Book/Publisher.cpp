#include "Publisher.h"

		Publisher::Publisher (std::string name, std::string city)
		{
			this->name = name;
			this->city = city;
		}
		
		void Publisher::display ()
		{
			std::cout<<"\n"<<name<<", "<<city;
		}
