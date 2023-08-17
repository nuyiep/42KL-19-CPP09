/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:23:22 by plau              #+#    #+#             */
/*   Updated: 2023/08/17 20:38:11 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include "color.hpp"
#include <iostream>
#include <stack>

void		checkAvFormat(char *av); 
void		checkInvalidCharacter(char *av); 
void		checkNumbersLessThanTen(char *av); 
void		parseIntoStack(char *av); 
void		checkSeparatedBySpaces(char *av); 
void		checkFirstTwoIsDigit(char *av); 
char*		trimSpacesBeforeFirstElement(char *av);

#endif
