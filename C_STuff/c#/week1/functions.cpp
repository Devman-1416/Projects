// Devin Combs
// 5/14/2025


#include <iomanip>
#include <iostream>
#include <string>
int computeValue(int num1, int num2);
int computeValue(int num1, int num2, int num3);
float  computeValueF(float num1, float num2);
int calcArea(int x, int y, int z=1 ); //Added Default Value only in Proto

int main() {

	int num1=4, num2=9, num3=2, value;
	float answer=num1/num2;
					//must have <data type>
	//answer = static_cast<float>(num1)/num2; //only the num1 is being cast
	answer = (float)num1 / num2;
	
	std::cout<<answer<<std::endl;
	
	char initial='a';
	std::cout<<(int)initial<<std::endl;
	
	answer = 2 * ++num1; // ++post vs pre++
	std::cout<<answer<<std::endl;

	//concatation
	std::string first=" Dev ",last=" Comb ";
	std::cout<<"\n\nHello" + first + last<<std::endl;
	
	
	//multiple cin
	std::cout<<"Enter 2 Nums: ";
	std::cin>>num1>>num2;
	std::cout<<"\nNums: "<<num1<<" and "<<num2;

	//boolian and stuff
	if (num2 % 2 == 1) std::cout<<"\nIts Odd";
	else std::cout<<"\nIts Even";
	
				//Boolian
	std::cout<<((num2 % 2)?"\nIts Odd":"\nIts Even");
	
	bool isTired=true;


	//function
		//function call   (arguments)
	value = computeValue(num1,num2);
	std::cout<<"\n\nValue: "<<value;
	std::cout<<"\n\nNew Value: "<<computeValue(num1,num2,num3);
	//Function Overloading when two same name function, need different Signature 

	std::cout<<"\n\nFloat Value: "<< computeValueF(8.5,7.2);
	
	
	std::cout<<"\n\nArea Value: "<< calcArea(num1,num2);
	std::cout<<"\n Volume: "<<calcArea(num1,num2,num3);

return 0;
}


	  //-----Function Signiture-------//
int   computeValue(int num1, int num2)
//type  //Declaration   //Peramitors
{
	//Body
	return num1 * num2;
	
}

float  computeValueF(float num1, float num2)
//type  //Declaration   //Peramitors
{
	//Body
	return num1 * num2;
	
}

int computeValue(int num1, int num2, int num3)
{
	return num1 + num2 + num3;
}


int calcArea(int x, int y, int z) //Added Default Value
{
	return x * y * z;
}


