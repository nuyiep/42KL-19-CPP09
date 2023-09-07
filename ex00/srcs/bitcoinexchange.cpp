/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitcoinexchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:55:36 by plau              #+#    #+#             */
/*   Updated: 2023/09/07 11:58:44 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitcoinexchange.hpp"

/*  */
std::map<std::string, double>	parseLine(void)
{
	std::ifstream inputFile("data.csv");
	if (!inputFile.is_open())
	{
		std::cerr << "Error opening file" << std::endl;
		exit(EXIT_FAILURE);
	}
	std::map<std::string, double> dataMap;
	std::string line;
	std::getline(inputFile, line);
	if (line.size() == 0)
	{
		std::cout << BOLD_MAGENTA << "Error" << line << std::endl;
		exit (EXIT_FAILURE);
	}
	while (std::getline(inputFile, line))
	{
		// std::cout << BOLD_GREEN << line << RESET << std::endl;
		std::istringstream iss(line); // 2009-01-02, 0
		std::string date;
		std::string value;
		if (std::getline(iss, date, ',') && std::getline(iss, value, '\n')) //2009-01-02  
			dataMap.insert(std::make_pair(date, std::stod(value)));
		else
			std::cerr << RED << "Error: bad input => " << line << RESET << std::endl;
	}
	inputFile.close();
	int size = dataMap.size();
	if (size == 0)
	{
		std::cout << BOLD_MAGENTA << "Error: table is empty" << std::endl;
		exit (EXIT_FAILURE);
	}
	return(dataMap);
}

std::string trimEnd(std::string date)
{
	std::string trimmedDate;
	size_t last = date.find_last_not_of(' '); //find the index of the last non-space character
	if (std::string::npos != last)
		return date.substr(0, last + 1);
	return (date);
}

int checkForValidDate(int year, int month, int day)
{
	int februaryDay = 28;
	
	if (year % 4 == 0)
	{
		if (year % 100 == 0)
		{
			if (year % 400 == 0) 
			{
				// std::cout << "Is a leap year" << std::endl;
				februaryDay = 28 + 1;				
			}
			// else
			// 	std::cout << "Not a leap year" << std::endl;
		}
		else
		{
			// std::cout << "Is a leap year" << std::endl;
			februaryDay = 28 + 1;
		}
	}
	// else
	// 	std::cout << "Not a leap year" << std::endl;
	int maxDayForEachMonth[12] = {31, februaryDay, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (day > maxDayForEachMonth[month - 1] || day < 1)
		return (1);
	if (month > 12 || month < 1)
		return (1);
	return (0);
}

int checkEarlierDate(std::string trimmedDate, std::map<std::string, double> dataMap, int year, int month, int day)
{
	//date before first date in dataMap is invalid
	std::map<std::string, double>::iterator firstElement = dataMap.begin();
	int firstDataYear = std::stoi(firstElement->first.substr(0, 4));
	int firstDataMonth = std::stoi(firstElement->first.substr(5, 2));
	int firstDataDay = std::stoi(firstElement->first.substr(8, 2));
	if ((firstDataYear > year)|| (firstDataYear == year && firstDataMonth > month) || (firstDataYear == year && firstDataMonth == month && firstDataDay > day))
	{
		std::cerr << RED << "Error: date out of range [earlier than first data]=> " << trimmedDate << RESET << std::endl;
		return (1);
	}
	//date after last date in dataMap is invalid
	std::map<std::string, double>::iterator lastElement = dataMap.end();
	lastElement--; 
	int lastDataYear = std::stoi(lastElement->first.substr(0, 4));
	int lastDataMonth = std::stoi(lastElement->first.substr(5, 2));
	int lastDataDay = std::stoi(lastElement->first.substr(8, 2));
	if ((lastDataYear < year)|| (lastDataYear == year && lastDataMonth < month) || (lastDataYear == year && lastDataMonth == month && lastDataDay < day))	
	{
		std::cerr << RED << "Error: date out of range [later than the last data]=> " << trimmedDate << RESET << std::endl;
		return (1);
	}
	return (0);
}

int	checkDateFormat(std::string trimmedDate, std::map<std::string, double> dataMap)
{
	if (trimmedDate.length() != 10)
	{
		std::cerr << RED << "Error: invalid date format => " << trimmedDate << RESET << std::endl;
		return (1);
	}
	if (trimmedDate[4] != '-' || trimmedDate[7] != '-')
	{
		std::cerr << RED << "Error: invalid date format => " << trimmedDate << RESET << std::endl;
		return (1);
	}
	int year = std::stoi(trimmedDate.substr(0, 4));
	int month = std::stoi(trimmedDate.substr(5, 2));
	int day = std::stoi(trimmedDate.substr(8, 2));
	if (checkEarlierDate(trimmedDate, dataMap, year, month, day) == 1)
		return (1);
	if (checkForValidDate(year, month, day) == 1)
	{
		std::cerr << RED << "Error: invalid date => " << trimmedDate << RESET << std::endl;
		return (1);
	}
	return (0);
}

void	doOperation(std::map<std::string, double> dataMap, char *avOne)
{
	std::ifstream inputFile(avOne);
	if (!inputFile.is_open())
	{
		std::cerr << "Error opening file" << std::endl;
		exit(EXIT_FAILURE);
	}
	std::map<std::string, double>::iterator it;
	std::string line;
	std::getline(inputFile, line);
	while (std::getline(inputFile, line))
	{
		std::istringstream iss(line);
		std::string delimiter = "|";
		size_t pos = line.find(delimiter);
		double numericResult = 0;
		double finalResult = 0;
		if (pos != std::string::npos)
		{
			std::string date = line.substr(0, pos); //want to extract a substring from line starting from index 0
			std::string result = line.substr(pos + delimiter.length()); //starting index is pos+delimiter.length()
			std::string trimmedDate = trimEnd(date);
			if (checkDateFormat(trimmedDate, dataMap) == 1)
				continue ;
			numericResult = std::stod(result);
			if (numericResult > 1000)
			{
				std::cerr << RED << "Error: too large a number." << RESET << std::endl;
				continue ;
			}
			if (numericResult < 0)
			{
				std::cerr << RED << "Error: too small a number." << RESET << std::endl;
				continue ;
			}
			it = dataMap.find(trimmedDate);
			if (it != dataMap.end()) 
			{
				// std::cout << it->first << ": " << it->second << std::endl;
				finalResult = numericResult * it->second;
			} 
			else 
			{
				it = dataMap.lower_bound(trimmedDate);
				it--;
				finalResult = numericResult * it->second;
				// std::cout << it->first << ": " << it->second << std::endl;
			}
			if (finalResult < 0)
			{
				std::cerr << RED << "Error: not a positive number." << RESET << std::endl;
				continue ;
			}
			std::cout << BOLD_GREEN << date << " => " << result << " = " << finalResult << RESET << std::endl;
		}
		else
			std::cerr << RED << "Error: bad input => " << line << RESET << std::endl;
	}
	inputFile.close();
	// printMap(dataMap);
}

void	printMap(std::map<std::string, double> dataMap)
{
	// std::map<std::string, double>::iterator it;
	std::map<std::string, double>::iterator firstElement = dataMap.begin();
	if (dataMap.empty())
	{
		std::cout << "map is empty" << std::endl;
		exit(EXIT_FAILURE);
	}
	std::cout << firstElement->first << std::endl;
	// std::cout << firstElement->first << ": " << firstElement->second << std::endl;
	// for (it = dataMap.begin(); it != dataMap.end(); ++it)
	// {
	// 	std::cout << BOLD_CYAN << it->first << ": " << it->second << RESET << std::endl;
	// }
}
