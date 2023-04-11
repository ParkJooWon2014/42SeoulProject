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

#include "Harl.hpp"
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(NULL));
	const string menu[5] = {"DEBUG", "WARNING", "INFO", "ERROR", "WRONG"};
	Harl harl;

	for (int i = 0 ; i < 100; i ++){
		harl.complain(menu[rand() % 5]);
		cout << "\001\033[0;39m\002";
	}
	while(1)
	{
		string str = "";
		cout << NORM;
		cout << "Choose what you want(DEBUG, WARNING, INFO, ERROR) :" ;
		getline(std::cin, str);
		if (std::cin.eof())
			break ;
		harl.complain(str);
	}
	return (0);
}
