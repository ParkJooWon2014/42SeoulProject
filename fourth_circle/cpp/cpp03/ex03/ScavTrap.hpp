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

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class ScavTrap : virtual public ClapTrap
{
	public : 
		ScavTrap(string n);
		ScavTrap(void);
		virtual ~ScavTrap(void);
		ScavTrap(ScavTrap const &c);
		ScavTrap &operator=(ScavTrap const &c);
	public :
		void guardGate(void);
		void attack(const string &target);
};

#endif /* ifndef SCAVTRAP_HPP */
