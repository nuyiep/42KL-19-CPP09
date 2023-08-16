
#include <iostream>
#include <map>

//check if is a leap year
int main()
{
	int year = 2000;

	if (year % 4 == 0)
	{
		if (year % 100 == 0)
		{
			if (year % 400 == 0)
				std::cout << "Is a leap year" << std::endl;
			else
				std::cout << "Not a leap year" << std::endl;
		}
		else
			std::cout << "Is a leap year" << std::endl;
	}
	else
		std::cout << "Not a leap year" << std::endl;
}