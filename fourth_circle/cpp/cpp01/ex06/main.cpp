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

int main(int ac, char *av[])
{
	Harl harl;
	string cmd;

	if (ac != 2)
		cmd = "Wrong";
	else
		cmd = av[1];
	harl.complain(cmd);
	cout << "\001\033[0;39m\002";

	return (0);
}
