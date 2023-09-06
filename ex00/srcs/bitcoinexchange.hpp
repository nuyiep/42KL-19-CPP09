/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitcoinexchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:55:33 by plau              #+#    #+#             */
/*   Updated: 2023/09/06 16:16:29 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

//Date() - constructor of the Date struct
//initialize them to -1
// struct Date
// {
// 	Date() : year(-1), month(-1), day(-1) {}
// 	int year;
// 	int month;
// 	int day;
// };

#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <iomanip>
#include <limits>
#include <cmath>
#include <ctime>
#include "color.hpp"

void							printMap(std::map<std::string, double> Map);
std::map<std::string, double>	parseLine(void);
void							doOperation(std::map<std::string, double> Map, char *avOne);

#endif
