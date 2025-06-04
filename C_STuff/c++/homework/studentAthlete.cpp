// Devin Combs
//Student Athlete



#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <limits>



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

		std::string getLastName () 
		{
			return lastName;
		}

			
		//Overload
		
		Student& operator+= (double num)
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
			
		double getFee() {return fee;}
		
		std::string getSport() {
			return sportName;
		}

		
			
		//Operator
		bool operator== (std::string sportName)
			{
				return this->sportName == sportName;
			}
			
		bool operator== (Student student)
		{
			return this->lastName == student.getLastName();
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


//Prototype
int displayMenu();
void addStudent(std::vector<Student> &allStudents, std::vector<Athlete> &allAthlete);
void displayStudents (std::vector<Student> allStudents);
void displayOneStudents (std::vector<Student> allStudents);
void displayAthletes (std::vector<Athlete> allAthlete);
void displayStudentsByGrade(std::vector<Student> allStudents);
void displayStudentsBySport(std::vector<Athlete> allAthlete);
void displayByGradeSport(std::vector<Student> allStudents, std::vector<Athlete> allAthlete);
bool getChoice();


int main() 
{
	
	std::vector<Student> allStudents;
	std::vector<Athlete> allAthlete;
	
	
// Sample Students
allStudents.push_back(Student("Alex", "Johnson", 10));
allStudents.push_back(Student("Taylor", "Smith", 10));
allStudents.push_back(Student("Jordan", "Lee", 10));  // Same grade as Alex
allStudents.push_back(Student("Casey", "Brown", 12));
allStudents.push_back(Student("Morgan", "Taylor", 11)); // Same grade as Taylor

// Sample Athletes
allAthlete.push_back(Athlete("Alex", "Johnson", "Esports"));
allAthlete.push_back(Athlete("Taylor", "Smith", "Soccor"));
allAthlete.push_back(Athlete("Jordan", "Lee", "Esports")); // Same sport as Alex
allAthlete.push_back(Athlete("Casey", "Brown", "Soccer"));
allAthlete.push_back(Athlete("Morgan", "Taylor", "Basketball")); // Same sport as Taylor

	
	
	int choice;
	
	while (true) 
	   {
	
		    switch (choice=displayMenu()) {
		        case 1:
					addStudent(allStudents, allAthlete);
		            break;
		
		        case 2:
					displayStudents(allStudents);
		            break;
		
		        case 3:
					displayOneStudents (allStudents);
		            break;
		
		        case 4:
					displayAthletes(allAthlete);
		            break;
		
		        case 5:
					displayStudentsByGrade(allStudents);
					break;
					
		        case 6:
		        	displayStudentsBySport(allAthlete);
					break;
					
		        case 7:
		   			 displayByGradeSport(allStudents, allAthlete);
					break;
					
				 case 8:
				 	std::cout<<"\n\n---------------Program Ended-------------------\n\n";
					exit(0);
					break;
		
			}
	    }
	
	

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
        std::cout << "7: Print a list of student by grade and sport\n";
        std::cout << "8: Exit program \n\n\tEnter: ";

        while (!(std::cin >> choice) || (choice < 1 || choice > 8)) {
            std::cout << "\nInvalid Menu Option! Enter a 1 - 8: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return choice;
}



void addStudent(std::vector<Student> &allStudents, std::vector<Athlete> &allAthlete)
{
	//Get Student Data
	std::cout<<"\n\n----------------------Add Student----------------------\n\n";
	std::string fName, lName, sName;
	int grade;
	bool choice;
	
	std::cout<<"\nFirst Name: ";
	std::getline(std::cin, fName);
	
	std::cout<<"\nLast Name: ";
	std::getline(std::cin, lName);
	
	std::cout<<"\nGrade: ";	
    while (!(std::cin >> grade) || (grade < 9|| grade > 12)) {
        std::cout << "\nInvalid Grade! Must be 9th - 12th Grade! ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    
    // Make New Student
	Student newStudent(fName,lName,grade);	

	
	//Ask if Athlete
	std::cout<<"\nDose the Student Play a sport? 1= Yes  0= No: ";	
	choice = getChoice();
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    // Run if They do play a sport

    while (choice)
    {
    	std::cout<<"\n\n--------Add Sport--------\n";
    	std::cout<<"\nSport Name: ";

		std::getline(std::cin, sName);
		
		
		//Make New Athlete
		Athlete newAthlete(fName,lName,sName);
		//Add Athlete Fee and to List
		newStudent+=newAthlete.getFee();
		allAthlete.push_back(newAthlete);
		
		//Add Another Sport
		std::cout<<"\nAdd Another Sport? 1= Yes  0= No: ";
		choice = getChoice();
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	allStudents.push_back(newStudent);
}

void displayStudents (std::vector<Student> allStudents)
{
	std::cout<<"\n\n----------------------All Students----------------------\n\n";
	for (Student student : allStudents)
	{
        std::cout<<student<<std::endl;
    }
}

void displayOneStudents (std::vector<Student> allStudents)
{
	bool found = false;
	std::string lName;
	std::cout<<"\n\n---------------------Find Student----------------------\n\n";
	
	std::cout<<"\nLast Name: ";
	std::getline(std::cin, lName);
	
	for (Student student : allStudents)
	{
		if (student == lName) 
		{
			std::cout<<student<<std::endl;
			found = true;
		}
    }
    
    if (!found) std::cout<<"\n"<<lName<<" not found!\n\n";
    
}



void displayAthletes (std::vector<Athlete> allAthlete)
{
	std::cout<<"\n\n-------------------All Athletes-------------------\n\n";
	for (Athlete athlete : allAthlete)
	{
        std::cout<<athlete<<std::endl;
    }
}

void displayStudentsByGrade(std::vector<Student> allStudents)
{
	int grade;
	
	std::cout<<"\n\n-----------------Student by Grade------------------\n\n";

	std::cout<<"\nEnter Grade: ";	
    while (!(std::cin >> grade) || (grade < 9|| grade > 12)) {
        std::cout << "\nInvalid Grade! Must be 9th - 12th Grade! ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
	
	for (Student student : allStudents)
	{
		if (student == grade) 
		{
			std::cout<<student<<std::endl;

		}
    }
 	
}


void displayStudentsBySport(std::vector<Athlete> allAthlete)
{
	bool found = false;
	std::string sName;
	
	std::cout<<"\n\n-----------------Athlete by Sport------------------\n\n";
	
    std::cout<<"\nSport Name: ";
	std::getline(std::cin, sName);
		
	for (Athlete athlete : allAthlete)
	{
		if (athlete == sName) std::cout<<athlete<<std::endl;
		found = true;
    }
 	
    if (!found) std::cout<<"\nNo Students play "<<sName<<"\n\n";
}

void displayByGradeSport(std::vector<Student> allStudents, std::vector<Athlete> allAthlete)
{
	int grade;
	std::string sName;
	bool found = false;
	std::vector<Student> gradeStudents;
	std::vector<Athlete> sportAthlete;
	
	std::cout<<"\n\n-----------Student by Grade and Sports------------\n\n";

	// Get Grade
	std::cout<<"\nEnter Grade: ";	
    while (!(std::cin >> grade) || (grade < 9|| grade > 12)) {
        std::cout << "\nInvalid Grade! Must be 9th - 12th Grade! ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  
	for (Student student : allStudents)
	{
		if (student == grade) 
		{
			gradeStudents.push_back(student);

		}
    }
    
    //Sport Name
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout<<"\nSport Name: ";
	std::getline(std::cin, sName);
		
	for (Athlete athlete : allAthlete)
	{
		if (athlete == sName) sportAthlete.push_back(athlete);
		found = true;
    }
 	
    if (!found) std::cout<<"\nNo Students play "<<sName<<"\n\n";
    
	for (int x=0; x < gradeStudents.size(); x++)
	{
		for (int y = 0; y < allAthlete.size(); y++ )
			if (allAthlete[y] == gradeStudents[x] && allAthlete[y].getSport() == sName)
			{
				std::cout<<"Test"<<x<<" "<<allAthlete[y]<<std::endl;
			}
	}
	

}



bool getChoice() {
    int choice;
    while (!(std::cin >> choice) || (choice != 0 && choice != 1)) {
        std::cout << "\nInvalid response! 1= Yes  0= No: ";
        
        std::cin.clear();  
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    
    // Return the result as a boolean (true for 1, false for 0)
    return choice;
}
