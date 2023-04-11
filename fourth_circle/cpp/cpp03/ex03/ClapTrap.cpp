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

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void): name("(no name)"), hitPoints(10), energyPoints(10), attackDamage(0)
{cout <<"Clap " << this->name << " constructors!" << std::endl;}
ClapTrap::ClapTrap(string name): name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{cout <<"Clap " << this->name << " constructors!" << std::endl;}
ClapTrap::ClapTrap(ClapTrap const &c) : name(c.getName()), energyPoints(c.getEnergyPoints()), 
	attackDamage(c.getAttackDamage())
{
	cout << "Copy Constructors!" << std::endl;
}
ClapTrap::~ClapTrap(void){cout<< "Clap "<< this->name << " destructor!" << std::endl;};
ClapTrap &ClapTrap::operator=(ClapTrap const &c)
{
	this->hitPoints = c.hitPoints;
	this->energyPoints = c.energyPoints;
	this->attackDamage = c.attackDamage;
	this->name = c.name;
	return (*this);
}

void ClapTrap::attack(const string &target)
{
	if (this->hitPoints && this->energyPoints){
		cout << "ClapTrap " << this->name << " attacks " << target << ", causing " \
			<< this->attackDamage << " points of damage!" << std::endl;
		this->energyPoints -= 1;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	this->hitPoints = this->hitPoints > amount ? this->hitPoints - amount : 0;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hitPoints && this->energyPoints)
	{
		this->hitPoints += amount;
		this->energyPoints -= 1;
	}
}

string ClapTrap::getName(void) const
{
	return this->name;
}

unsigned int ClapTrap::getHitPoints(void) const
{
	return this->hitPoints;
}

unsigned int ClapTrap::getAttackDamage(void) const
{
	return this->attackDamage;
}

unsigned int ClapTrap::getEnergyPoints(void) const
{
	return this->attackDamage;
}
