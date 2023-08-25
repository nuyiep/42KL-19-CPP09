/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:19:31 by plau              #+#    #+#             */
/*   Updated: 2023/08/24 17:06:54 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	printBeforeAndErrorChecking(int ac, char **av)
{
	int i = 1;
	while (i < ac)
	{
		if (atoi(av[i]) < 0)
		{
			std::cout << RED << "Error: Only positive integer is allowed." << RESET << std::endl;
			exit(EXIT_FAILURE);
		}
		i++;
	}
	std::cout << "Before: ";
	
	i = 1;
	while (i < ac)
	{
		std::cout << av[i] << ' ';
		i++;
	}
	std::cout << std::endl;
}

void	printVector(std::vector<int> Data)
{
	std::vector<int>::iterator it = Data.begin();
	std::vector<int>::iterator ite = Data.end();
	
	std::cout << BOLD_MAGENTA << "Printing vector data container: ";
	while (it != ite)
	{
		std::cout << *it << ' ';
		++it;
	}
	std::cout << RESET << std::endl;
}

std::vector<int>	parseIntoVector(int ac, char **av, std::vector<int> initialData)
{
	for (int i = 1; i < ac; i ++)
		initialData.push_back(atoi(av[i]));
	
	return(initialData);
}

std::vector<int>	splitIntoTwoPairs(std::vector<int> Data, int numberOfElement)
{
	std::vector<int>::iterator it;
	int temp = 0;
	std::vector<int>::iterator ite;

	ite = Data.end();
	if (numberOfElement % 2 != 0)
		ite = Data.end() - 1;

	for (it = Data.begin(); it != ite; it += 2)
	{
		if (*it > *(it + 1))
		{
			temp = *it;
			*it = *(it + 1);
			*(it + 1) = temp;
		}
	}
	return (Data);
}

void	jacobsthalNumbers(std::vector<int> Data)
{
	(void)Data;
}

/* 2 8 4 7 */
void	compareSecondElement(std::vector<int> Data, int numberOfElement)
{
	std::vector<int>::iterator it;
	int temp = 0;

	if (numberOfElement % 2 == 0)
	{
		for (it = Data.begin() + 1; it != Data.end() - 1; it += 2)
		{
			if (*it > *(it + 2))
			{
				std::swap(*it, *(it + 2));
				std::swap(*(it - 1), *(it + 1));
			}
		}
	}
	else
	{
		for (it = Data.begin() + 1; it != Data.end() - 2; it += 2)
		{
			if (*it > *(it + 2))
			{
				std::swap(*it, *(it + 2));
				std::swap(*(it - 1), *(it + 1));
			}
		}
	}
	printVector(Data);
	(void)temp;
}

void	mergeInsertionSort(int ac, char **av)
{
	std::vector<int> initialData;
	initialData = parseIntoVector(ac, av, initialData);
	int numberOfElement = ac - 1;
	initialData = splitIntoTwoPairs(initialData, numberOfElement);
	printVector(initialData);
	compareSecondElement(initialData, numberOfElement);
	jacobsthalNumbers(initialData);
}
