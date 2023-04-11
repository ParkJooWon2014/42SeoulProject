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


#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string.h>

#define cout std::cout
typedef std::string string;

class Zombie
{
	private :
		string name;
	public :
		void announce(void);
	public :
		Zombie(void);
		Zombie(string name);
		~Zombie();
};

Zombie*	newZombie( std::string name);
void randomChump(std::string);
#endif
