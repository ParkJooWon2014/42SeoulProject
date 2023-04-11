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

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>

typedef std::string string;

class ICharacter;

class AMateria
{
	public :
		AMateria(void);
		virtual ~AMateria(void);
		AMateria(AMateria const &a);
		virtual AMateria &operator=(AMateria const &a)

	protected:
		string type;

	public:
		AMateria(std::string const & type);
		std::string const & getType() const; 
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif /* ifndef AMATERIA_HPP */
