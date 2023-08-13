/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitcoinexchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:55:36 by plau              #+#    #+#             */
/*   Updated: 2023/08/13 18:56:09 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitcoinexchange.hpp"

void	openFileAndGetLine(char *avOne)
{
	std::ifstream inputFile(avOne);
	if (!inputFile.is_open())
	{
		std::cerr << "Error opening file" << std::endl;
		exit(EXIT_FAILURE);
	}
	std::map<std::string, int> Map;
	
	std::string line;
	int i = 0;
	while (std::getline(inputFile, line))
	{
		std::istringstream iss(line);
		std::string key;
		int value;
		if (i != 0)
		{
			if (iss >> key >> value)
				Map[key] = value;
			else
				std::cout << "Failed to parse line " << line << std::endl;
		}
		i = i + 1;
	}
	printMap(Map);
}

void	printMap(std::map<std::string, int> Map)
{
	std::map<std::string, int>::iterator it;
	if (Map.empty())
	{
		std::cout << "map is empty" << std::endl;
		exit(EXIT_FAILURE);
	}
	for (it = Map.begin(); it != Map.end(); ++it)
	{
		std::cout << it->first << ": " << it->second << std::endl;
	}
}
