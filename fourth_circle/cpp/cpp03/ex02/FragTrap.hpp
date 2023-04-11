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

#ifndef FRAPTRAP_HPP
#define FRAPTRAP_HPP value

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public : 
		FragTrap(string n);
		FragTrap(void);
		~FragTrap(void);
		FragTrap(FragTrap const &c);
		FragTrap &operator=(FragTrap const &c);
	public :
		void highFivesGuys(void);
		void attack(const string &name);
};

#endif /* ifndef FRAPTRAP_HPP */
