// Devin Combs
// 6/17/2025

#include <iostream>
  

int sum(int num)
{
	std::cout<<"\nNum: "<<num;
	if (num > 0)
	{
	return num + sum(num - 1);
	}
	else return num;
}


int main() 
{
	int num;
	
	std::cout<<"Enter a Number: ";
	std::cin>>num;
	
	std::cout<<"\nSum of the numbers is: "<<sum(num);
	
	// 3 + 2 + 1 = 6
	// 4 + 3 + 2 + 1 = 10

	return 0;
}

