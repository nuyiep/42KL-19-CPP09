/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe_deque.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:20:01 by plau              #+#    #+#             */
/*   Updated: 2023/09/06 21:14:12 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	printDeque(std::deque<int> Data)
{
	std::deque<int>::iterator it = Data.begin();
	std::deque<int>::iterator ite = Data.end();
	
	std::cout << BOLD_MAGENTA;
	while (it != ite)
	{
		std::cout << *it << ' ';
		++it;
	}
	std::cout << RESET << std::endl;
}

std::deque<int>	parseIntoDeque(int ac, char **av, std::deque<int> initialData)
{
	for (int i = 1; i < ac; i ++)
		initialData.push_back(atoi(av[i]));
	
	return(initialData);
}

void	splitPairsRecursive(std::deque<int>::iterator it, std::deque<int>::iterator ite)
{
	if (it == ite)
		return ; //base case
	if (*it > *(it + 1))
		std::swap(*it, *(it + 1));
	splitPairsRecursive(it + 2, ite);
}

std::deque<int>	stepOnesplitIntoTwoPairs(std::deque<int> Data, int numberOfElement)
{
	std::deque<int>::iterator it;
	std::deque<int>::iterator ite;

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

void	compareSecondElementRecursive(std::deque<int>::iterator it, std::deque<int>::iterator ite)
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

std::deque<int>	stepTwocompareSecondElement(std::deque<int> Data, int numberOfElement)
{
	std::deque<int>::iterator it;
	std::deque<int>::iterator ite;

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
			// printDeque(Data);
			it = Data.begin() + 1 - 2;
		}
	}
	return (Data);
}

/* Generate the jacob number based on the size of the pend */
/* My jacob number starts from 1, 1, 3, 5, 11, 21 */
std::deque<int> getJacobsthalNumbers(std::deque<int> pend)
{
	std::deque<int> jacobIndex;
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

std::deque<int> insertNumIntoMain(std::deque<int> updatedMain, int num)
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
std::deque<int>	insertionSort(std::deque<int> originalMain, std::deque<int> pend, std::deque<int> jacobIndex)
{
	std::deque<int> updatedMain(originalMain); //deep copy
	int i = 1;
	int jacobDequeSize = jacobIndex.size();
	int j = 1;
	int k = 0;
	
	updatedMain.insert(updatedMain.begin(), pend[0]);
	while (i < jacobDequeSize)
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
	int lastJacobNum = jacobIndex[jacobDequeSize - 1];
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
int	checkIfSorted(std::deque<int> initialData)
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
void	stepThreeCreateMainAndPend(std::deque<int> initialData, int numberOfElement)
{
	std::deque<int> main;
	std::deque<int> pend;
	std::deque<int>::iterator it;
	std::deque<int>::iterator ite;
	std::deque<int> jacobIndex;

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
	std::cout << BOLD_MAGENTA << "After (Deque): \t";
	printDeque(main);
	checkIfSorted(main);
}

std::chrono::microseconds	mergeInsertionSortDeque(int ac, char **av)
{
	std::chrono::steady_clock::time_point startTime = std::chrono::steady_clock::now();
	
	std::deque<int> initialData;
	initialData = parseIntoDeque(ac, av, initialData);
	int numberOfElement = ac - 1;
	initialData = stepOnesplitIntoTwoPairs(initialData, numberOfElement);
	initialData = stepTwocompareSecondElement(initialData, numberOfElement);
	int x = checkIfSorted(initialData);
	if (x == 2)
	{
		std::cout << BOLD_MAGENTA << "After:\t\t";
		printDeque(initialData);
		std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
		std::chrono::microseconds duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - startTime);
		return (duration);
	}
	stepThreeCreateMainAndPend(initialData, numberOfElement);
	std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
	std::chrono::microseconds duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - startTime);
	return (duration);
}
