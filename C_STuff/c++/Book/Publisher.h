#ifndef PUBLISHER_H
#define PUBLISHER_H
#include <string>
#include <iostream>

class Publisher
{
	private:
		std::string name;
		std::string city;
		
		
	public:
		
		Publisher (std::string name, std::string city);
		
		void display ();



};

#endif
