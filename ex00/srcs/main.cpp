/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:53:45 by plau              #+#    #+#             */
/*   Updated: 2023/08/10 20:03:35 by plau             ###   ########.fr       */
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
	openFile(av[1]);
	std::map<std::string, int> Map;
	
	return (0);
}
