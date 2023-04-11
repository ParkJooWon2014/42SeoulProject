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

#ifndef MATERIA_HPP
#define MATERIA_HPP 

#include "AMateria.hpp"


class Ice : public AMateria
{
	public :
		Ice(void);
		Ice(Ice const &ice);
		Ice &operator(Ice const &ice);
		~Ice(void);

	public :
		AMateria *clone();
		void use(ICharacter &target);
};

class Cure : public AMateria
{
	public :
		Cure(void);
		Cure(Ice const &ice);
		Cure&operator(Ice const &ice);
		~Cure(void);

	public :
		AMateria *clone();
		void use(ICharacter &target);
};

#endif /* ifndef MATERIA_HPP */
