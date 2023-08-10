
#include <iostream>
#include <map>
#include <functional>
using namespace std;

/* Map will auto-sort in ascending order */
int main()
{
	std::map<string, int> Map;
	Map["PY"] = 0506; 
	//compiler interprets it as an octal (base 8) number 
	Map["Queen"] = 100;
	Map.insert(std::make_pair("King", 88));

	for (auto &bishop: Map)
	{
		cout << bishop.first << " " << bishop.second << endl;
	}

	cout << Map["Chess"] << endl;
}
