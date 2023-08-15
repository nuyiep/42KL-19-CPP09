/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitcoinexchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:55:33 by plau              #+#    #+#             */
/*   Updated: 2023/08/15 18:05:53 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <iomanip>
#include <limits>
#include <cmath>
#include "color.hpp"

void							openFileAndGetLine(char *avOne);
void							printMap(std::map<std::string, double> Map);
std::map<std::string, double>	parseLine(void);
void							operation(std::map<std::string, double> Map, char *avOne);

#endif
