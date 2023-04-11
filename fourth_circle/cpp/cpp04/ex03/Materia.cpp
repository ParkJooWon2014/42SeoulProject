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

#include "Materia.h"

Ice::Ice(void)
{
	this->type = "ice";
}

Ice::Ice(Ice const &ice)
{
	*this = ice;
}

Ice::~Ice(void){}

Ice &Ice::operator=(Ice const &ice)
{
	this->type = ice.getType();
	return (*this);
}

Ice void::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

Cure::Cure(void)
{
	this->type = "ice";
}

Cure::Cure(Cure const &ice)
{
	*this = ice;
}

Cure::~Cure(void){}

Cure &Cure::operator=(Cure const &cure)
{
	this->type = cure.getType();
	return (*this);
}

Cure void::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "\'s wounds *" << std::endl;
}
