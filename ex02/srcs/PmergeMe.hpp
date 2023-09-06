/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:19:40 by plau              #+#    #+#             */
/*   Updated: 2023/09/06 12:19:45 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include "color.hpp"
#include <iostream> //cout
#include <vector> //vector
#include <algorithm>
#include <chrono> //time
#include <cstring> //strcmp

void							printBeforeAndErrorChecking(int ac, char **av);
std::chrono::microseconds		mergeInsertionSort(int ac, char **av);
int								checkIfSorted(std::vector<int> initialData);

#endif
