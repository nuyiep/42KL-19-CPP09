/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:21:29 by plau              #+#    #+#             */
/*   Updated: 2023/08/19 18:22:00 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

void	checkAvFormat(char *av)
{
	checkInvalidCharacter(av);
	checkNumbersLessThanTen(av);
	checkExtraSpacesAndTrailingSpaces(av);
	checkFirstTwoIsDigit(av);
	checkSeparatedBySpaces(av);
	checkLastElement(av);
	checkNumOfDigitsAndOperations(av);
}

void	doOperation(char *av)
{
	std::stack<int> dataStack;
	int i = 0;
	long first = 0; 
	long second = 0; 
	long result = 0;

	while (av[i] != '\0')
	{
		if (isdigit(av[i]) == 1)
		{
			dataStack.push(av[i] - '0');
			i++;
		}
		else if (av[i] == ' ')
			i++;
		else if (av[i] == '+' || av[i] == '-' || av[i] == '*' || av[i] == '/')
		{
			second = dataStack.top();
			dataStack.pop();
			first = dataStack.top();
			dataStack.pop();
			if (av[i] == '+')
				result = first + second;
			else if (av[i] == '-')
				result = first - second;
			else if (av[i] == '*')
				result = first * second;
			else if (av[i] == '/')
			{
				if (second == 0)
				{
					std::cout << "Error: cannot be divided by 0" << std::endl;
					exit(EXIT_FAILURE);
				}
				result = first / second;
			}
			checkResult(result);
			dataStack.push(result);
			i++;
		}
	}
	if (dataStack.size() != 1)
	{
		std::cout << "Error: invalid operation" << std::endl;
		exit(EXIT_FAILURE);
	}
	std::cout << BOLD_MAGENTA << dataStack.top() << RESET << std::endl;
}

void	checkResult(long result)
{
	if (result < std::numeric_limits<int>::min())
	{
		std::cout << "Error: result can't be smaller tha INT_MIN" << std::endl;
		exit(EXIT_FAILURE);
	}
	if (result > std::numeric_limits<int>::max())
	{
		std::cout << "Error: result can't be larger tha INT_MAX" << std::endl;
		exit(EXIT_FAILURE);
	}
}

void	printStack(std::stack<int>dataStack)
{
	while (!dataStack.empty())
	{
		std::cout << BOLD_MAGENTA << dataStack.top() << RESET << " ";
		dataStack.pop();
	}
	std::cout << std::endl;
}

void	checkExtraSpacesAndTrailingSpaces(char *av)
{
	int	i = 0;

	while (av[i + 1] != '\0')
	{
		if (av[i] == ' ' && av[i + 1] == ' ')
		{
			std::cout << "Error: cannot have extra spaces" << std::endl;
			exit(EXIT_FAILURE);
		}
		i++;
	}
	int len = 0;
	while (av[len] != '\0')
		len++;
	len--;
	if (av[len] == ' ')
	{
		std::cout << "Error: cannot have spaces as the last character" << std::endl;
		exit(EXIT_FAILURE);
	}
}

void	checkNumOfDigitsAndOperations(char *av)
{
	int digits = 0;
	int operations = 0;
	int i = 0;
	
	while (av[i] != '\0')
	{
		if (isdigit(av[i]) == 1)
			digits++;
		else if (av[i] == '+' || av[i] == '-' || av[i] == '*' || av[i] == '/')
			operations++;
		i++;
	}
	if (digits - operations != 1)
	{
		std::cout << "Error: invalid RPN" << std::endl;
		exit(EXIT_FAILURE);
	}
}

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
				std::cout << "Error: number cannot be more than ten" << RESET << std::endl; 
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
