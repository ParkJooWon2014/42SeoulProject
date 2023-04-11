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

#ifndef ClapTrap_HPP
#define ClapTrap_HPP 

#include <iostream>
#include <string>

#define cout std::cout
#define cin std::cin

typedef std::string string;

class ClapTrap{
	public :
		ClapTrap(void);
		ClapTrap(string name);
		~ClapTrap(void);
		ClapTrap &operator=(ClapTrap const &c);
	
	private:
		string name;
		unsigned int hitPoints;
		unsigned int energyPoints;
		unsigned int attackDamage;
	
	public :
		void attack(const string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif /* ifndef ClapTrap_HPP */
