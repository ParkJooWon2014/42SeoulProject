/**********************************************************************
 * Copyright (c) 2023
 *  Joowon park <ghonman2@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTIABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 **********************************************************************/

#include "PmergeMe.hpp"

int isAllDigit(std::string sNum)
{
	if (sNum.length() == 0)
		return (1);
	for (size_t i = 0; i < sNum.size(); i++){
		if (!isdigit(sNum[i]))
			return (1);
	}
	return (0);
}


int main(int ac, char **av)
{
	const int rate = 3;
	std::deque<int> numbers;
	if (ac == 1)
	{
		std::cout << "ERROR" << std::endl;
		return (0);
	}
	for (int i = 1; i < ac; i ++)
	{
		if (isAllDigit(av[i]))
		{
			std::cout << "ERROR" << std::endl;
			return (0);
		}
		if (atof(av[i]) > INT_MAX)
		{
			std::cout << "ERROR" << std::endl;
			return (0);
		}
		numbers.push_back(atoi(av[i]));
	}
	std::cout << "Before : ";
	for(size_t i = 0 ; i < numbers.size(); i ++)
		std::cout << " "<< numbers[i];
	std::cout << std::endl;
	
	std::vector<int>v(numbers.begin(), numbers.end());
	std::deque<int>d(numbers.begin(), numbers.end());

	PmergeMeDeque(d, rate);
	PmergeMeVector(v, rate);
	return (0);
}
