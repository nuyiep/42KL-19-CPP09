/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:19:31 by plau              #+#    #+#             */
/*   Updated: 2023/09/05 19:17:57 by plau             ###   ########.fr       */
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
	while (result <= sizeOfPend)
	{
		result = result + ((jacobIndex[i - 2]) * 2);
		if (result <= sizeOfPend)
			jacobIndex.push_back(result);
		i++;
	}
	jacobIndex.erase(jacobIndex.begin());
	return (jacobIndex);
}

std::vector<int> insertNumIntoMain(std::vector<int> updatedMain, int num)
{
	int left = 0;
	int right = updatedMain.size() - 1;
	int mid = (left + right) / 2;
	int index = -1;

	if (num <= updatedMain[0])
	{
		updatedMain.insert(updatedMain.begin(), num);
		return (updatedMain);
	}
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
			index = mid + 1;
	}
	index = mid + 1;
	updatedMain.insert(updatedMain.begin() + index, num);
	return (updatedMain);
}

/* insert b1 before a1 first */
/* Insertion sort using Jacobsthal number */
/* deep copy using copy constructor */
std::vector<int>	insertionSort(std::vector<int> originalMain, std::vector<int> pend, std::vector<int> jacobIndex)
{
	std::vector<int> updatedMain(originalMain); //deep copy
	int i = 1;
	int jacobVectorSize = jacobIndex.size();
	int j = 1;
	int k = 0;
	
	updatedMain.insert(updatedMain.begin(), pend[0]);
	while (i < jacobVectorSize)
	{
		updatedMain = insertNumIntoMain(updatedMain, pend[jacobIndex[i] - 1]);
		j = jacobIndex[i - 1];
		k = jacobIndex[i];
		k--;
		while (k > j)
		{
			updatedMain = insertNumIntoMain(updatedMain, pend[k - 1]);
			k--;
		}
		i++;
	}
	// sortPendElementAfterLastJacobNum();
	int lastJacobNum = jacobIndex[jacobVectorSize - 1];
	int z = pend.size();
	if (z > lastJacobNum)
	{
		while (z > lastJacobNum)
		{
			updatedMain = insertNumIntoMain(updatedMain, pend[z - 1]);
			z--;
		}
	}
	return (updatedMain);
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
			// std::cout << BOLD_RED << "Error: Not sorted" << RESET << std::endl;
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
	int x = checkIfSorted(main);
	if (x == 1)
	{
		std::cout << BOLD_RED << "Fatal error: Main is unsorted" << RESET << std::endl;
		exit(EXIT_FAILURE);
	}
	main = insertionSort(main, pend, jacobIndex);
	//last step- the left out odd num
	if (numberOfElement % 2 != 0)
	{
		int oddLastElement = initialData[numberOfElement - 1];
		main = insertNumIntoMain(main, oddLastElement);
	}
	std::cout << "After: \t";
	printVector(main);
	checkIfSorted(main);
}

std::chrono::microseconds	mergeInsertionSort(int ac, char **av)
{
	std::chrono::steady_clock::time_point startTime = std::chrono::steady_clock::now();

	std::vector<int> initialData;
	initialData = parseIntoVector(ac, av, initialData);
	int numberOfElement = ac - 1;
	initialData = stepOnesplitIntoTwoPairs(initialData, numberOfElement);
	initialData = stepTwocompareSecondElement(initialData, numberOfElement);
	int x = checkIfSorted(initialData);
	if (x == 2)
	{
		std::cout << "After: ";
		printVector(initialData);
		std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
		std::chrono::microseconds duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - startTime);
		return (duration);
	}
	stepThreeCreateMainAndPend(initialData, numberOfElement);
	std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
	std::chrono::microseconds duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - startTime);
	return (duration);
}
