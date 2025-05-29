// Devin Combs
// Amanda
// Joshua Konopczynski

//TDD



#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <limits>


class ClockTime {
	private:
		int h;
		int m;
	
	public:
		ClockTime (int h, int m): h(h), m(m) {
		}
		
		std::string display()
		{
			
			if (h > 12)
			{
				return std::to_string(h - 12) + ":" + (m >= 10 ?  std::to_string(m) : "0" + std::to_string(m) ) + " PM";
					
			}
			else 
			 return std::to_string(h) + ":" + (m < 10 ?  "0" : "" ) + std::to_string(m) + " AM";
		}
};
 
void assertThat(ClockTime t, std::string expected);

int main() 
{
	
	assertThat(ClockTime(11,15) , "11:15 AM");   // 1
	assertThat(ClockTime(11,45) , "11:45 AM");  // 2
	assertThat(ClockTime(13,45) , "1:45 PM");   // 3
	assertThat(ClockTime(22,22) , "10:22 PM");  // 4
	assertThat(ClockTime(9,00) , "9:00 PM");   // 5
	
return 0;
}

void assertThat(ClockTime t, std::string expected)
{
	if (t.display() == expected)
		std::cout<<"Test Passed\n";
	else
		std::cout<<"Test Failed\n";
}
