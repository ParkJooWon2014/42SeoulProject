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

#include "DiamondTrap.hpp"

int main(void)
{
	/*
	cout << "### TESTING CLAPTRAP ###\n" << std::endl;
	{
		cout << "\033[34mConstructing\033[0m" << std::endl;
		ClapTrap a;
		ClapTrap b("Cody");

		cout << "\033[34mTesting\033[0m" << std::endl;
		a.attack("some other robot");
		a.takeDamage(10);
		a.takeDamage(10);
		a.beRepaired(5);
		a.attack("some other other robot");
		b.beRepaired(3);
		for (int i = 0; i < 12; i++)
			b.attack("Cody-clone");
		b.beRepaired(3);
		cout << "\033[34mDeconstructing\033[0m" << std::endl;
	}
	cout << "\n\n### TESTING SCAVTRAP ###\n" << std::endl;
	{
		cout << "\033[34mConstructing\033[0m" << std::endl;
		ScavTrap a;
		ScavTrap b("Savage");

		cout << "\033[34mTesting\033[0m" << std::endl;
		a.attack("CloneTrap");
		// for (int i = 0; i < 50; i++)
		// 	a.attack("CloneTrap");
		a.beRepaired(22);
		a.takeDamage(21);
		a.beRepaired(22);
		a.guardGate();
		a.guardGate();
		b.attack("Savage-clone");
		b.takeDamage(101);
		b.takeDamage(15);
		b.attack("ScavTrap-clone");
		cout << "\033[34mDeconstructing\033[0m" << std::endl;
	}
	cout << "\n\n### TESTING FRAGTRAP ###\n" << std::endl;
	{
		cout << "\033[34mConstructing\033[0m" << std::endl;
		FragTrap a;
		FragTrap b("Chadd");

		cout << "\033[34mTesting\033[0m" << std::endl;
		a.highFivesGuys();
		a.attack("some random dude");
		a.takeDamage(101);
		a.takeDamage(1);
		a.attack("some random dude");
		b.highFivesGuys();
		// for(int i = 0; i < 101; i++)
		// 	b.attack("FragTrap-clone");
		cout << "\033[34mDeconstructing\033[0m" << std::endl;
	}
	*/
	cout << "\n\n### TESTING DIAMONDTRAP ###\n" << std::endl;
	{
		cout << "\033[34mConstructing\033[0m" << std::endl;
		DiamondTrap a;
		DiamondTrap b("Giga Chadd");
		//DiamondTrap c(a);

		cout << "\033[34mTesting\033[0m" << std::endl;
		a.whoAmI();
		a.attack("some super random dude");
		b.whoAmI();
		b.attack("Chadd-clone");
		//c.whoAmI();
		cout << "\033[34mDeconstructing\033[0m" << std::endl;
	}
	
	return (0);
}
