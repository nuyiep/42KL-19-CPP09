/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:19:31 by plau              #+#    #+#             */
/*   Updated: 2023/08/22 17:18:23 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::vector<int> vectorData;

void	printBeforeAndErrorChecking(int ac, char **av)
{
	std::cout << "Before: ";
	int i = 1;
	
	while (i < ac)
	{
		if (atoi(av[i]) )
		std::cout << av[i] << ' ';
		i++;
	}
	std::cout << std::endl;
}

void	printVector(std::vector<int> Data)
{
	std::vector<int>::iterator it = Data.begin();
	std::vector<int>::iterator ite = Data.end();
	
	while (it != ite)
	{
		std::cout << *it << ' ';
		++it;
	}
	std::cout << std::endl;
}

void	parseIntoVector(int ac, char **av)
{
	for (int i = 1; i < ac; i ++)
		vectorData.push_back(atoi(av[i]));
	//printVector(vectorData);
}

void	splitIntoTwoPairs(std::vector<int> Data)
{
	std::vector<int>::iterator it = Data.begin();
	std::vector<int>::iterator ite = Data.end();

}

void	foJoMergeInsertionSort(int ac, char **av)
{
	parseIntoVector(ac, av);
	splitIntoTwoPairs(vectorData);
	
}

