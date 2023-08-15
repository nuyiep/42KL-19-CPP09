/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:53:45 by plau              #+#    #+#             */
/*   Updated: 2023/08/15 15:16:07 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitcoinexchange.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Error: please provide a file name" << std::endl;
		return (1);
	}
	
	parseLine();
	// openFileAndGetLine(av[1]);
	(void)av;
	return (0);
}

/* Use std::map because it maintains the order of insertion */
