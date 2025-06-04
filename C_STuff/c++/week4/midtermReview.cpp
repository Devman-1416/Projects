// Devin Combs
//Midterm Review

#include <iomanip>  // for std::setprecision and std::fixed
#include <iostream>
#include <string>
#include <vector>
#include <limits>

// Student class definition
class Student {
    // Allows std::cout << student to access private members
    friend std::ostream& operator<< (std::ostream& out, Student oneStudent);

private:
    std::string name;
    int id;
    float gpa;
    static int sCount;  // static variable shared across all students

public:
    // Constructor using initialization list
    Student(std::string name, int id, int gpa) : name(name), id(id), gpa(gpa) {
        sCount++;
    }

    // Static accessor to get student count
    static int getCount() { return sCount; }

    // Accessor
    float getGpa() { return gpa; }

    // Utility function using conditional (ternary) operator
    std::string getStatus() {
        return gpa >= 3.0 ? "\nGood Standing" : "\nProbation";
    }

    // Mutator
    void updateGpa(float gpa) {
        this->gpa = gpa;
    }

    // Operator overload to compare GPA
    bool operator> (Student student) {
        return this->gpa > student.gpa;
    }
}; // End Student class

int Student::sCount = 0; // Initialize static count

// Overloaded output operator for Student
std::ostream& operator<< (std::ostream& out, Student oneStudent) {
    std::string oneString = "\nName: " + oneStudent.name + "\nID: " + std::to_string(oneStudent.id) + "\nGPA: "
        + std::to_string(oneStudent.gpa) + oneStudent.getStatus() + "\n";

    out << oneString;
    return out;
}

// Course class demonstrates composition (has vector of Students)
class Course {
private:
    std::string courseName;
    std::vector<Student> roster;

public:
    Course(std::string name) : courseName(name) { }

    // Add a student to the roster
    void enrollStudent(Student newStudent) {
        roster.push_back(newStudent);
    }

    // Loop using ranged-based for to display students
    void printRoster() {
        std::cout << "\n\nCourse: " << courseName << std::endl;
        for (Student student : roster) {
            std::cout << student;
        }
    }

    // Get student with highest GPA
    Student getTopStudent() {
        Student top = roster[0];
        for (int x = 0; x < roster.size(); x++) {
            if (roster[x] > top) {
                top = roster[x];
            }
        }
        return top;
    }
};

// Function that modifies a student's GPA by reference
void changeGpa(Student& student) {
    student.updateGpa(1.1);
}

int main() {
    // Set 2 decimal places for all floating-point output
    std::cout << std::fixed << std::setprecision(2);

    // Create students
    Student aStudent("J.J", 14, 2.4);
    Student bStudent("D.D", 2, 4.4);
    Student cStudent("Jimmy Hendrix", 20, 4.0);

    // Display a student
    std::cout << aStudent;
    std::cout << "\nCount: " << Student::getCount();

    // Create a course and add students
    Course oneCourse("C++");
    oneCourse.enrollStudent(aStudent);
    oneCourse.enrollStudent(bStudent);
    oneCourse.enrollStudent(cStudent);

    // Print all students
    oneCourse.printRoster();

    // Show top student
    std::cout << "\nTop: " << oneCourse.getTopStudent();

    // Change GPA and show updated info
    changeGpa(aStudent);
    std::cout << aStudent;

    return 0;
}

//	Non-String Data Validation Example
//
//	std::cout<<"\nGrade: ";	
//    while (!(std::cin >> grade) || (grade < 9|| grade > 12)) {
//        std::cout << "\nInvalid Grade! Must be 9th - 12th Grade! ";
//        std::cin.clear();
//        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//    }

// For Each
//	for (Student student : allStudents)
//	{
//		if (student == lName) 
//		{
//			std::cout<<student<<std::endl;
//			found = true;
//		}
//    }

// Menu Switch Code Example
//	while (true) 
//	   {
//	
//		    switch (choice=displayMenu()) {
//		        case 1:
//					addStudent(allStudents, allAthlete);
//		            break;
//		
//		        case 2:
//					displayStudents(allStudents);
//		            break;
//		
//		        case 3:
//					displayOneStudents (allStudents);
//		            break;
//		
//		        case 4:
//					displayAthletes(allAthlete);
//		            break;
//		
//		        case 5:
//					displayStudentsByGrade(allStudents);
//					break;
//					
//		        case 6:
//		        	displayStudentsBySport(allAthlete);
//					break;
//					
//		        case 7:
//		   			 displayByGradeSport(allStudents, allAthlete);
//					break;
//					
//				 case 8:
//				 	std::cout<<"\n\n---------------Program Ended-------------------\n\n";
//					exit(0);
//					break;
//		
//			}
//	    }




