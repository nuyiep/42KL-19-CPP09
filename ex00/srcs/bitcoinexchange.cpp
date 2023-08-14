/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitcoinexchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:55:36 by plau              #+#    #+#             */
/*   Updated: 2023/08/14 17:08:43 by plau             ###   ########.fr       */
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
	std::multimap<std::string, double> Map;
	
	std::string line;
	std::getline(inputFile, line);
	while (std::getline(inputFile, line))
	{
		std::cout << BOLD_GREEN << line << RESET << std::endl;
		std::istringstream iss(line);
		std::string date;
		std::string value;
		char delimiter = '|';
		if (std::getline(iss, date, delimiter) && std::getline(iss, value, delimiter))
			Map.insert(std::make_pair(date, std::stod(value)));
		else
			std::cerr << RED << "Failed to parse line: " << line << RESET << std::endl;
	}
	inputFile.close();
	printMap(Map);
}


void	printMap(std::multimap<std::string, double> Map)
{
	std::map<std::string, double>::iterator it;
	if (Map.empty())
	{
		std::cout << "map is empty" << std::endl;
		exit(EXIT_FAILURE);
	}
	for (it = Map.begin(); it != Map.end(); ++it)
	{
		std::cout << BOLD_CYAN << it->first << ": " << it->second << RESET << std::endl;
	}
}
