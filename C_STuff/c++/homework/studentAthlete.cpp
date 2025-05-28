// Devin Combs
//Student Athlete



#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <limits>

//Prototypes
int displayMenu();

//Classes
class Student{
	
	friend std::ostream& operator<< (std::ostream& out, Student oneStudent);
	
	private:
		std::string firstName;
		std::string lastName;
		int grade;
		double totalFee;
		
	public:
		Student(std::string firstName,std::string lastName, int grade):
			firstName(firstName), lastName(lastName), grade(grade), totalFee(0) { }
			
		double getTotalFee(){return this->totalFee;}
			
		//Overload
		
		Student& operator+= (int num)
		{
			totalFee = totalFee + num;
			return *this;
		}
		
		bool operator== (std::string lastName)
			{
				return this->lastName == lastName;
			}
			
		bool operator== (int grade)
			{
				return this->grade == grade;
			}
		
		
		
}; // End Class

//Display Student Info
std::ostream& operator<< (std::ostream& out, Student oneStudent)
{
	out<<"\nGrade: "<<oneStudent.grade<<"th\nName: "<<oneStudent.firstName + " " + 
		oneStudent.lastName<<"\nTotal Fee: $"<<oneStudent.totalFee;
	return out;
}


class Athlete {
	friend std::ostream& operator<< (std::ostream& out, Athlete athleteOne);
	
	private:
		std::string firstName;
		std::string lastName;
		std::string sportName;
		static double fee;
		
	public:
		Athlete (std::string firstName, std::string lastName,std::string sportName):
			firstName(firstName), lastName(lastName), sportName(sportName) { }
			
		//Operator
		bool operator== (std::string sportName)
			{
				return this->sportName == sportName;
			}
		
}; // End Class

double Athlete::fee = 125.50;

//Display Student Info
std::ostream& operator<< (std::ostream& out, Athlete athleteOne)
{
	out<<"\nSport: "<<athleteOne.sportName<<"\nName: "<<athleteOne.firstName + " " + 
		athleteOne.lastName;
	return out;
}






int main() 
{
	
	std::vector<Student> allStudents;
	std::vector<Athlete> allAthlete;
	int choice;
	
	while (true) 
	   {
	
		    switch (choice=displayMenu()) {
		        case 1:
					
		            break;
		
		        case 2:
		
		            break;
		
		        case 3:
		
		            break;
		
		        case 4:
		
		            break;
		
		        case 5:
					break;
					
		        case 6:
					break;
					
		        case 7:
					break;
		
			}
	    }
	
	
	
	
	
	
	
	
	
	
	
	
	/*
	Student studentOne("Devin","Combs", 12);
	
	std::cout<<"\nBefore"<<studentOne.getTotalFee();
	studentOne+=5;
	
	std::cout<<"\nAfter"<<studentOne.getTotalFee();
	
	std::cout<<studentOne;
	
	if (studentOne == "Combs") std::cout<<"\n\nTrue";
	else std::cout<<"\n\nFalse";
	
	if (studentOne == 12) std::cout<<"\n\nTrue";
	else std::cout<<"\n\nFalse";
	
	Athlete athleteOne("Aragorn", "Islander", "Sword");
	
	std::cout<<athleteOne;
	
	if (athleteOne == "Sword") std::cout<<"\n\nTrue";
	else std::cout<<"\n\nFalse";
	*/

return 0;
}



int displayMenu()
{
		int choice;
        std::cout << "\n--------------------- Menu ------------------------\n";
        std::cout << "\nPlease choose from the following menu\n";
        std::cout << "1: Add student\n";
        std::cout << "2: Print a list of enrolled students\n";
        std::cout << "3: Print a list of students by last name\n";
        std::cout << "4: Print a list of students who play sports\n";
        std::cout << "5: Print a list of students by grade\n";
        std::cout << "6: Print a list of students by sport\n";
        std::cout << "7: Exit program \n\tEnter: ";

        while (!(std::cin >> choice) || (choice < 1 || choice > 7)) {
            std::cout << "\nInvalid Menu Option! Enter a 1 - 7: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        
        return choice;
}
