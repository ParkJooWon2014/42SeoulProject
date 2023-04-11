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

#ifndef CHARACTER_HPP
#define CHARACTER_HPP 

#include "ICharacter.h"
#include "Materia.hpp"

class Character : public ICharacter
{
	public :
		Character(void);
		Character(Character const &c);
		~Character(void);
		Character &operator=(Character const &c);

	private :
		string name;
		AMateria *slot[4];

	public :
		string const &getName(void) const;
		void use(int, ICharacter &) const;

};

#endif /* ifndef CHARACTER_HPP */
