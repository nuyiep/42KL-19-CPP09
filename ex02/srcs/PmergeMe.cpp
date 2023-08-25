/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:19:31 by plau              #+#    #+#             */
/*   Updated: 2023/08/25 15:24:40 by plau             ###   ########.fr       */
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

void	splitPairsRecursive(std::vector<int>::iterator it, std::vector<int>::iterator ite)
{
	if (it == ite)
		return ; //base case
	if (*it > *(it + 1))
		std::swap(*it, *(it + 1));
	splitPairsRecursive(it + 2, ite);
}

std::vector<int>	splitIntoTwoPairs(std::vector<int> Data, int numberOfElement)
{
	std::vector<int>::iterator it;
	std::vector<int>::iterator ite;

	ite = Data.end();
	if (numberOfElement % 2 != 0)
		ite = Data.end() - 1;
	splitPairsRecursive(Data.begin(), ite);
	/* For loop is good too */
	// for (it = Data.begin(); it != ite; it += 2)
	// {
	// 	if (*it > *(it + 1))
	// 		std::swap(*it, *(it + 1));
	// }
	return (Data);
}

void	jacobsthalNumbers(std::vector<int> Data)
{
	(void)Data;
}

void	compareSecondElementRecursive(std::vector<int>::iterator it, std::vector<int>::iterator ite)
{
	if (it == ite)
		return; 
	if (*it > *(it + 2))
	{
		std::swap(*it, *(it + 2));
		std::swap(*(it - 1), *(it + 1));
		compareSecondElementRecursive(it, ite);
	}
	else
		compareSecondElementRecursive(it + 2, ite);
}

std::vector<int>	compareSecondElement(std::vector<int> Data, int numberOfElement)
{
	std::vector<int>::iterator it;
	std::vector<int>::iterator ite;

	ite = Data.end();
	if (numberOfElement % 2 == 0)
		ite = Data.end() - 1;
	else
		ite = Data.end() - 2;
	for (it = Data.begin() + 1; it != ite; it += 2)
	{
		if (*it > *(it + 2))
		{
			std::cout << *it << ' ';
			std::cout << *(it + 2) << ' ';
			std::swap(*it, *(it + 2));
			std::swap(*(it - 1), *(it + 1));
			printVector(Data);
			it = Data.begin() + 1;
		}
	}
	return (Data);
}

void	mergeInsertionSort(int ac, char **av)
{
	std::vector<int> initialData;
	initialData = parseIntoVector(ac, av, initialData);
	int numberOfElement = ac - 1;
	initialData = splitIntoTwoPairs(initialData, numberOfElement);
	std::cout << "step 1: splitIntoTwoPairs" << std::endl;
	printVector(initialData);
	initialData = compareSecondElement(initialData, numberOfElement);
	std::cout << "step 2: compareSecondElement" << std::endl;
	printVector(initialData);
	jacobsthalNumbers(initialData);
}
