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

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP 

#include "AMateria.hpp"

enum TYPE{
	ICE,
	CURE,
};

class IMateriaSource
{
	public:
		virtual ~IMateriaSource() {}
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};

class MateriaSource : public IMateriaSource
{
	public :
		MateriaSource(void);
		MateriaSource(MateriaSource const &m);
		MateriaSource &operator=(MateriaSource const &m)
		~MateriaSource(void);
	private : 
		IMateria *slot[2];

	public :
		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
};

#endif /* ifndef MATERIASOURCE_HPP */
