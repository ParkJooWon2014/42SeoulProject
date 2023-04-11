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

DiamondTrap::DiamondTrap(void) : ClapTrap("(no name)_clap_name"), FragTrap(), ScavTrap()
{
	this->name = "(no name)";
	ClapTrap::name = this->name + "_clap_name";
	this->hitPoints= FragTrap::hitPoints;
	this->attackDamage = FragTrap::attackDamage;
	this->energyPoints = ScavTrap::energyPoints;
	cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(string name): ClapTrap(name + "_clap_name")
{
	this->name = name;
	ClapTrap::name = this->name + "_clap_name";
	this->hitPoints= FragTrap::hitPoints;
	this->attackDamage = FragTrap::attackDamage;
	this->energyPoints = ScavTrap::energyPoints;
	cout << "DiamondTrap " <<this->name << " constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &d) : ClapTrap(d), FragTrap(d), ScavTrap(d)
{
	*this = d;
	cout << "DiamondTrap Copy Constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
	cout << "DiamondTrap " << this->name << " destructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &d)
{
	this->name = d.name;
	this->energyPoints = d.energyPoints;
	this->attackDamage = d.attackDamage;
	this->hitPoints = d.hitPoints;
	return *this;
}

void DiamondTrap::attack(const string &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void)
{
	cout	<< "This DiamondTrap name is " << this->name << " and This ClapTrap name is " << ClapTrap::name << std::endl;
}
