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

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	private :
		string name;
	public : 
		DiamondTrap(void);
		DiamondTrap(string name);
		DiamondTrap(DiamondTrap const &d);
		~DiamondTrap(void);
		DiamondTrap &operator=(DiamondTrap const &d);

		void attack(const string& target);
		void whoAmI(void);
};


#endif /* ifndef DIAMONDTRAP_HPP */
