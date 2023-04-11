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

#include "Zombie.hpp"

Zombie:: Zombie(void)
{
	this->name = "";
	cout << "Zombie is created without name" << std::endl;
}

Zombie:: Zombie(string name)
{
	this->name = name;
	cout << "Zombie " << name << " is created" << std::endl;
}

Zombie:: ~Zombie(void)
{
	if (this->name.length())
		cout << "Zombie " << this->name << " is destoryed" << std::endl;
	else
		cout << "Zombie(no name) " << "is destoryed" << std::endl;
}

void Zombie::announce(void)
{
	if (this->name.length())
		cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	else
		cout << "(no name): BraiiiiiiinnnzzzZ..." << std::endl;
}
