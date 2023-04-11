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

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("No type") 
{
	std::cout << "WrongAnimal constructor called" << std::endl;
}
WrongAnimal::WrongAnimal(WrongAnimal const &ani) : type(ani.getType())
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}
WrongAnimal::~WrongAnimal(void) 
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &ani)
{
	std::cout << "WrongAnimal copy operator called" << std::endl;
	this->type = ani.getType();
	return *this;
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "No type animal make sound" << std::endl;
}

string WrongAnimal::getType(void) const
{
	return this->type;
}
