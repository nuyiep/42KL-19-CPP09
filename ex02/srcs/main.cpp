/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:19:16 by plau              #+#    #+#             */
/*   Updated: 2023/09/05 19:18:56 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	std::chrono::microseconds processingTime;

	printBeforeAndErrorChecking(ac, av);
	processingTime = mergeInsertionSort(ac, av);
	std::cout << "Time to process a range of " << ac - 1 << " elements with std::vector : " << processingTime.count() << " microseconds" << std::endl; 

	return (0);
}
