// Devin Combs
//5/28/2025



#include <iomanip>
#include <iostream>
#include <string>

class Job{
	friend int operator+ (int value, Job oneJob);
	friend std::ostream& operator<< (std::ostream& out, Job oneJob);
	friend std::istream& operator<< (std::istream& in, Job& oneJob);
	
	private:
		int jobNum;
		int jobTime;
		double rate;
		
	public:
		Job (int j, int t, int r): 
			jobNum(j), jobTime(t), rate(r) { }
		
		//Basic Operators
		
		int operator+ (int value)
		{
			return jobTime + value;
		}
		
		double operator+ (double value)
		{
			return rate + value;
		}
		
		int operator+ (Job aJob)
		{
			return this->jobTime + aJob.jobTime;
		}
		
		
		Job operator* (double value)
		{
			Job newJob(jobNum, value * jobTime, rate);
			return newJob;
		}
		
		//SHort Cut
		
		Job operator*= (double value)
		{
			jobTime *= value;
			return *this;
		}
		
		bool operator> (Job newJob)
		{
			return this->rate > newJob.rate;
		}

		Job& operator++()  //Prefix
		{
			jobTime++;
			return *this;
		}
		
		Job& operator++(int x) //Postfix
		{
			jobTime++;
			return *this;
		}
		
		int showTime()
		{
			return this->jobTime;
		}
		
}; // End class

//Making new Primative Overload

int operator+ (int value, Job oneJob)
{
	return value + oneJob.jobTime;
}



std::ostream& operator<< (std::ostream& out, Job oneJob)
{
	out<<oneJob.jobTime<<" "<<oneJob.rate<<" "<<oneJob.jobNum;
	return out;
}

// By refrence
std::istream& operator<< (std::istream& in, Job& oneJob)
{
	std::cout<<"Enter Job Num: "; std::cin>>oneJob.jobNum;
	std::cout<<"Enter Job Time: "; std::cin>>oneJob.jobTime;
	std::cout<<"Enter Job Rate: "; std::cin>>oneJob.rate;
	return in;
}


int main() 
{
	
	Job jobA(111,10,15.00);
	Job jobB(666,20,25.00);
	Job jobC(333,30,35.00);
	Job jobD(0,0,0);
	
	std::cout<<"\n Job A + 10 : "<<jobA + 10;
	std::cout<<"\n Job A + 5  : "<<jobA.operator+(5);
	std::cout<<"\n Job A + 7.5: "<<jobA + 7.5;
	
	std::cout<<"\n Job A + Job B: "<<jobA + jobB;
	
	std::cout<<"\n Job A + Job B + Job C: "<<jobA + jobB + jobC;
	
	jobD = jobA * 1.5;
	
	std::cout<<"\n Job D with Buffer: "<<jobD.showTime();
	
	jobD*=2;
	std::cout<<"\n Job D with Buffer: "<<jobD.showTime()<<std::endl;
	
	std::cout<<jobB<<std::endl;

	std::cin<<jobD;
	std::cout<<jobD;
	
	
	if (jobA > jobB) std::cout<<"\nJobA is bigger";
	else std::cout<<"\nJob B is bigger";
	
	//jobB++;
	std::cout<<jobB;
	
	++jobB;
	std::cout<<jobB;
	
	
	
return 0;
}




