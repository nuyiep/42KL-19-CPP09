/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:21:29 by plau              #+#    #+#             */
/*   Updated: 2023/08/18 15:18:53 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

void	checkAvFormat(char *av)
{
	checkInvalidCharacter(av);
	checkNumbersLessThanTen(av);
	checkFirstTwoIsDigit(av);
	checkSeparatedBySpaces(av);
	checkLastElement(av);
	checkNumOfDigitsAndOperations(av);
}

void	doOperation(char *av)
{
	std::stack<int> dataStack;
	int i = 0;

	while (av[i] != '\0')
	{
		if (isdigit(av[i]))
			dataStack.push(av[i]);
		else
		{
			
		}
		i++;
	}
}

// void	checkNumOfDigitsAndOperations(char *av)
// {
// 	int digits = 0;
// 	int operations = 0;

// 	while (av[i])
// }

void	checkLastElement(char *av)
{
	int len = 0;
	while (av[len] != 0)
		len++;
	len--;
	if (av[len] != '+' && av[len] != '-' && av[len] != '*' && av[len] != '/')
	{
		std::cout << "Error: Last element has to be an operation" << std::endl;
		exit(EXIT_FAILURE);
	}
}

void	checkFirstTwoIsDigit(char *av)
{
	int result = 0;
	if (isdigit(av[0]) != 1)
	{
		std::cout << "Error: First element has to be a digit" << std::endl;
		exit(EXIT_FAILURE);
	}
	result = isdigit(av[2]);
	if (isdigit(av[2]) != 1)
	{
		std::cout << "Error: Second element has to be a digit" << std::endl;
		exit(EXIT_FAILURE);
	}
}

void	checkInvalidCharacter(char *av)
{
	int i = 0;
	int result = 0;
	
	while (av[i] != '\0')
	{
		result = isdigit(av[i]);
		if (result != 1 && av[i] != ' ' && av[i] != '+' && av[i] != '-' && av[i] != '*' && av[i] != '/')
		{
			std::cout << "Error: invalid character: " << BOLD_RED << av[i] << RESET << std::endl;
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	checkNumbersLessThanTen(char *av)
{
	int i = 0;
	int result = 0;

	while (av[i + 1] != '\0')
	{
		result = isdigit(av[i]);
		if (result == 1)
		{
			result = isdigit(av[i + 1]);
			if (result == 1)
			{
				std::cout << "Error: number cannot be more than ten: " << BOLD_RED << av[i] << av[i + 1] << RESET << std::endl; 
				exit(EXIT_FAILURE);
			}
		}
		i++;
	}
}

void	checkSeparatedBySpaces(char *av)
{
	int i = 1;

	while (av[i] != '\0')
	{
		if (av[i] != ' ')
		{
			std::cout << "Error: not separated by spaces: " << BOLD_RED << av[i] << RESET << std::endl;
			exit(EXIT_FAILURE);
		}
		i = i + 2;
	}
}
