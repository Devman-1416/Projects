// RPG Test

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;



class Species
{
	private:
		int statsMods[4];
		
	public:
		Species (int s, int d, int w, int i )
		{
			statsMods[0] += s;
			statsMods[1] += d;
			statsMods[2] += w;
			statsMods[3] += i;
		}
			
		void StatMod (int stats [4])
		{
			for (int x = 0; x < 4; x++)
			{
				stats[x] += statsMods[3];
			}
		}
	
}; // End Species

class Human : public Species
{
	public:
		Human (int s=1, int d=1, int w=1, int i=1):
			Species (s,d,w,i) {}
				
}; // End Human



class Person
{
	private:
		string firstName;
		string lastName;
		Human race;
		//Profession
		string description;
		int age;
		
		
		//Stats [strenght,dexterity,wisdom,intelligence]
		int stats [4];
		
	public:
		
		Person (string fN, string lN, string desc, int age)
		:firstName(fN), lastName(lN), description(desc), age(age)
		{
			race.StatMod(stats);
		}
		
		void display ()
		{
			cout<<"\nFN: " + firstName + "\nSN: " + lastName + "\nDesc: " + description;
			cout<<"\n Age "<<age<<"\nStats: ";
			for (int x=0;x<4;x++)
			{
				cout<<stats[x]<<"  ";
			}
		}
		
		
	
}; // end Character





int main() 
{

	Person me("Devin","Combs","A dude",26);
	me.display();
	  

    return 0;
}
