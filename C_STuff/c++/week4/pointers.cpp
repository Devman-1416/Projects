// Devin Combs

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <limits>

 

int main() 
{
	int qty = 10;
	int *qtyPtr;
	
	qtyPtr = &qty;
	
	std::cout<<qty<<std::endl;
	std::cout<<qtyPtr<<std::endl;
	
	*qtyPtr = 22;  //* mean derefrencing
	std::cout<<qty<<std::endl;
	
	float amount = 1.99, price = 2.99;
	float const *amtPtr = &amount; // Constant to what the pointer points too
	// float * const amtPtr; Pointer is now a constant
	std::cout<<"\nAmount: "<<amount<<std::endl;
	//amtPtr = &amount;
	std::cout<<"\nAmount Ptr: "<<*amtPtr<<std::endl;
	//*amtPtr = 4.99;
	std::cout<<"\nAmount: "<<amount<<std::endl;
	
	amtPtr = &price;
	//*amtPtr = 4.99;
	std::cout<<"\nPrice: "<<price<<std::endl;
	
	//const int *xPtr; // ptr points to constant int 
	//int const *xPtr; // ptr points to constant int 
	//int * const xPtr; // constant ptr points to int 
    //int const * const xPtr; // constant ptr points to constant int 
	
	

return 0;
}


