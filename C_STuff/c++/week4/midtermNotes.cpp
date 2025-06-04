// Devin Combs
// Midterm C++ Review (Examples from Devin's Code)

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>
#include <limits>
using namespace std;

// ===== CLASSES =====
class Demo {
	private:
		static int count;
	public:
		Demo() { count++; }
		static int getCount() { return count; }
};
int Demo::count = 0;

// ===== ACCESSORS / MUTATORS / CONDITIONAL / INIT LIST =====
class Student{
	friend ostream& operator<< (ostream& out, Student oneStudent);

	private:
		string name;
		int id;
		float gpa;
		static int sCount;

	public:
		Student (string name, int id, float gpa): name(name), id(id), gpa(gpa) {sCount++;}
		static int getCount() {return sCount;}
		float getGpa(){return gpa;}
		void updateGpa (float gpa) {this->gpa = gpa;}
		string getStatus() { return gpa >= 3.0 ? "\nGood Standing" : "\nProbation"; }
		bool operator> (Student student) { return this->gpa > student.gpa; }
};
int Student::sCount = 0;

ostream& operator<< (ostream& out, Student oneStudent)
{
	string oneString = "\nName: " + oneStudent.name + "\nID: "+to_string(oneStudent.id)+"\nGPA: "
				+to_string(oneStudent.gpa)+oneStudent.getStatus()+"\n";
	out<<oneString;
	return out;
}

// ===== COMPOSITION (Course has Students) =====
class Course {
	private:
		string courseName;
		vector<Student> roster;

	public:
		Course (string name) : courseName(name) {;}
		void enrollStudent(Student newStudent) { roster.push_back(newStudent); }
		void printRoster() {
			cout<<"\n\nCourse: "<<courseName<<endl;
			for (Student student : roster) cout<<student;
		}
		Student getTopStudent() {
			Student top = roster[0];
			for (int x = 0; x < roster.size(); x++) if (roster[x] > top) top = roster[x];
			return top;
		}
};

// ===== FRIEND FUNCTION EXAMPLE =====
class Sale; // forward declaration
class SalePerson {
	friend void displaySale (Sale aSale, SalePerson aSeller);
	private:
		string name;
		int id;
	public:
		SalePerson(string name, int id): name(name), id(id) { }
};
class Sale {
	friend void displaySale (Sale aSale, SalePerson aSeller);
	private:
		Student dummyStudent = Student("Dummy", 0, 0); // to demo comp
		float amount;
		int id;
	public:
		Sale(float amt, int id): amount(amt), id(id) {}
};
void displaySale (Sale aSale, SalePerson aSeller) {
	cout<<"\nAmount: $"<<aSale.amount;
	cout<<"\nSeller: "<<aSeller.name;
	cout<<"\nSeller ID: #"<<aSale.id;
}

// ===== POINTERS / REFERENCES =====
void pointerDemo() {
	int qty = 10;
	int *qtyPtr = &qty;
	cout<<qty<<endl;
	cout<<qtyPtr<<endl;
	*qtyPtr = 22;
	cout<<qty<<endl;
}

void referenceDemo(int &ref) {
	ref += 10;
}

// ===== FLOAT COMPARISON (DATA VALIDATION) =====
void floatCompare() {
	const float EPSILON = .0005;
	float amount = 56.06, given = 60.00;
	float totalDue = given - amount;
	cout<<fixed<<setprecision(2);
	if (fabs(totalDue - 3.94) < EPSILON) cout<<"\n\nThey Equal!!!";
	else cout<<"\n\nNot Equal!!!";
	cout<<"\nAmount: "<<totalDue;
}

// ===== MAIN ===== //
int main() 
{
	Demo a, b, c;
	cout<<"\nStatic Count: "<<Demo::getCount();

	Student aStudent ("J.J", 14, 2.4);
	Student bStudent ("D.D", 2, 4.4);
	Student cStudent ("Jimmy Hendrix", 20, 4.0);
	cout<<aStudent;
	cout<<"\nCount: "<<Student::getCount();

	Course oneCourse("C++");
	oneCourse.enrollStudent(aStudent);
	oneCourse.enrollStudent(bStudent);
	oneCourse.enrollStudent(cStudent);
	oneCourse.printRoster();
	cout<<"\nTop: "<<oneCourse.getTopStudent();

	pointerDemo();
	int num = 5;
	referenceDemo(num);
	cout<<"\nRef Changed: "<<num;

	floatCompare();

	SalePerson kevin("Kevin James", 12);
	Sale sale(15.50, 9988);
	displaySale(sale, kevin);

	return 0;
}


