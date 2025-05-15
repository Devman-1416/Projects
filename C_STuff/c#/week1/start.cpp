// Devin Combs
// 5/13/2025
// -std=c++11

#include <iomanip>
#include <iostream>
#include <string>
//using namespace std;



int main() {
//Add to Top, set for Money
std::cout<<std::setprecision(2)<<std::fixed;
	

int num1=5, num2=10;

			//print		end line (flushes buffer)
std::cout<<"Hello! "<<std::endl;

	//c-out		print variables
std::cout<<num1<<"\t"<<num2;

bool isHungry = true;
std::cout<<"\nAm I hungry? "<<isHungry<<std::endl;

int a,b,c,d;
a=b=c=d=0;


float version=23.141589654;
std::cout<<version<<"\n"; //23.1416
					// Change number of significent Digits
std::cout<<std::setprecision(3)<<version<<"\n"; //23.1
std::cout<<std::fixed<<version<<"\n"; // 23.142
std::cout<<version<<"\n"; // 23.142




float number=222.2222;
{
	//This is a Block
	//Varable in Here exist only in block, deleted after
	float number=12.345F; // add F to make float, default is double
	double number2=12.34;
	std::cout<<"\n"<<number;
}
	//Push into memory, Pop out
	// Float 4 bites, double 8 bites





//Input
std::cout<<"\n"<<number;

int age;
std::cout<<"\nEnter Your Age: ";
std::cin>>age;

std::cout<<"\nYour age is: "<<age<<" years old";


while(std::cin.fail())
{
	std::cout<<"\nFail";
	

	std::cin.clear(); //turns off alarms, bool
	std::cin.ignore(10,'\n'); //ignore up 10 chars untill enter key
	
	std::cout<<"\nEnter Your Age: ";
	std::cin>>age;	
	
}

//Strings

	// Not primitive data type
std::string greeting;
greeting = "\nThis is a Greeting!";

std::cout<<greeting;

greeting += " I added this";

std::cout<<greeting;

char initial;
std::string name;
std::cout<<"\n\nEnter Your Age: "; std::cin>>age;
std::cout<<"\nEnter Your Inital: "; std::cin>>initial;
std::cin.ignore(100,'\n'); // Rid of enter Key in buffer

std::cout<<"Enter Name: "; // stops at space or enter   std::cin>>name;
std::getline(std::cin,name); // Grabs whole line in buffer

 
std::cout<<"\n\nAge:"<<age<<"\nInitial: "<<initial<<"\nName: "<<name;


if (age >= 18)
{
	std::cout<<"\nAdult";
}
else std::cout<<"\nChild";

	//?: <- condition Operator (Need 3 operands)
			// 1         2        3	
			//like if statment				
std::cout<<((age >= 18)?"Adult":"Child");


}
