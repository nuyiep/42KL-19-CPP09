/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitcoinexchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:55:36 by plau              #+#    #+#             */
/*   Updated: 2023/08/10 13:53:34 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitcoinexchange.hpp"

void	openFile(char *av)
{
	std::ifstream inputFile(av);

	if (!inputFile.is_open())
	{
		std::cerr << "Error opening file" << std::endl;
		exit(EXIT_FAILURE);
	}
		
}
