/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:19:16 by plau              #+#    #+#             */
/*   Updated: 2023/08/22 17:09:27 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	printBeforeAndErrorChecking(ac, av);
	foJoMergeInsertionSort(ac, av);
	std::cout << "Time to process a range of " << ac - 1 << " elements with std::" << std::endl; 
	return (0);
}
