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

ScavTrap::ScavTrap(void)
{
	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	cout << "Scav Constructor!" << std::endl;
}

ScavTrap::ScavTrap(string name)
{
	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	cout << "Scav " << this->name <<" Constructor!" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &c)
{
	*this = c;
	cout << "Copy Scav Constructors!" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	cout << "Scav "<< this->name << " destructor!" << std::endl;
}
ScavTrap &ScavTrap::operator=(ScavTrap const &c)
{
	this->hitPoints = c.hitPoints;
	this->energyPoints = c.energyPoints;
	this->attackDamage = c.attackDamage;
	this->name = c.name;
	cout << "Scav assign operator " << std::endl;
	return (*this);
}

void ScavTrap::guardGate(void)
{
	cout << this->name << " do guard Gate" << std::endl;
}

void ScavTrap::attack(const string &target)
{
	cout << "ScavTrap " << this->name << " attack " << target << " causing " <<
		this->attackDamage << " points of damage!" << std::endl;
}
