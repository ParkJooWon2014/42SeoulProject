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

#include "AMateria.h"

AMateria::AMateria(void): type("") {}
AMateria::AMateria(string const &type) :type(type){}
AMateria::AMateria(AMateria const &m) {*this = m};
AMateria::~AMateria(void) {};
AMateria &AMateria::operator=(AMateria const &m)
{
	this->type = m.getType();
}

string const &AMateria::getType(void) const
{
	return (this->type);
}

AMateria *AMateria::clone(void) const
{
	return new AMateria(*this);
}

void use(ICharacter &target)
{
	std::cout << "Valia Material \'use\' function to " << target.getName() << std::endl;
}
