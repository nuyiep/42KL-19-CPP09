/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:19:31 by plau              #+#    #+#             */
/*   Updated: 2023/09/04 14:42:45 by plau             ###   ########.fr       */
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
	
	std::cout << BOLD_MAGENTA;
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

std::vector<int>	stepOnesplitIntoTwoPairs(std::vector<int> Data, int numberOfElement)
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

std::vector<int>	stepTwocompareSecondElement(std::vector<int> Data, int numberOfElement)
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
			// std::cout << *it << ' ';
			// std::cout << *(it + 2) << ' ';
			std::swap(*it, *(it + 2));
			std::swap(*(it - 1), *(it + 1));
			// printVector(Data);
			it = Data.begin() + 1 - 2;
		}
	}
	return (Data);
}

/* Generate the jacob number based on the size of the pend */
/* My jacob number starts from 1, 1, 3, 5, 11, 21 */
std::vector<int> getJacobsthalNumbers(std::vector<int> pend)
{
	std::vector<int> jacobIndex;
	int sizeOfPend = pend.size();
	int result = 1;
	int	i = 2;
		
	jacobIndex.push_back(1);
	jacobIndex.push_back(1);
	std::cout << "size of pend: " << sizeOfPend << std::endl;
	while (result < sizeOfPend)
	{
		result = result + ((jacobIndex[i - 2]) * 2);
		if (result < sizeOfPend)
			jacobIndex.push_back(result);
		i++;
	}
	jacobIndex.erase(jacobIndex.begin());
	return (jacobIndex);
}

/* insert b1 before a1 first */
/* Insertion sort using Jacobsthal number */
std::vector<int>	insertionSort(std::vector<int> main, std::vector<int> pend, std::vector<int> jacobIndex)
{
	int i = 1;
	// int pendLength = pend.size();
	int jacobVectorSize = jacobIndex.size();
	int num = 0;
	// int insertNum = -1;
	
	main.insert(main.begin(), pend[0]);
	std::cout << BOLD_CYAN << "Main: " << RESET;
	printVector(main);
	std::cout << BOLD_CYAN << "Pend: " << RESET;
	printVector(pend);
	std::cout << std::endl << "Jacob number: ";
	printVector(jacobIndex);
	while (i < jacobVectorSize)
	{
		std::cout << std::endl << "Jacobindex[i]: " << jacobIndex[i] << std::endl;
		std::cout << "i: " << i << std::endl;
		std::cout << "pend num " << pend[jacobIndex[i] - 1] << std::endl;
		main.insert(main.begin() + jacobIndex[i] + num, pend[jacobIndex[i] - 1]);
		std::cout << BOLD_CYAN << "Main: " << RESET;
		printVector(main);
		i++;
		num++;
	}
	std::cout << "Before the end of insertion sort" << std::endl;
	return (main);
}

/* Use for debugging purposes */
int	checkIfSorted(std::vector<int> initialData)
{
	int i = 0;
	int length = initialData.size();

	while (i < (length - 1))
	{
		if (initialData[i] > initialData[i + 1])
		{
			std::cout << BOLD_RED << "Error: Not sorted" << RESET << std::endl;
			return (1);
		}
		i++;
	}
	return (2);
}

/* Step 3 create main chain and pend */
/* main chain: a1 a2 a3 - sorted */
/* pend: 	   b1, b2, b3 - unsorted */
void	stepThreeCreateMainAndPend(std::vector<int> initialData, int numberOfElement)
{
	std::vector<int> main;
	std::vector<int> pend;
	std::vector<int>::iterator it;
	std::vector<int>::iterator ite;
	std::vector<int> jacobIndex;

	if (numberOfElement % 2 == 0)
		ite = initialData.end() + 1;
	else
		ite = initialData.end();
	for (it = initialData.begin() + 1; it != ite; it+=2)
	{
		main.push_back(*it);
		pend.push_back(*(it - 1));
	}
	jacobIndex = getJacobsthalNumbers(pend);
	printVector(main);
	printVector(pend);
	int x = checkIfSorted(main);
	if (x == 1)
	{
		std::cout << BOLD_RED << "Fatal error: Main is unsorted" << RESET << std::endl;
		exit(EXIT_FAILURE);
	}
	std::cout << std::endl << "step 4: insertion sort" << std::endl;
	main = insertionSort(main, pend, jacobIndex);
}

void	sortOddNumber(void)
{
}

void	mergeInsertionSort(int ac, char **av)
{
	std::vector<int> initialData;
	initialData = parseIntoVector(ac, av, initialData);
	int numberOfElement = ac - 1;
	initialData = stepOnesplitIntoTwoPairs(initialData, numberOfElement);
	std::cout << "step 1: sort each pair" << std::endl;
	printVector(initialData);
	std::cout << std::endl << "step 2: compare the 2nd element for each pair" << std::endl;
	initialData = stepTwocompareSecondElement(initialData, numberOfElement);
	printVector(initialData);
	int x = checkIfSorted(initialData);
	if (x == 2)
		return ;
	std::cout << std::endl << "step 3: create main and pend" << std::endl;
	stepThreeCreateMainAndPend(initialData, numberOfElement);
	//last step- the left out odd num
	if (numberOfElement % 2 != 0)
	{
		int lastElement = initialData[numberOfElement - 1];
		std::cout << "lastElement: " << lastElement << std::endl;
		sortOddNumber();
	}
}
