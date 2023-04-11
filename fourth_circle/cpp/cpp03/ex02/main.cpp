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

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	ScavTrap *c1 = new ScavTrap();
	FragTrap *c2 = new FragTrap("Zoro");
	FragTrap *aux = new FragTrap();
	FragTrap *c3 = new FragTrap(*aux);

	cout << std::endl;

	c1->attack("Slime");
	c2->attack("Sanji");
	c3->attack("Slime shiny");

	cout << std::endl;

	c1->takeDamage(80);
	c2->takeDamage(50);
	c2->takeDamage(50);
	c3->takeDamage(5);

	cout << std::endl;

	c1->beRepaired(1000);
	c2->beRepaired(1);
	c3->beRepaired(5);

	cout << std::endl;

	c1->guardGate();
	c2->highFivesGuys();
	c3->highFivesGuys();

	cout << std::endl;

	delete c1;
	delete c2;
	delete aux;
	delete c3;	
	return (0);
}
