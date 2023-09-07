
#include <iostream>
#include <algorithm>
#include <deque>

void	printdeque(std::deque<int> Data);

int main()
{
	int num = 999;
	std::deque<int> data = {7, 4, 5, 8, 10, 88, 1, 888, 3, 2};
	std::deque<int>::iterator it_pair_position;
	it_pair_position = data.insert(data.begin(), num);
	std::cout << "It pair position:  "<< *it_pair_position << std::endl;
	// printdeque(data);
}

void	printdeque(std::deque<int> Data)
{
	std::deque<int>::iterator it = Data.begin();
	std::deque<int>::iterator ite = Data.end();
	
	while (it != ite)
	{
		std::cout << *it << ' ';
		++it;
	}
}
