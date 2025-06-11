// Devin Combs
// 6/11/2025

#include <iostream>
#include <limits>
#include <ctime>





class Player {

    

    private: 

       	std::string name;

		int number; 

  		int wins;

  		int losses;

 	public: 

  		Player(std::string n)  { name = n; }

  		int getNum()   { return number; }

  		void setNumber(int x) { number = x; } 

  		std::string getName() { return name; }
  		
  		virtual void chooseNumber () {}

};



class Human : public Player {

 private: 


 public: 
		
	 Human(std::string n):Player(n) {   }

  
	  void chooseNumber() 
	
	  {
	  	int x;
		 std::cout<<"\nEnter a Number 1 - 30: ";std::cin>>x;
		 setNumber(x);
	
	  }


};



class Computer : public Player {
 

	private: 
	

	
	public: 
 
	  Computer (): Player("Joshua") {}
	  void chooseNumber() 
	  {
		int x = rand() % (30 - 1 + 1) + 30;
		setNumber(x);
	  }


};





void playGame (Player *p1, Player *p2)

{
	Player x = *p1;
	Player y = *p2;
	
	x.chooseNumber();
	y.chooseNumber();
	
	 if (rand() % 2)
	{
	  	std::cout<<"\nHighest number wins .... ";
	
	  	if (x.getNum() > y.getNum())
	
	  	{
	  		std::cout<<x.getName()<<" wins with the highest number! "<<std::endl;
	  	} 
	
	  	else
	
	  	{
	  		std::cout<<y.getName()<<" wins with the highest number! "<<std::endl;
	  	}
	
	}

	 else
	
	 {
	 	std::cout<<"Lowest number wins .... ";
	
	  	if (x.getNum() < y.getNum())
	
	  	{
	  		std::cout<<x.getName()<<" wins with the lowest number! "<<std::endl;
	  	} 
	
	  	else
	
	  	{
	  		std::cout<<y.getName()<<" wins with the lowest number! "<<std::endl;
	  	}
	
	}
	
	std::cout<<"\n\n Player 1 Num: "<<x.getNum()<<"\tPlayer 2 Num: "<<y.getNum();
    
}


int main ()
{
	Player *p1;
	Player *p2;
	int choice;
	
	std::cout<<"\nPlayer 1: 1 = Human | 2 = Computer  "; std::cin>>choice;
		std::cin.clear();
	    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	
	if (choice == 1)
	{
		std::string name;
		std::cout<<"\nEnter Name: "; std::getline(std::cin, name);
		
		p1 = new Human(name);
	}
	
	else 
	{
		p1 = new Computer();
	}
	
	std::cout<<"\nPlayer 2: 1 = Human | 2 = Computer  "; std::cin>>choice;
	std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	
	if (choice == 1)
	{
		std::string name;
		std::cout<<"\nEnter Name: "; std::getline(std::cin, name);
		
		p2 = new Human(name);

	}
	else 
	{
		p2 = new Computer();
	}
	
	
	playGame(p1,p2);
	
	
	
	return 0;
}

