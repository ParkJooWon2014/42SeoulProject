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

#include "RPN.hpp"

int main(int ac, char **av){

	RPN r;
	int answer = 0;
	if (ac != 2 || *(av[1]) == '\0' || r.calInput(answer, av[1]))
	{
		std::cout << "Wrong input!" << std::endl;
		return (0);
	}
	std::cout << answer << std::endl;
	return (0);
}
