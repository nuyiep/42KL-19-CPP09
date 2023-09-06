/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:19:16 by plau              #+#    #+#             */
/*   Updated: 2023/09/06 21:11:51 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	std::chrono::microseconds processingTimeVec;
	std::chrono::microseconds processingTimeDeque;
	
	if (ac == 2)
	{
		std::cout << BOLD_RED << "Error: Need more than 1 number to sort" << RESET << std::endl;
		return (1);
	}
	printBeforeAndErrorChecking(ac, av);
	processingTimeVec = mergeInsertionSortVec(ac, av);
	processingTimeDeque = mergeInsertionSortDeque(ac, av);
	std::cout << "Time to process a range of " << ac - 1 << " elements with std::vector: " << processingTimeVec.count() << " microseconds" << std::endl; 
	std::cout << "Time to process a range of " << ac - 1 << " elements with std::deque : " << processingTimeDeque.count() << " microseconds" << std::endl; 
	return (0);
}
