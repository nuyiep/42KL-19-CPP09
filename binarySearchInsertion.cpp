
#include <vector>
#include <iostream>
using namespace std;

int ft_insert(vector<int>& updatedMain, int num) 
{
	int left = 0;
	int right = updatedMain.size() - 1;
	int mid = (left + right) / 2;

	while (left <= right)
	{
		if (num < updatedMain[mid])
		{
			right = mid - 1;
			mid = (left + right) / 2;
		}
		else if (num > updatedMain[mid])
		{
			left = mid + 1;
			mid = (left + right) / 2;
		}
		else if (num == updatedMain[mid])
			return (mid + 1);
	}
	return (mid + 1);
}

int main()
{
	vector<int> updatedMain = {-1, 0, 3, 5, 9, 12, 15};
	int num = 5;
	int result = 0;

	result = ft_insert(updatedMain, num);
	std::cout << "Size: "<< updatedMain.size() << std::endl;
	std::cout << "Result: " << result << std::endl;
}
