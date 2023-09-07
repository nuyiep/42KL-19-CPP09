
#include <iostream>
#include <algorithm>
#include <deque>
void	printdeque(std::deque<int> Data);

int	partition(std::deque<int> &data, int low, int high)
{
	int	pivot_value;
	int	i;
	int	j;

	pivot_value = data[high];
	i = low;
	j = low;
	while (j < high)
	{
		if (data[j] <= pivot_value)
		{
			std::swap(data[i], data[j]);
			i++;
		}
		j++;
	}
	std::swap(data[i], data[high]);
	return (i);
}

void	quicksort_recursion(std::deque<int> &data, int low, int high)
{
	int	pivot_index;

	if (low < high)
	{
		pivot_index = partition(data, low, high);
		quicksort_recursion(data, low, pivot_index - 1);
		quicksort_recursion(data, pivot_index + 1, high);
	}
}

void	quicksort(std::deque<int> &data)
{
	quicksort_recursion(data, 0, data.size() - 1);
}

int main()
{
	std::deque<int> data = {7, 4, 5, 8, 10, 88, 1, 888, 3, 2};
	quicksort(data);
	printdeque(data);
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
