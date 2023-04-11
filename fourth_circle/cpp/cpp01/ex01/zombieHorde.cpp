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

#include "Zombie.hpp"

Zombie* zombieHorde(int N,string name)
{
	if (N <= 0)
		return (NULL);
	Zombie *zombies = new Zombie[N];

	for (int i = 0; i < N; i++) {
		zombies[i].setName(name);
	}
	return zombies;
}
