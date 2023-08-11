
#include <iostream>
#include <map>
#include <functional>
#include <vector>
#include "ex00/srcs/color.hpp"
using namespace std;

/* Map will auto-sort in ascending order */
/* Can make it into descending order */
/* std::map<string, int, std::greater> Map; */
/* or less */
int main()
{
	{
		std::cout << BOLD_MAGENTA << "----1.1 Map: Using normal int----" << RESET << std::endl;
		std::map<string, int, std::greater<string>> Map;
		Map["PY"] = 0506; 
		//guess what will 0506 be printed out as- explanation at below
		Map["Queen"] = 100;
		Map.insert(std::make_pair("King", 88));

		for (auto &bishop: Map)
		{
			cout << bishop.first << " " << bishop.second << endl;
		}
		cout << Map["PY"] << endl;
	}
	{
		std::cout << BOLD_MAGENTA << "----1.2 Map: Using vector- can store multiple values for 1 key----" << RESET << std::endl;
		std::map<string, vector<int>>Map;
		Map["PY"].push_back(0506);
		Map["PY"].push_back(930605);
		for (auto &name: Map)
		{
			cout << name.first << " ";
			for (auto &value : name.second)
			{
				cout << value << " ";
			}
		}
		cout << endl;
	}
}

//0506 compiler interprets it as an octal (base 8) number 