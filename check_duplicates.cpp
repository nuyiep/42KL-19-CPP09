
#include <iostream>

int main(int ac, char **av)
{
	int i = 1;
	int j = 1;
	int count = 0;

	while (i < ac)
	{
		j = 1;
		while (j < ac)
		{
			if (i != j && std::strcmp(av[i], av[j]) == 0)
				count++;
			j++;
		}
		i++;
	}
	if (count != 0)
		std::cout << "Du" << std::endl;
}
