// Devin Combs
// Virtual Person

#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <stdlib.h> 
#include <vector>    

class Person
{
	private:
		std::string fName;
		std::string lName;
		std::string address;
		std::string zipcode;
		std::string phone;
		
	public:
		
//		Person(std::string fn, std::string ln, std::string add, std::string zip,
//			 std::string ph)
//			: fName(fn), lName(ln), address(add), zipcode(zip), phone(ph) {}
	
		std::string getFName()  { return fName; }
		void setFName( std::string fn) { fName = fn; }

		std::string getLName()  { return lName; }
		void setLName( std::string ln) { lName = ln; }

		std::string getAddress()  { return address; }
		void setAddress(std::string add) { address = add; }

		std::string getZipcode()  { return zipcode; }
		void setZipcode(std::string zip) { zipcode = zip; }

		std::string getPhone()  { return phone; }
		void setPhone( std::string ph) { phone = ph; }

		virtual void display()
		{
			std::cout<<"\nFirst Name: " + fName + "\nLast Name: " + lName
			+ "\nAddress: " + address + "Zip Code: " + zipcode
			+ "\nPhone #: " + phone + "\n";
		}
	
	
}; // End Person

class Employee : public Person
{
	private:
		std::string ss;
		std::string department;
		
	public:

//		Employee(std::string fn, std::string ln, std::string add, std::string zip,
//             std::string ph, std::string ssn, std::string dept)
//			: Person(fn, ln, add, zip, ph), ss(ssn), department(dept) {}
		
		std::string getSS() { return ss; }
		void setSS(std::string ss) { ss = ss; }

		std::string getDepartment()  { return department; }
		void setDepartment(std::string department) { department = department; }
		
		virtual void display ()
		{
			std::cout<<"\n------------\nEmployee\n------------\n";
			Person::display();
			std::cout<<"Social Security: " + ss + "\nDepartment: " + department + "\n";	
		}	
		
	
}; // End Employee

class Customer : public Person
{
	private:
		std::string discount;
		std::string email;
		
	public:
		
//		Customer(std::string fn, std::string ln, std::string add, std::string zip, std::string ph,
//				 std::string dis, std::string mail)
//			: Person(fn, ln, add, zip, ph), discount(dis), email(mail) {}
		
		std::string getDiscount() { return discount; }
		void setDiscount(std::string dis) { discount = dis; }

		std::string getEmail()  { return email; }
		void setEmail(std::string email) { email = email; }
		
	virtual void display ()
	{
		std::cout<<"\n------------\nCustomer\n------------\n";
		Person::display();
		std::cout<<"Discount: %" + discount + "\nEmail: " + email + "\n";	
	}	
		
	
}; // End Customer

int displayMenu();
void displayAll(Person *person);

int main() 
{
	std::vector<Person *> allPeople;
	int choice;
	Person *person;
	
	do
	{		
		switch (choice = displayMenu())
		{
			case 1:
				
				allPeople.push_back(person = new Employee);
				break;
				
			case 2:
				allPeople.push_back(person = new Customer);
				break;
				
			default:
				break;												
		}
		
	} while(choice != 0);
	
	for (Person *person : allPeople)
	{
		displayAll(person);
	}


	return 0;
}


int displayMenu()
{
		int choice;
        std::cout << "\n--------------------- Menu ------------------------\n";
        std::cout << "\nPlease choose from the following menu\n";
        std::cout << "1: Add Employee\n";
        std::cout << "2: Add Customer\n";
        std::cout << "0: Quit\n";
		std::cout << "Enter: ";

        while (!(std::cin >> choice) || (choice < 0 || choice > 2)) {
            std::cout << "\nInvalid Menu Option! Enter a 0 - 3: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        return choice;
}

void displayAll(Person *person)
{
	person->display();
}



