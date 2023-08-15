/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitcoinexchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:55:36 by plau              #+#    #+#             */
/*   Updated: 2023/08/15 18:12:11 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitcoinexchange.hpp"

std::map<std::string, double>	parseLine(void)
{
	std::ifstream inputFile("data.csv");
	if (!inputFile.is_open())
	{
		std::cerr << "Error opening file" << std::endl;
		exit(EXIT_FAILURE);
	}
	std::map<std::string, double> Map;
	
	std::string line;
	std::getline(inputFile, line);
	while (std::getline(inputFile, line))
	{
		// std::cout << BOLD_GREEN << line << RESET << std::endl;
		std::istringstream iss(line);
		std::string date;
		std::string value;
		char delimiter = ',';
		if (std::getline(iss, date, delimiter) && std::getline(iss, value, delimiter))
			Map.insert(std::make_pair(date, std::stod(value)));
		else
			std::cerr << RED << "Error: bad input => " << line << RESET << std::endl;
	}
	inputFile.close();
	printMap(Map);
	return(Map);
}

void	operation(std::map<std::string, double> Map, char *avOne)
{
	std::map<std::string, double>::iterator it;

	
}

// void	openFileAndGetLine(char *avOne)
// {
// 	std::ifstream inputFile(avOne);
// 	if (!inputFile.is_open())
// 	{
// 		std::cerr << "Error opening file" << std::endl;
// 		exit(EXIT_FAILURE);
// 	}
// 	std::string line;
// 	std::getline(inputFile, line);
// 	while (std::getline(inputFile, line))
// 	{
// 		std::cout << BOLD_GREEN << line << RESET << std::endl;
// 		std::istringstream iss(line);
// 		std::string date;
// 		std::string value;
// 		char delimiter = '|';
// 		if (std::getline(iss, date, delimiter) && std::getline(iss, value, delimiter))
// 			Map.insert(std::make_pair(date, std::stod(value)));
// 		else
// 			std::cerr << RED << "Error: bad input => " << line << RESET << std::endl;
// 	}
// 	inputFile.close();
// 	printMap(Map);
// }

void	printMap(std::map<std::string, double> Map)
{
	// std::map<std::string, double>::iterator it;
	std::map<std::string, double>::iterator firstElement = Map.begin();
	if (Map.empty())
	{
		std::cout << "map is empty" << std::endl;
		exit(EXIT_FAILURE);
	}
	std::cout << firstElement->first << std::endl;
	// std::cout << firstElement->first << ": " << firstElement->second << std::endl;
	// for (it = Map.begin(); it != Map.end(); ++it)
	// {
	// 	std::cout << BOLD_CYAN << it->first << ": " << it->second << RESET << std::endl;
	// }
}
