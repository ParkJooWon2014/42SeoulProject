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

#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	this->name = "(no name)";
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	cout << "Frag " << this->name <<" Constructor!" << std::endl;
}

FragTrap::FragTrap(string name)
{
	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	cout << "Frag " << this->name <<" Constructor!" << std::endl;
}

FragTrap::FragTrap(FragTrap const &c)
{
	*this = c;
	cout << "Copy Frag Constructors!" << std::endl;
}

FragTrap::~FragTrap(void)
{
	cout << "Frag "<< this->name << " destructor!" << std::endl;
}
FragTrap &FragTrap::operator=(FragTrap const &c)
{
	this->hitPoints = c.hitPoints;
	this->energyPoints = c.energyPoints;
	this->attackDamage = c.attackDamage;
	this->name = c.name;
	cout << "Frag assign operator " << std::endl;
	return (*this);
}

void FragTrap::attack(const string &target)
{
	cout << "FragTrap " << this->name << " attack " << target << " causing " <<
		this->attackDamage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	cout << this->name << " do highFiveGuys!" << std::endl;
}

